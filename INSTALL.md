# Installation and Setup Guide

## System Requirements

### Minimum Requirements
- **Operating System**: Linux, macOS, or Windows with WSL
- **Compiler**: G++ with C++17 support (GCC 7.0+ or equivalent)
- **Memory**: 50MB RAM
- **Storage**: 10MB disk space

### Recommended
- **Compiler**: G++ 9.0 or newer
- **Terminal**: Any modern terminal with UTF-8 support

## Installation Steps

### 1. Download/Clone the Project
```bash
# If you have the project files
cd "Echoes of the Forgotten Realm"

# Or if cloning from repository
git clone [repository-url]
cd "Echoes of the Forgotten Realm"
```

### 2. Verify Dependencies
```bash
# Check if g++ is installed
g++ --version

# Should show C++17 support
# If not installed on Ubuntu/Debian:
sudo apt update
sudo apt install build-essential

# On macOS (with Homebrew):
brew install gcc

# On other systems, install appropriate C++ compiler
```

### 3. Compile the Game
```bash
# Using the provided Makefile (recommended)
make

# Or compile manually
g++ -std=c++17 -Wall -Wextra -O2 src/*.cpp -o echoes_game

# For debug version with more verbose output
make debug
```

### 4. Verify Installation
```bash
# Check if executable was created
ls -la echoes_game

# Test that the game starts
echo -e "TestPlayer\nquit\ny" | ./echoes_game
```

## Running the Game

### Standard Launch
```bash
./echoes_game
```

### Demo Mode
```bash
# Run the demo script to see key features
./demo.sh
```

### Custom Compilation Options

#### Debug Version
```bash
make debug
# Creates version with debugging symbols and verbose output
```

#### Release Version
```bash
make release  
# Optimized version for best performance
```

#### Clean Build
```bash
make clean    # Remove compiled files
make          # Rebuild from scratch
```

## Troubleshooting

### Common Issues

#### 1. Compilation Errors
**Problem**: "error: 'std::shared_ptr' was not declared"
**Solution**: Ensure C++17 support:
```bash
g++ -std=c++17 src/*.cpp -o echoes_game
```

#### 2. Permission Denied
**Problem**: "./echoes_game: Permission denied"
**Solution**: Make executable:
```bash
chmod +x echoes_game
```

#### 3. Missing Compiler
**Problem**: "g++: command not found"
**Solution**: Install build tools:
```bash
# Ubuntu/Debian
sudo apt install build-essential

# CentOS/RHEL
sudo yum groupinstall "Development Tools"

# macOS
xcode-select --install
```

#### 4. Linking Errors
**Problem**: Undefined reference errors
**Solution**: Ensure all source files are compiled:
```bash
g++ -std=c++17 src/main.cpp src/GameEngine.cpp src/Player.cpp src/Enemy.cpp src/Item.cpp src/Room.cpp -o echoes_game
```

### Performance Issues

#### Memory Usage
- Game uses approximately 10-50MB RAM
- Smart pointers manage memory automatically
- No known memory leaks in normal gameplay

#### CPU Usage
- Minimal CPU usage during normal gameplay
- Slight increase during random number generation for combat

## Game Controls

### Basic Commands
- `help` - Show all available commands
- `look` - Examine current room
- `move [direction]` - Travel (north, south, east, west)
- `take [item]` - Pick up items
- `inventory` - Show your items
- `attack` - Fight enemies
- `use [item]` - Use potions or keys
- `memory` - View story journal
- `save/load` - Game progress (planned feature)
- `quit` - Exit game

### Tips for New Players
1. Start with `help` to see all commands
2. Use `look` to examine each new room
3. Pick up items as you find them - they're usually useful
4. Check your `inventory` regularly
5. Use the `memory` command to track story progress
6. Combat is turn-based - take your time to think

## File Structure

```
Echoes of the Forgotten Realm/
├── src/                    # Source code files
│   ├── main.cpp           # Program entry point
│   ├── GameEngine.h/.cpp  # Main game logic
│   ├── Player.h/.cpp      # Player character system
│   ├── Enemy.h/.cpp       # Enemy and combat system
│   ├── Item.h/.cpp        # Item and inventory system
│   └── Room.h/.cpp        # World and navigation system
├── docs/                  # Documentation
│   ├── UML_Diagram.md     # Class structure diagrams
│   ├── Test_Cases.md      # Testing strategy and cases
│   └── Design_Patterns.md # Software architecture details
├── data/                  # Game data files (future expansion)
├── Makefile              # Build configuration
├── README.md             # Main project documentation
├── demo.sh               # Demo script
└── echoes_game           # Compiled executable
```

## Development Setup

### For Developers
If you want to modify or extend the game:

```bash
# Clone the project
git clone [repository-url]
cd "Echoes of the Forgotten Realm"

# Create development build
make debug

# Run tests (when implemented)
make test

# Make changes to source files in src/
# Recompile after changes
make clean && make
```

### Code Style Guidelines
- Use C++17 features where appropriate
- Smart pointers for memory management
- Consistent naming: camelCase for methods, PascalCase for classes
- Header guards in all .h files
- Comprehensive comments for public methods

## Uninstallation

```bash
# Remove compiled executable
make clean

# Remove entire project directory
cd ..
rm -rf "Echoes of the Forgotten Realm"
```

## Support

### Getting Help
1. Check this installation guide
2. Review the documentation in `docs/`
3. Run `./echoes_game` and use the `help` command
4. Check the demo script: `./demo.sh`

### Reporting Issues
When reporting problems, please include:
- Operating system and version
- G++ version (`g++ --version`)
- Exact error message
- Steps to reproduce the issue

### Contributing
- Follow the existing code style
- Add tests for new features
- Update documentation
- Test on multiple platforms when possible
