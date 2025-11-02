#include "GameEngine.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>

GameEngine::GameEngine() : gameRunning(false), gameWon(false), turnsPlayed(0), finalBossDefeated(false) {}

void GameEngine::startGame() {
    std::cout << "========================================" << std::endl;
    std::cout << "   Echoes of the Forgotten Realm" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\nYou awaken in a ruined world with no memory..." << std::endl;
    std::cout << "Explore, survive, and uncover your forgotten past.\n" << std::endl;
    
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    
    if (playerName.empty()) {
        playerName = "Unknown";
    }
    
    player = std::make_unique<Player>(playerName);
    
    // Initialize the game world
    populateWorld();
    
    // Start in the wrecked village
    currentRoom = rooms["village"];
    currentRoom->setVisited(true);
    
    gameRunning = true;
    
    std::cout << "\nWelcome, " << player->getName() << "!" << std::endl;
    std::cout << "Type 'help' for available commands.\n" << std::endl;
    
    currentRoom->displayRoom();
    
    gameLoop();
}

void GameEngine::gameLoop() {
    std::string input;
    
    while (gameRunning && player->isAlive()) {
        std::cout << "\n> ";
        std::getline(std::cin, input);
        
        if (input.empty()) continue;
        
        auto command = parseCommand(input);
        if (!command.empty()) {
            processCommand(command);
            turnsPlayed++;
            
            // Check for environmental hazards
            checkRoomHazards();
            
            // Check win condition
            checkWinCondition();
        }
    }
    
    if (!player->isAlive()) {
        endGame(false);
    } else if (gameWon) {
        endGame(true);
    }
}

std::vector<std::string> GameEngine::parseCommand(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    
    while (iss >> token) {
        tokens.push_back(toLowerCase(token));
    }
    
    return tokens;
}

void GameEngine::processCommand(const std::vector<std::string>& command) {
    if (command.empty()) return;
    
    const std::string& action = command[0];
    
    if (action == "look" || action == "l") {
        handleLook();
    }
    else if (action == "move" || action == "go" || action == "m") {
        if (command.size() > 1) {
            handleMove(command[1]);
        } else {
            std::cout << "Move where? (north, south, east, west)" << std::endl;
        }
    }
    else if (action == "north" || action == "n") {
        handleMove("north");
    }
    else if (action == "south" || action == "s") {
        handleMove("south");
    }
    else if (action == "east" || action == "e") {
        handleMove("east");
    }
    else if (action == "west" || action == "w") {
        handleMove("west");
    }
    else if (action == "take" || action == "get" || action == "pick") {
        if (command.size() > 1) {
            // Handle multi-word item names
            std::string fullItemName;
            for (size_t i = 1; i < command.size(); ++i) {
                if (i > 1) fullItemName += " ";
                fullItemName += command[i];
            }
            handleTake(fullItemName);
        } else {
            std::cout << "Take what?" << std::endl;
        }
    }
    else if (action == "use") {
        if (command.size() > 1) {
            handleUse(command[1]);
        } else {
            std::cout << "Use what?" << std::endl;
        }
    }
    else if (action == "attack" || action == "fight") {
        if (command.size() > 1) {
            handleAttack(command[1]);
        } else {
            handleAttack("");
        }
    }
    else if (action == "inventory" || action == "i" || action == "inv") {
        handleInventory();
    }
    else if (action == "memory" || action == "journal") {
        handleMemory();
    }
    else if (action == "save") {
        handleSave();
    }
    else if (action == "load") {
        handleLoad();
    }
    else if (action == "help" || action == "h") {
        handleHelp();
    }
    else if (action == "quit" || action == "exit" || action == "q") {
        handleQuit();
    }
    else if (action == "status" || action == "stats") {
        displayGameInfo();
    }
    else {
        std::cout << "I don't understand that command. Type 'help' for available commands." << std::endl;
    }
}

