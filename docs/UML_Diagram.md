# UML Class Diagram - Echoes of the Forgotten Realm

## Class Relationships

```
    ┌─────────────┐         ┌─────────────┐
    │   Player    │◇────────│    Item     │
    └─────────────┘         └─────────────┘
           │                        │
           │                        │
           │ uses                   │ contains
           │                        │
           ▼                        ▼
    ┌─────────────┐         ┌─────────────┐
    │ GameEngine  │◇────────│    Room     │
    └─────────────┘         └─────────────┘
           │                        │
           │ manages                │ contains
           │                        │
           ▼                        ▼
    ┌─────────────┐         ┌─────────────┐
    │   Enemy     │◇────────│    Item     │
    └─────────────┘         └─────────────┘
```

## Class Descriptions

### Player Class
- **Attributes:**
  - `name: string` - Player's chosen name
  - `health, maxHealth: int` - Current and maximum health points
  - `attack, defense: int` - Combat statistics
  - `gold: int` - Currency for transactions
  - `inventory: vector<shared_ptr<Item>>` - Items carried
  - `equippedWeapon: shared_ptr<Item>` - Currently equipped weapon
  - `memoryJournal: vector<string>` - Story progression tracker

- **Methods:**
  - `heal(amount)` - Restore health points
  - `takeDamage(damage)` - Reduce health after defense calculation
  - `addItem(item)` - Add item to inventory
  - `equipWeapon(weapon)` - Equip weapon for combat bonus
  - `addMemory(memory)` - Add story element to journal

### Item Class
- **Attributes:**
  - `name, description: string` - Item identification
  - `type: enum Type` - WEAPON, POTION, KEY, TREASURE, QUEST_ITEM
  - `value, effect: int` - Worth and mechanical effect

- **Methods:**
  - `getTypeString()` - Human-readable type name
  - `isUsable()` - Check if item can be consumed/used

### Enemy Class
- **Attributes:**
  - `name: string` - Enemy identifier
  - `type: enum Type` - GOBLIN, WOLF, SKELETON, GHOST, BOSS
  - `health, attack, defense: int` - Combat statistics
  - `goldReward: int` - Gold dropped when defeated

- **Methods:**
  - `performAttack()` - Execute attack with random variation
  - `takeDamage(damage)` - Process incoming damage
  - `createRandomEnemy()` - Factory method for encounters
  - `createBoss()` - Factory method for final boss

### Room Class
- **Attributes:**
  - `id, name, description: string` - Room identification
  - `exits: map<string, string>` - Directional connections
  - `items: vector<shared_ptr<Item>>` - Items present in room
  - `enemies: vector<shared_ptr<Enemy>>` - Enemies in room
  - `hazard: enum HazardType` - Environmental dangers
  - `visited: bool` - Track exploration progress

- **Methods:**
  - `addExit(direction, roomId)` - Connect to another room
  - `takeItem(itemName)` - Remove and return item
  - `addEnemy(enemy)` - Place enemy in room
  - `displayRoom()` - Show room description and contents

### GameEngine Class
- **Attributes:**
  - `player: unique_ptr<Player>` - Main character
  - `rooms: map<string, shared_ptr<Room>>` - Game world
  - `currentRoom: shared_ptr<Room>` - Player's location
  - `gameRunning, gameWon: bool` - Game state flags

- **Methods:**
  - `startGame()` - Initialize game world and player
  - `gameLoop()` - Main input/processing cycle
  - `processCommand(command)` - Parse and execute player actions
  - `handleCombat(enemy)` - Manage turn-based fighting
  - `checkWinCondition()` - Evaluate victory conditions

## Design Patterns Used

1. **Factory Pattern**: Enemy creation through static factory methods
2. **Composition**: GameEngine contains Player, Rooms contain Items/Enemies
3. **State Pattern**: Game states (running, won, combat mode)
4. **Command Pattern**: Text commands parsed into method calls
5. **Observer Pattern**: Memory system triggers based on item interactions

## Memory Management
- Smart pointers (`shared_ptr`, `unique_ptr`) used throughout
- RAII principles for automatic resource cleanup
- No raw pointer usage to prevent memory leaks
