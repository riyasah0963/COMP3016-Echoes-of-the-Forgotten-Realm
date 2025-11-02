# Visual UML Diagram for Video

## Class Relationship Diagram

```
┌─────────────────────────────────────────────────────────────────┐
│                          GAME ARCHITECTURE                       │
└─────────────────────────────────────────────────────────────────┘

           ┌─────────────────┐
           │   GameEngine    │ ◄── Main Controller
           │ ─────────────── │
           │ - player        │
           │ - rooms         │
           │ - currentRoom   │
           │ - gameRunning   │
           │ ─────────────── │
           │ + startGame()   │
           │ + gameLoop()    │
           │ + processCmd()  │
           └─────────────────┘
                    │
                    │ manages
                    ▼
    ┌─────────────────────────────────────────┐
    │                                         │
    ▼                                         ▼
┌─────────────┐                    ┌─────────────┐
│   Player    │                    │    Room     │
│ ─────────── │                    │ ─────────── │
│ - name      │                    │ - id        │
│ - health    │                    │ - name      │
│ - inventory │ ◆────────┐         │ - items     │ ◆─────┐
│ - memories  │          │         │ - enemies   │       │
│ ─────────── │          │         │ - exits     │       │
│ + addItem() │          │         │ ─────────── │       │
│ + addMemory()│         │         │ + addItem() │       │
│ + attack()  │          │         │ + addEnemy()│       │
└─────────────┘          │         └─────────────┘       │
                         │                               │
                         │                               │
                    ┌────▼─────┐                   ┌────▼─────┐
                    │   Item   │                   │  Enemy   │
                    │ ──────── │                   │ ──────── │
                    │ - name   │                   │ - name   │
                    │ - type   │                   │ - health │
                    │ - effect │                   │ - attack │
                    │ ──────── │                   │ ──────── │
                    │ + use()  │                   │ + fight()│
                    └──────────┘                   └──────────┘
                         │                               │
                         │                               │
                    ┌────┴─────┐                   ┌────┴─────┐
                    │   Types  │                   │   Types  │
                    │ ──────── │                   │ ──────── │
                    │ WEAPON   │                   │ GOBLIN   │
                    │ POTION   │                   │ WOLF     │
                    │ KEY      │                   │ SKELETON │
                    │ TREASURE │                   │ GHOST    │
                    │          │                   │ BOSS     │
                    └──────────┘                   └──────────┘

RELATIONSHIPS:
◆ = Composition (has-a)
◄ = Association (uses)
▼ = Dependency (creates/manages)

DESIGN PATTERNS:
• Factory Pattern: Enemy::createRandomEnemy()
• Composition: GameEngine contains Player and Rooms
• State Pattern: Game states (running, combat, victory)
• Command Pattern: Text input → method calls
```

## Memory Management
```
Smart Pointer Usage:
┌─────────────────────┐
│ unique_ptr<Player>  │ ◄── Single ownership
└─────────────────────┘

┌─────────────────────┐
│ shared_ptr<Room>    │ ◄── Shared between containers
└─────────────────────┘

┌─────────────────────┐
│ shared_ptr<Item>    │ ◄── Can be in room OR inventory
└─────────────────────┘

┌─────────────────────┐
│ shared_ptr<Enemy>   │ ◄── Shared between room and combat
└─────────────────────┘
```

## Key OOP Principles Demonstrated

### 1. Encapsulation
- Private member variables in all classes
- Public interface methods only
- Data validation in setters

### 2. Inheritance  
- Item types inherit common interface
- Enemy types share base behavior
- Virtual methods for polymorphism

### 3. Polymorphism
- Factory methods return base type
- Runtime type determination
- Strategy pattern in combat

### 4. Composition
- GameEngine HAS-A Player
- Room HAS-MANY Items and Enemies  
- Player HAS-MANY Items in inventory

## File Architecture
```
┌─────────────┐    loads    ┌─────────────┐
│ GameEngine  │ ─────────► │ Room Data   │
└─────────────┘            └─────────────┘
                                  │
                                  ▼
                           ┌─────────────┐
                           │ Item Data   │
                           └─────────────┘
                                  │  
                                  ▼
                           ┌─────────────┐
                           │ Enemy Data  │
                           └─────────────┘
```