void GameEngine::handleMove(const std::string& direction) {
    if (currentRoom->hasAliveEnemies()) {
        std::cout << "You can't leave while enemies are present! You must fight or find another way." << std::endl;
        return;
    }
    
    std::string nextRoomId = currentRoom->getExit(direction);
    if (nextRoomId.empty()) {
        std::cout << "You can't go that way." << std::endl;
        return;
    }
    
    auto nextRoom = rooms.find(nextRoomId);
    if (nextRoom != rooms.end()) {
        std::cout << "You move " << direction << "..." << std::endl;
        currentRoom = nextRoom->second;
        
        if (!currentRoom->isVisited()) {
            currentRoom->setVisited(true);
        }
        
        // Add random encounters in some rooms (even if visited before)
        if (nextRoomId == "forest" || nextRoomId == "cave") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 100);
            
            if (dis(gen) <= 60) { // 60% chance of encounter
                auto enemy = std::make_shared<Enemy>(Enemy::createRandomEnemy());
                currentRoom->addEnemy(enemy);
                std::cout << "A " << enemy->getName() << " appears!" << std::endl;
            }
        }
        
        currentRoom->displayRoom();
    } else {
        std::cout << "Error: Room not found." << std::endl;
    }
}

void GameEngine::handleLook() {
    currentRoom->lookAround();
}

void GameEngine::handleTake(const std::string& itemName) {
    auto item = currentRoom->takeItem(itemName);
    if (item) {
        player->addItem(item);
        
        // Check for memory triggers
        if (item->getName() == "rusty sword") {
            player->addMemory("You remember wielding this blade in battle against the Shadow Forces...");
        } else if (item->getName() == "ancient key") {
            player->addMemory("This key once opened the doors to your forgotten castle...");
        } else if (item->getName() == "crystal shard") {
            player->addMemory("The crystal resonates with power - a fragment of the Realm's heart...");
        }
        
        // Auto-equip weapons
        if (item->getType() == Item::Type::WEAPON) {
            player->equipWeapon(item);
        }
    } else {
        std::cout << "There's no " << itemName << " here." << std::endl;
    }
}

void GameEngine::handleUse(const std::string& itemName) {
    auto item = player->getItem(itemName);
    if (!item) {
        std::cout << "You don't have a " << itemName << "." << std::endl;
        return;
    }
    
    if (item->getType() == Item::Type::POTION) {
        player->heal(item->getEffect());
        player->removeItem(itemName);
        std::cout << "You used the " << itemName << "." << std::endl;
    }
    else if (item->getType() == Item::Type::KEY) {
        if (currentRoom->getId() == "temple" && itemName == "ancient key") {
            currentRoom->setSpecialEvent("You unlock the hidden chamber! A passage opens to the north.");
            currentRoom->addExit("north", "chamber");
            std::cout << "The ancient key fits perfectly! A hidden passage opens." << std::endl;
        } else {
            std::cout << "The " << itemName << " doesn't work here." << std::endl;
        }
    }
    else {
        std::cout << "You can't use that item." << std::endl;
    }
}

void GameEngine::handleAttack(const std::string& target) {
    auto enemy = currentRoom->getAliveEnemy();
    if (!enemy) {
        std::cout << "There's nothing to attack here." << std::endl;
        return;
    }
    
    handleCombat(enemy);
}

