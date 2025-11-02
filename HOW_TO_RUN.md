# SIMPLE INSTRUCTIONS TO RUN YOUR GAME

## Quick Start Commands (Copy and Paste These)

### 1. Open Terminal and Navigate to Your Game
```bash
cd "/media/love/7bb51a76-d8df-4ea9-bfe9-02f1a442fc3c/Echoes of the Forgotten Realm"
```

### 2. Make Files Executable (Run Once)
```bash
chmod +x demo.sh
chmod +x echoes_game
```

### 3. Run the Game Demo (Shows All Features)
```bash
./demo.sh
```

### 4. Run the Full Interactive Game
```bash
./echoes_game
```

## What to Expect

### When You Run `./demo.sh`:
- Shows automated demo of all game features
- Demonstrates combat, exploration, items, memory system
- Perfect for showing your assignment to professors

### When You Run `./echoes_game`:
- Interactive game where YOU control the character
- Type commands like: `help`, `look`, `move north`, `take sword`
- Full gameplay experience

## Game Commands You Can Use

### Basic Commands:
- `help` - Show all commands (START HERE!)
- `look` - See what's around you
- `inventory` - Check your items
- `status` - Show your character stats

### Movement:
- `move north` or just `north` or `n`
- `move south` or just `south` or `s`
- `move east` or just `east` or `e` 
- `move west` or just `west` or `w`

### Interactions:
- `take [item name]` - Pick up items (e.g., `take sword`)
- `use [item name]` - Use potions or keys
- `attack` - Fight enemies
- `memory` - View your recovered memories

### System:
- `save` - Save your progress
- `load` - Load saved game
- `quit` - Exit the game

## Step-by-Step Gameplay Example

1. Start the game: `./echoes_game`
2. Enter your name when prompted
3. Type: `help` (to see all commands)
4. Type: `look` (to see your surroundings)
5. Type: `take rusty sword` (to pick up your first weapon)
6. Type: `inventory` (to see what you have)
7. Type: `move north` (to explore)
8. Type: `attack` (if you meet enemies)
9. Continue exploring and collecting items!

## For Windows Users

If you're on Windows, use these commands in PowerShell or Command Prompt:

### Using Windows Subsystem for Linux (WSL):
1. Open PowerShell as Administrator
2. Install WSL: `wsl --install`
3. Restart computer
4. Open Ubuntu from Start menu
5. Use the Linux commands above

### Using MinGW or Git Bash:
```bash
cd "Echoes of the Forgotten Realm"
g++ -std=c++17 src/*.cpp -o echoes_game.exe
./echoes_game.exe
```

## If Something Goes Wrong

### Error: "Permission denied"
```bash
chmod +x echoes_game
chmod +x demo.sh
```

### Error: "No such file or directory"
```bash
# Make sure you're in the right folder
pwd
ls -la
```

### Error: "g++ not found"
```bash
# Install build tools first
sudo apt update
sudo apt install build-essential
```

### Need to Recompile?
```bash
make clean
make
```

## Assignment Presentation Tips

1. **Show the Demo First**: Run `./demo.sh` to impress with automated showcase
2. **Then Play Manually**: Run `./echoes_game` and play interactively
3. **Highlight Features**: 
   - Object-oriented design (show the code files)
   - Memory system (collect items to trigger memories)
   - Combat system (fight enemies)
   - File structure (show the organized folders)
4. **Show Documentation**: Open the files in `docs/` folder

## MOST IMPORTANT COMMANDS FOR YOUR ASSESSMENT:

```bash
# 1. Navigate to game folder
cd "/media/love/7bb51a76-d8df-4ea9-bfe9-02f1a442fc3c/Echoes of the Forgotten Realm"

# 2. Run the impressive demo
./demo.sh

# 3. Run the interactive game
./echoes_game

# 4. In the game, type these to show features:
help
look
take rusty sword
inventory
move north
attack
memory
quit
```

Your game is complete and ready to impress! 🎮
