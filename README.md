# Echoes of the Forgotten Realm

## Overview
A text-based fantasy adventure game written in modern C++ demonstrating object-oriented programming, file handling, and robust gameplay mechanics.

## Setup & Installation
1. Ensure you have a C++ compiler (g++, MinGW, or similar)
2. Clone/download this repository
3. Compile the project:
   ```bash
   g++ -std=c++17 -o game src/*.cpp
   ```
4. Run the executable:
   ```bash
   ./game
   ```

## Game Description
You awaken in a ruined realm with no memory. Explore mysterious areas, collect items, fight enemies, and uncover your forgotten past. Your choices will determine the fate of the realm.

## Features
- **Object-Oriented Design**: Clean C++ classes for Player, Enemy, Item, Room, and GameEngine
- **File Loading**: Game world loaded from external text files for easy modification
- **Turn-based Combat**: Strategic combat with health, attack, and defense stats
- **Multiple Endings**: Story branches based on player choices
- **Save/Load System**: Resume your adventure anytime
- **Memory Journal**: Track discovered clues that influence the story
- **Environmental Hazards**: Rooms with special effects that impact gameplay

## How to Play
Use simple commands to interact with the game:
- `look` - Examine your surroundings
- `move [direction]` - Travel to different areas (north, south, east, west)
- `take [item]` - Pick up items
- `inventory` - Check your items
- `use [item]` - Use potions or items
- `attack [enemy]` - Fight enemies
- `save` - Save your progress
- `load` - Load saved game
- `help` - Show all commands
- `quit` - Exit the game

## Game World
- **Wrecked Village**: Starting area with basic items
- **Misty Forest**: Random encounters and hidden paths
- **Abandoned Temple**: Puzzles and ancient secrets
- **Underground Cave**: Resource gathering and dangers
- **Ruined Keep**: Final area with boss encounters

## Technical Details
- Language: Modern C++17
- Architecture: Object-oriented with clean separation of concerns
- Data Storage: External text files for game content
- Error Handling: Robust input validation and exception handling
- Testing: Comprehensive test cases included

## File Structure
```
src/
├── main.cpp          # Entry point
├── GameEngine.h/.cpp # Main game loop and logic
├── Player.h/.cpp     # Player class with stats and inventory
├── Enemy.h/.cpp      # Enemy class with AI behavior
├── Item.h/.cpp       # Item system for weapons, potions, etc.
├── Room.h/.cpp       # Room/area system
└── FileManager.h/.cpp# File loading utilities

data/
├── rooms.txt         # Room definitions and connections
├── items.txt         # Item database
├── enemies.txt       # Enemy stats and behaviors
└── dialogues.txt     # Story text and conversations

docs/
├── UML_Diagram.md    # Class design diagrams
├── Test_Cases.md     # Testing documentation
└── Design_Patterns.md# Game programming patterns used
```

## Complete command for Terminal
1. Game Introduction
./echoes_game
DemoPlayer
help

2. Basic Mechanics  
look
take rusty sword
inventory
status
memory

3. Exploration
move north
look
move east
look
take ancient key
memory

4. Key Usage & Progression
use ancient key
move north
look
take legendary blade
inventory

5. Combat Demo
move south
move west
move north
attack
1
1

6. Error Handling
invalidcommand
move nowhere
take nothing

7. Final Status
memory
inventory
status
quit
y


## Demo Video
YouTube Link - 

## Author
Riya Shah - COMP3016 Assignment A

## License
Educational Project - University of Plymouth