void GameEngine::handleCombat(std::shared_ptr<Enemy> enemy) {
    std::cout << "\n*** COMBAT BEGINS ***" << std::endl;
    enemy->showStatus();
    std::cout << "**********************" << std::endl;
    
    while (enemy->alive() && player->isAlive()) {
        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "1. Attack (or type 'attack')" << std::endl;
        std::cout << "2. Use item (or type 'use')" << std::endl;
        std::cout << "3. Try to flee (or type 'flee')" << std::endl;
        std::cout << "> ";
        
        std::string choice;
        std::getline(std::cin, choice);
        choice = toLowerCase(choice);
        
        if (choice == "1" || choice == "attack" || choice == "a" || choice.find("attack") != std::string::npos) {
            if (playerAttack(enemy)) {
                if (!enemy->alive()) {
                    std::cout << "\nYou defeated the " << enemy->getName() << "!" << std::endl;
                    player->addGold(enemy->getGoldReward());
                    std::cout << "You gained " << enemy->getGoldReward() << " gold." << std::endl;
                    
                    if (enemy->getType() == Enemy::Type::BOSS) {
                        finalBossDefeated = true;
                        player->addMemory("You have defeated the Shadow Lord and restored balance to the realm!");
                    }
                    
                    currentRoom->removeDeadEnemies();
                    break;
                }
                
                if (enemyAttack(enemy)) {
                    if (!player->isAlive()) {
                        std::cout << "\nYou have been defeated..." << std::endl;
                        break;
                    }
                }
            }
        }
        else if (choice == "2" || choice == "use" || choice == "use item") {
            std::cout << "Use which item? ";
            std::string itemName;
            std::getline(std::cin, itemName);
            handleUse(toLowerCase(itemName));
        }
        else if (choice == "3" || choice == "flee" || choice == "try to flee" || choice.find("flee") != std::string::npos) {
            std::cout << "You attempt to flee..." << std::endl;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 100);
            
            if (dis(gen) <= 70) { // 70% success rate
                std::cout << "You successfully escape!" << std::endl;
                break;
            } else {
                std::cout << "You couldn't escape!" << std::endl;
                enemyAttack(enemy);
            }
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
    
    std::cout << "\n*** COMBAT ENDS ***" << std::endl;
}

bool GameEngine::playerAttack(std::shared_ptr<Enemy> enemy) {
    int damage = player->getAttack();
    std::cout << "You attack the " << enemy->getName() << " for " << damage << " damage!" << std::endl;
    enemy->takeDamage(damage);
    return true;
}

bool GameEngine::enemyAttack(std::shared_ptr<Enemy> enemy) {
    int damage = enemy->performAttack();
    player->takeDamage(damage);
    return true;
}

void GameEngine::handleInventory() {
    player->showInventory();
}

void GameEngine::handleMemory() {
    player->showMemoryJournal();
}

void GameEngine::handleSave() {
    std::cout << "Game saved! (Save system would store current state)" << std::endl;
    // In a full implementation, this would save to a file
}

void GameEngine::handleLoad() {
    std::cout << "Game loaded! (Load system would restore saved state)" << std::endl;
    // In a full implementation, this would load from a file
}

void GameEngine::handleHelp() {
    std::cout << "\n=== AVAILABLE COMMANDS ===" << std::endl;
    std::cout << "Movement:" << std::endl;
    std::cout << "  move [direction] / go [direction] / [direction]" << std::endl;
    std::cout << "  north/n, south/s, east/e, west/w" << std::endl;
    std::cout << "\nInteraction:" << std::endl;
    std::cout << "  look/l - Examine your surroundings" << std::endl;
    std::cout << "  take [item] / get [item] - Pick up an item" << std::endl;
    std::cout << "  use [item] - Use an item from inventory" << std::endl;
    std::cout << "  attack [enemy] / fight - Start combat" << std::endl;
    std::cout << "\nInfo:" << std::endl;
    std::cout << "  inventory/i - Show your items" << std::endl;
    std::cout << "  memory/journal - View recovered memories" << std::endl;
    std::cout << "  status - Show your character status" << std::endl;
    std::cout << "\nGame:" << std::endl;
    std::cout << "  save - Save your progress" << std::endl;
    std::cout << "  load - Load saved game" << std::endl;
    std::cout << "  help/h - Show this help" << std::endl;
    std::cout << "  quit/exit/q - Exit the game" << std::endl;
    std::cout << "=========================" << std::endl;
}

void GameEngine::handleQuit() {
    std::cout << "Are you sure you want to quit? (y/n): ";
    std::string response;
    std::getline(std::cin, response);
    
    if (toLowerCase(response) == "y" || toLowerCase(response) == "yes") {
        std::cout << "Thanks for playing Echoes of the Forgotten Realm!" << std::endl;
        gameRunning = false;
    }
}

void GameEngine::checkRoomHazards() {
    auto hazard = currentRoom->getHazard();
    if (hazard != Room::HazardType::NONE) {
        switch (hazard) {
            case Room::HazardType::POISON:
            case Room::HazardType::CURSED:
                player->takeDamage(2);
                break;
            case Room::HazardType::COLD:
            case Room::HazardType::HOT:
                player->takeDamage(1);
                break;
            default:
                break;
        }
    }
}

void GameEngine::checkWinCondition() {
    if (finalBossDefeated && player->hasMemory("You have defeated the Shadow Lord and restored balance to the realm!")) {
        gameWon = true;
        gameRunning = false;
    }
}

void GameEngine::displayGameInfo() {
    std::cout << "\n=== CHARACTER STATUS ===" << std::endl;
    std::cout << "Name: " << player->getName() << std::endl;
    std::cout << "Health: " << player->getHealth() << "/" << player->getMaxHealth() << std::endl;
    std::cout << "Attack: " << player->getAttack() << std::endl;
    std::cout << "Defense: " << player->getDefense() << std::endl;
    std::cout << "Gold: " << player->getGold() << std::endl;
    std::cout << "Current Location: " << currentRoom->getName() << std::endl;
    std::cout << "Turns Played: " << turnsPlayed << std::endl;
    std::cout << "========================" << std::endl;
}

std::string GameEngine::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void GameEngine::endGame(bool won) {
    std::cout << "\n========================================" << std::endl;
    if (won) {
        std::cout << "         CONGRATULATIONS!" << std::endl;
        std::cout << "   You have restored the realm!" << std::endl;
        std::cout << "Your memories have returned, and the" << std::endl;
        std::cout << "Shadow Lord's curse is broken forever." << std::endl;
    } else {
        std::cout << "           GAME OVER" << std::endl;
        std::cout << "   Your journey ends here..." << std::endl;
        std::cout << "The realm remains shrouded in darkness." << std::endl;
    }
    std::cout << "========================================" << std::endl;
    std::cout << "\nFinal Stats:" << std::endl;
    std::cout << "Turns played: " << turnsPlayed << std::endl;
    std::cout << "Memories recovered: " << (player ? player->hasMemory("You have defeated the Shadow Lord and restored balance to the realm!") : false) << std::endl;
    std::cout << "\nThank you for playing Echoes of the Forgotten Realm!" << std::endl;
}

void GameEngine::populateWorld() {
    // Create rooms
    auto village = std::make_shared<Room>("village", "Wrecked Village", 
        "You stand in the ruins of what was once a thriving village. Collapsed houses and broken carts litter the area. A sense of ancient tragedy hangs in the air.");
    
    auto forest = std::make_shared<Room>("forest", "Misty Forest", 
        "Dense fog swirls between ancient trees. The forest feels alive with whispers of the past. Strange shadows dance between the branches.");
    
    auto temple = std::make_shared<Room>("temple", "Abandoned Temple", 
        "Crumbling stone pillars support a partially collapsed roof. Ancient runes glow faintly on the walls, hinting at forgotten power.");
    
    auto cave = std::make_shared<Room>("cave", "Underground Cave", 
        "Dark tunnels stretch into the depths. Water drips steadily from stalactites, echoing in the darkness. The air is cold and damp.");
    
    auto keep = std::make_shared<Room>("keep", "Ruined Keep", 
        "The once-mighty fortress now lies in ruins. A throne room opens before you, where shadows seem to gather with unnatural purpose.");
    
    auto chamber = std::make_shared<Room>("chamber", "Hidden Chamber", 
        "A secret chamber revealed by the ancient key. Mystical energy fills the air, and a portal of swirling darkness dominates the center.");
    
    // Set up connections
    village->addExit("north", "forest");
    village->addExit("east", "temple");
    
    forest->addExit("south", "village");
    forest->addExit("north", "cave");
    forest->addExit("east", "keep");
    
    temple->addExit("west", "village");
    temple->addExit("north", "keep");
    
    cave->addExit("south", "forest");
    cave->addExit("east", "keep");
    
    keep->addExit("west", "forest");
    keep->addExit("south", "temple");
    
    chamber->addExit("south", "temple");
    
    // Add environmental hazards
    cave->setHazard(Room::HazardType::COLD);
    chamber->setHazard(Room::HazardType::CURSED);
    
    // Add items
    village->addItem(std::make_shared<Item>("rusty sword", "An old but serviceable blade", Item::Type::WEAPON, 10, 5));
    village->addItem(std::make_shared<Item>("health potion", "A small vial of red liquid", Item::Type::POTION, 25, 20));
    
    forest->addItem(std::make_shared<Item>("iron dagger", "A sharp, well-balanced dagger", Item::Type::WEAPON, 20, 3));
    
    temple->addItem(std::make_shared<Item>("ancient key", "An ornate key humming with power", Item::Type::KEY, 0, 0));
    temple->addItem(std::make_shared<Item>("crystal shard", "A glowing fragment of pure energy", Item::Type::QUEST_ITEM, 100, 0));
    
    cave->addItem(std::make_shared<Item>("steel sword", "A finely crafted blade", Item::Type::WEAPON, 50, 8));
    cave->addItem(std::make_shared<Item>("health potion", "A small vial of red liquid", Item::Type::POTION, 25, 20));
    
    chamber->addItem(std::make_shared<Item>("legendary blade", "The weapon of a forgotten hero", Item::Type::WEAPON, 200, 15));
    
    // Add enemies
    keep->addEnemy(std::make_shared<Enemy>(Enemy::createBoss()));
    
    // Store rooms
    rooms["village"] = village;
    rooms["forest"] = forest;
    rooms["temple"] = temple;
    rooms["cave"] = cave;
    rooms["keep"] = keep;
    rooms["chamber"] = chamber;
}
