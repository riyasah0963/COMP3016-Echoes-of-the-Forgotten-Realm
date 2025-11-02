# Echoes of the Forgotten Realm

## Overview
A text-based fantasy adventure game written in modern C++ demonstrating object-oriented programming, file handling, and robust gameplay mechanics for COMP3016 - Immersive Game Technologies.

## Setup & Installation
1. Ensure you have a C++ compiler supporting C++17 (g++, MinGW, or similar)
2. Clone/download this repository
3. Compile the project:
   ```bash
   # Linux/macOS/WSL
   make
   # OR manually:
   g++ -std=c++17 -o echoes_game src/*.cpp
   
   # Windows (MinGW)
   g++ -std=c++17 -o echoes_game.exe src/*.cpp
   ```
4. Run the executable:
   ```bash
   # Linux/macOS/WSL
   ./echoes_game
   
   # Windows
   echoes_game.exe
   ```

## Game Description
You awaken in a ruined realm with no memory of your past. Explore mysterious areas, collect ancient artifacts, fight supernatural enemies, and piece together your forgotten identity. Your choices will determine not only your fate, but the fate of the entire realm.

## Key Features
- **Modern C++ Design**: Clean OOP architecture with classes for Player, Enemy, Item, Room, and GameEngine
- **Design Patterns**: Factory, Observer, Strategy, Command, and Composition patterns implemented
- **Memory Management**: RAII principles with smart pointers for automatic resource cleanup
- **File Architecture**: Extensible system supporting external data files for easy content modification
- **Turn-based Combat**: Strategic combat system with health, attack, and defense calculations
- **Narrative System**: Dynamic memory journal that triggers story progression
- **Multiple Endings**: Story branches based on player exploration and choices
- **Error Handling**: Comprehensive input validation and exception safety
- **Cross-platform**: Compiles and runs on Windows, Linux, and macOS

## How to Play
Use intuitive text commands to interact with the game world:

### **Movement & Exploration:**
- `look` / `l` - Examine your current surroundings
- `move [direction]` / `go [direction]` - Travel between areas
- `north` / `n`, `south` / `s`, `east` / `e`, `west` / `w` - Quick movement

### **Item Interaction:**
- `take [item]` / `get [item]` - Pick up items from the environment
- `inventory` / `i` - View your items and equipped gear
- `use [item]` - Consume potions or use special items
- `status` - Check your health, attack, and defense stats

### **Combat & Story:**
- `attack` / `fight` - Engage enemies in turn-based combat
- `memory` / `journal` - View recovered memories and story progress
- `help` / `h` - Display all available commands

### **Game Management:**
- `save` - Save your current progress
- `load` - Load previously saved game
- `quit` / `exit` / `q` - Exit the game

## Game World & Areas
- **Wrecked Village**: Your starting point - gather basic equipment and learn the controls
- **Misty Forest**: Encounter supernatural enemies and discover hidden paths
- **Ancient Temple**: Solve puzzles and uncover ancient secrets with special keys  
- **Underground Cave**: Navigate dangerous tunnels while gathering rare resources
- **Hidden Chamber**: Unlock with the ancient key to find legendary equipment
- **Ruined Keep**: Face the final challenges and discover the truth about your past

## Technical Implementation

### **Architecture:**
- **Language**: Modern C++17 with STL containers and smart pointers
- **Design**: Object-oriented with clean separation of concerns
- **Patterns**: Factory, Observer, Strategy, Command, Composition, and RAII
- **Memory**: Automatic resource management with unique_ptr and shared_ptr
- **Error Handling**: Exception safety and comprehensive input validation

### **File Structure:**
```
├── src/                    # Source code files
│   ├── main.cpp           # Application entry point
│   ├── GameEngine.h/.cpp  # Main game loop and command processing
│   ├── Player.h/.cpp      # Player character with stats and inventory
│   ├── Enemy.h/.cpp       # Enemy AI and combat mechanics
│   ├── Item.h/.cpp        # Item system (weapons, potions, keys)
│   └── Room.h/.cpp        # Game world areas and navigation
├── docs/                   # Documentation
│   ├── UML_Diagram.md     # Class design and relationships
│   ├── Test_Cases.md      # Testing strategy and validation
│   └── Design_Patterns.md # Software architecture patterns
├── data/                   # Game content (extensible architecture)
│   └── README.md          # Data file format specifications
├── Makefile               # Build automation
└── echoes_game            # Compiled executable
```

## Complete Gameplay Sequence

### **1. Game Introduction & Setup**
```bash
./echoes_game
[Enter name: DemoPlayer]
help
```

### **2. Basic Mechanics & Item System**
```bash
look
take rusty sword
inventory
status
memory
```

### **3. World Exploration**
```bash
move north
look
move east
look
take ancient key
memory
```

### **4. Key Usage & Progression**
```bash
use ancient key
move north
look
take legendary blade
inventory
```

### **5. Combat Demonstration**
```bash
move south
move west
move north
attack
1
1
```

### **6. Error Handling Validation**
```bash
invalidcommand
move nowhere
take nothing
```

### **7. Final Status & Completion**
```bash
memory
inventory
status
quit
y
```

## Testing & Quality Assurance
- **Unit Testing**: Individual class validation
- **Integration Testing**: Component interaction verification  
- **Edge Case Handling**: Invalid input and boundary condition testing
- **Memory Safety**: Smart pointer usage eliminates memory leaks
- **Cross-platform**: Tested on Windows, Linux, and macOS environments

## UML Design
See `docs/UML_Diagram.md` for complete class relationships and architecture overview.

## Demo Video
[YouTube Link - (To be added before submission)]

## Assignment Information
- **Module**: COMP3016 - Immersive Game Technologies
- **Assignment**: CW1 - Text-Based Game (30%)
- **Student**: Riya Shah
- **Submission Date**: November 4, 2025

## Academic Requirements Met
- ✅ Modern C++ with object-oriented programming
- ✅ File handling architecture (data loading system)
- ✅ Robust error handling and input validation
- ✅ Comprehensive documentation and UML diagrams
- ✅ Professional code structure and design patterns
- ✅ Working executable with all features demonstrated

## License
Educational Project - University of Plymouth - COMP3016 Module
