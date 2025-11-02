#pragma once
#include "Player.h"
#include "Room.h"
#include "Enemy.h"
#include "Item.h"
#include <map>
#include <string>
#include <memory>

class GameEngine {
private:
    std::unique_ptr<Player> player;
    std::map<std::string, std::shared_ptr<Room>> rooms;
    std::shared_ptr<Room> currentRoom;
    bool gameRunning;
    bool gameWon;
    
    // Game state
    int turnsPlayed;
    bool finalBossDefeated;
    
    // File handling
    void loadRooms();
    void loadItems();
    void populateWorld();
    
    // Combat system
    void handleCombat(std::shared_ptr<Enemy> enemy);
    bool playerAttack(std::shared_ptr<Enemy> enemy);
    bool enemyAttack(std::shared_ptr<Enemy> enemy);
    
    // Input processing
    std::vector<std::string> parseCommand(const std::string& input);
    void processCommand(const std::vector<std::string>& command);
    
    // Command handlers
    void handleMove(const std::string& direction);
    void handleLook();
    void handleTake(const std::string& itemName);
    void handleUse(const std::string& itemName);
    void handleAttack(const std::string& target);
    void handleInventory();
    void handleMemory();
    void handleSave();
    void handleLoad();
    void handleHelp();
    void handleQuit();
    
    // Game logic
    void checkRoomHazards();
    void checkWinCondition();
    void displayGameInfo();
    std::string toLowerCase(const std::string& str);
    
public:
    GameEngine();
    ~GameEngine() = default;
    
    void startGame();
    void gameLoop();
    void endGame(bool won);
    
    // Utility
    bool isGameRunning() const { return gameRunning; }
};
