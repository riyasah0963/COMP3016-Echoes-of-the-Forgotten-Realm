# Test Cases - Echoes of the Forgotten Realm

## Unit Testing Strategy

### Player Class Tests

#### Test Case 1: Player Creation
- **Objective**: Verify player initializes with correct default values
- **Input**: Player("TestHero")
- **Expected Output**: 
  - Name: "TestHero"
  - Health: 100/100
  - Attack: 10, Defense: 5
  - Gold: 50
  - Empty inventory

#### Test Case 2: Combat Mechanics
- **Objective**: Test damage calculation and health management
- **Steps**:
  1. Create player with 100 health
  2. Call `takeDamage(20)` with defense 5
  3. Verify health reduces by 15 (20-5)
  4. Test healing with `heal(10)`
  5. Verify health increases but doesn't exceed maximum

#### Test Case 3: Inventory Management
- **Objective**: Test item addition, removal, and equipment
- **Steps**:
  1. Add sword item to inventory
  2. Verify `hasItem("sword")` returns true
  3. Equip sword and verify attack bonus
  4. Remove item and verify inventory update

### Item Class Tests

#### Test Case 4: Item Types
- **Objective**: Verify item type classification and usability
- **Steps**:
  1. Create WEAPON type item
  2. Verify `getTypeString()` returns "Weapon"
  3. Create POTION type item
  4. Verify `isUsable()` returns true for potions

### Enemy Class Tests

#### Test Case 5: Combat Behavior
- **Objective**: Test enemy attack patterns and damage
- **Steps**:
  1. Create enemy with known stats
  2. Call `performAttack()` multiple times
  3. Verify damage is within expected range
  4. Test damage application with `takeDamage()`

#### Test Case 6: Factory Methods
- **Objective**: Verify enemy creation factories
- **Steps**:
  1. Call `Enemy::createRandomEnemy()` multiple times
  2. Verify different enemy types are created
  3. Test boss creation with `createBoss()`

### Room Class Tests

#### Test Case 7: Room Navigation
- **Objective**: Test room connections and movement
- **Steps**:
  1. Create two rooms
  2. Add exit from room1 to room2
  3. Verify `getExit("north")` returns correct room ID
  4. Test invalid direction returns empty string

#### Test Case 8: Item Management
- **Objective**: Test room item storage and retrieval
- **Steps**:
  1. Add item to room
  2. Verify `hasItem()` finds the item
  3. Take item and verify it's removed from room
  4. Confirm `takeItem()` returns null for missing items

### GameEngine Integration Tests

#### Test Case 9: Command Parsing
- **Objective**: Test input parsing and command execution
- **Input**: Various command strings
- **Expected Results**:
  - "move north" → handleMove("north")
  - "take sword" → handleTake("sword")
  - "inventory" → handleInventory()
  - Invalid commands → error message

#### Test Case 10: Combat System
- **Objective**: Test complete combat flow
- **Steps**:
  1. Place enemy in room
  2. Initiate combat with "attack"
  3. Verify turn-based combat mechanics
  4. Test victory conditions and rewards

#### Test Case 11: Win Condition
- **Objective**: Test game completion requirements
- **Steps**:
  1. Defeat final boss
  2. Verify `finalBossDefeated` flag is set
  3. Check that game ends with victory message

## Integration Testing

### Test Case 12: Complete Playthrough
- **Objective**: Simulate full game session
- **Steps**:
  1. Start new game
  2. Move through all rooms
  3. Collect key items
  4. Fight random encounters
  5. Unlock hidden areas
  6. Defeat final boss
  7. Verify victory condition

### Test Case 13: Memory System
- **Objective**: Test story progression tracking
- **Steps**:
  1. Pick up story-relevant items
  2. Verify memories are added to journal
  3. Check memory triggers affect game state
  4. Test memory journal display

### Test Case 14: Save/Load System
- **Objective**: Test game state persistence
- **Steps**:
  1. Play game to mid-point
  2. Save game state
  3. Load saved state
  4. Verify all data restored correctly

## Error Handling Tests

### Test Case 15: Invalid Input
- **Objective**: Test graceful handling of bad input
- **Inputs**: 
  - Empty commands
  - Unknown commands
  - Invalid parameters
- **Expected**: Error messages, no crashes

### Test Case 16: Edge Cases
- **Objective**: Test boundary conditions
- **Steps**:
  1. Try to move when enemies present
  2. Use items not in inventory
  3. Attack when no enemies present
  4. Attempt to equip non-weapon items

## Performance Tests

### Test Case 17: Memory Management
- **Objective**: Verify no memory leaks
- **Method**: Run game with memory profiler
- **Expected**: All allocated memory properly freed

### Test Case 18: Large Inventory
- **Objective**: Test performance with many items
- **Steps**:
  1. Add 100+ items to inventory
  2. Perform inventory operations
  3. Verify reasonable response times

## Test Data

### Sample Items for Testing
```cpp
Item sword("Steel Sword", "Sharp blade", Item::Type::WEAPON, 50, 10);
Item potion("Health Potion", "Healing liquid", Item::Type::POTION, 25, 20);
Item key("Ancient Key", "Mystical key", Item::Type::KEY, 0, 0);
```

### Sample Enemies for Testing
```cpp
Enemy goblin("Test Goblin", Enemy::Type::GOBLIN, 25, 8, 2, 15);
Enemy boss("Test Boss", Enemy::Type::BOSS, 100, 20, 8, 100);
```

## Automated Testing Script

```bash
#!/bin/bash
# Run automated tests
echo "Running Echoes of the Forgotten Realm Tests..."

# Compile test version
g++ -std=c++17 -DTEST_MODE src/*.cpp -o test_game

# Run unit tests
./test_game --unit-tests

# Run integration tests  
./test_game --integration-tests

# Run performance tests
./test_game --performance-tests

echo "All tests completed."
```

## Manual Testing Checklist

- [ ] Game starts and displays intro
- [ ] Player can move between rooms
- [ ] Items can be picked up and used
- [ ] Combat system functions correctly
- [ ] Memory system triggers properly
- [ ] Save/load works as expected
- [ ] Win condition triggers victory
- [ ] All commands work as documented
- [ ] Error messages are helpful
- [ ] Game exits cleanly
