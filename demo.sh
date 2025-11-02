#!/bin/bash

# Demo Script for Echoes of the Forgotten Realm
# This script demonstrates the key features of the game

echo "=== ECHOES OF THE FORGOTTEN REALM - DEMO SCRIPT ==="
echo ""
echo "This demo will showcase the main features of the game:"
echo "1. Game initialization and character creation"
echo "2. Room exploration and navigation"
echo "3. Item collection and inventory management"
echo "4. Combat system"
echo "5. Memory system and story progression"
echo "6. Multiple game commands"
echo ""
echo "Starting demo..."
echo ""

# Create a demo input file
cat > demo_input.txt << 'EOF'
Hero
help
look
take rusty sword
inventory
take health potion
move north
look
move north
look
move south
move east
look
take ancient key
memory
use ancient key
look
move north
take legendary blade
inventory
move south
move west
move north
move east
attack
quit
y
EOF

echo "Running game with demo inputs..."
echo ""

# Run the game with demo input
./echoes_game < demo_input.txt

echo ""
echo "=== DEMO COMPLETED ==="
echo ""
echo "Key features demonstrated:"
echo "✓ Character creation and initialization"
echo "✓ Room navigation (north, east directions)" 
echo "✓ Item pickup and inventory management"
echo "✓ Weapon auto-equipping system"
echo "✓ Memory journal system with story triggers"
echo "✓ Key usage for unlocking areas"
echo "✓ Combat initiation"
echo "✓ Help system and command parsing"
echo ""
echo "For full gameplay experience, run: ./echoes_game"
echo "Try commands like: look, move north, take [item], attack, inventory, memory"
echo ""

# Clean up demo file
rm -f demo_input.txt
