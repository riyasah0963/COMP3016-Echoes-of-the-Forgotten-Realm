# Design Patterns - Echoes of the Forgotten Realm

## Overview
This document details the software design patterns implemented in the game, explaining how they contribute to maintainable, extensible, and robust code architecture.

## 1. Factory Pattern

### Implementation: Enemy Creation
The Enemy class uses the Factory pattern to create different types of enemies with appropriate stats.

```cpp
// Factory methods in Enemy class
static Enemy createRandomEnemy();
static Enemy createBoss();
```

### Benefits:
- **Encapsulation**: Enemy creation logic is centralized
- **Extensibility**: Easy to add new enemy types
- **Consistency**: Ensures enemies have balanced stats
- **Randomization**: Supports varied gameplay encounters

### Usage:
```cpp
auto randomEnemy = std::make_shared<Enemy>(Enemy::createRandomEnemy());
auto boss = std::make_shared<Enemy>(Enemy::createBoss());
```

## 2. Composition Pattern

### Implementation: Game Object Relationships
Objects contain other objects rather than inheriting from them, promoting flexible design.

#### GameEngine contains:
- `unique_ptr<Player>` - Single player instance
- `map<string, shared_ptr<Room>>` - World rooms
- `shared_ptr<Room> currentRoom` - Player location

#### Room contains:
- `vector<shared_ptr<Item>>` - Items in the room
- `vector<shared_ptr<Enemy>>` - Enemies present

#### Player contains:
- `vector<shared_ptr<Item>>` - Inventory items
- `shared_ptr<Item> equippedWeapon` - Current weapon

### Benefits:
- **Flexibility**: Objects can be composed dynamically
- **Reusability**: Components can be shared between objects
- **Loose Coupling**: Changes to one component don't affect others

## 3. State Pattern

### Implementation: Game State Management
The game maintains different states and behaves differently based on current state.

```cpp
class GameEngine {
private:
    bool gameRunning;
    bool gameWon;
    bool finalBossDefeated;
    // State affects behavior of processCommand()
};
```

### States:
1. **Exploration State**: Normal room navigation and interaction
2. **Combat State**: Turn-based fighting with enemies
3. **Victory State**: Game completed successfully
4. **Game Over State**: Player defeated

### Benefits:
- **Clear Behavior**: Each state has defined valid actions
- **Maintainability**: Easy to add new game states
- **Bug Prevention**: Invalid state transitions prevented

## 4. Command Pattern

### Implementation: Text Command Processing
Player input is parsed into command objects that encapsulate actions.

```cpp
void GameEngine::processCommand(const std::vector<std::string>& command) {
    const std::string& action = command[0];
    
    if (action == "move") handleMove(command[1]);
    else if (action == "take") handleTake(command[1]);
    // ... other commands
}
```

### Command Types:
- **Movement Commands**: move, north, south, east, west
- **Interaction Commands**: take, use, attack
- **Information Commands**: look, inventory, memory
- **System Commands**: save, load, help, quit

### Benefits:
- **Extensibility**: Easy to add new commands
- **Separation**: Input parsing separated from action execution
- **Consistency**: Uniform command handling interface

## 5. Observer Pattern

### Implementation: Memory System
The memory journal system observes item interactions and triggers story events.

```cpp
void GameEngine::handleTake(const std::string& itemName) {
    auto item = currentRoom->takeItem(itemName);
    if (item) {
        player->addItem(item);
        
        // Observer pattern - memory triggers
        if (item->getName() == "rusty sword") {
            player->addMemory("You remember wielding this blade...");
        }
    }
}
```

### Benefits:
- **Decoupling**: Story events separated from item mechanics
- **Dynamic**: Memories can trigger based on various conditions
- **Extensible**: Easy to add new memory triggers

## 6. Strategy Pattern

### Implementation: Combat System
Different combat strategies based on player choices and enemy types.

```cpp
void GameEngine::handleCombat(std::shared_ptr<Enemy> enemy) {
    while (enemy->alive() && player->isAlive()) {
        // Strategy selection based on player input
        if (choice == "attack") {
            playerAttack(enemy);
        } else if (choice == "use") {
            handleUse(itemName);
        } else if (choice == "flee") {
            // Flee strategy with success probability
        }
    }
}
```

### Strategies:
- **Attack Strategy**: Direct damage dealing
- **Item Use Strategy**: Healing or buff application
- **Flee Strategy**: Escape with probability calculation

## 7. Singleton Pattern (Avoided)

### Decision: No Singleton Usage
While GameEngine could be a singleton, we chose not to implement it as such.

### Reasons:
- **Testing**: Easier to test with multiple instances
- **Flexibility**: Allows for multiple game sessions
- **Memory**: Clear object lifetime management

### Alternative: Single Instance Management
```cpp
int main() {
    GameEngine game; // Single instance created in main
    game.startGame();
}
```

## 8. RAII (Resource Acquisition Is Initialization)

### Implementation: Smart Pointer Usage
All dynamic resources managed through smart pointers.

```cpp
std::unique_ptr<Player> player;                    // Exclusive ownership
std::shared_ptr<Room> currentRoom;                 // Shared ownership
std::vector<std::shared_ptr<Item>> inventory;      // Shared resources
```

### Benefits:
- **Automatic Cleanup**: No manual memory management
- **Exception Safety**: Resources freed even if exceptions occur
- **Clear Ownership**: Ownership semantics explicit in code

## 9. Template Pattern (Implicit)

### Implementation: Virtual Method Framework
Room and combat interactions follow template method pattern.

```cpp
void Room::displayRoom() const {
    // Template method with defined steps:
    showDescription();    // Step 1
    showHazards();        // Step 2
    listItems();          // Step 3
    listEnemies();        // Step 4
    showExits();          // Step 5
}
```

## 10. Builder Pattern Considerations

### Potential Use: Room Construction
Complex rooms could benefit from builder pattern:

```cpp
// Potential future enhancement
Room complexRoom = RoomBuilder("chamber")
    .setDescription("Ancient chamber...")
    .addHazard(HazardType::CURSED)
    .addItem(legendaryWeapon)
    .addEnemy(guardianSpirit)
    .addExit("north", "treasure_room")
    .build();
```

## Design Principles Applied

### 1. Single Responsibility Principle
- Each class has one reason to change
- Player handles character data, Room handles location data

### 2. Open/Closed Principle
- Classes open for extension, closed for modification
- New enemy types can be added without changing existing code

### 3. Liskov Substitution Principle
- Derived classes can replace base classes
- All Item types can be used interchangeably

### 4. Interface Segregation Principle
- Interfaces are focused and minimal
- Classes only depend on methods they use

### 5. Dependency Inversion Principle
- High-level modules don't depend on low-level modules
- GameEngine works with abstractions, not concrete implementations

## Pattern Benefits Summary

1. **Maintainability**: Clear separation of concerns
2. **Extensibility**: Easy to add new features
3. **Testability**: Components can be tested in isolation
4. **Reusability**: Components can be used in different contexts
5. **Reliability**: Established patterns reduce bugs
6. **Performance**: Smart pointers manage memory efficiently

## Future Pattern Opportunities

1. **Visitor Pattern**: For item interaction effects
2. **Decorator Pattern**: For temporary item enchantments
3. **Prototype Pattern**: For cloning configured rooms
4. **Mediator Pattern**: For complex object interactions
