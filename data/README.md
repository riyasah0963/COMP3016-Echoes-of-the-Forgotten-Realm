# Game Data Files

This folder contains external data files that can be used to modify game content without recompiling.

## Current Implementation
The current version has game data built into the code for simplicity. However, the architecture supports loading from external files.

## File Formats

### rooms.txt Format
```
[ROOM_ID]
name=Room Name
description=Room description text
exits=north:room2,east:room3
hazard=none|poison|cursed|cold|hot
special_event=Optional special event text
```

### items.txt Format
```
[ITEM_NAME]
description=Item description
type=weapon|potion|key|treasure|quest_item
value=monetary_value
effect=mechanical_effect_value
```

### enemies.txt Format
```
[ENEMY_NAME]
type=goblin|wolf|skeleton|ghost|boss
health=health_points
attack=attack_value
defense=defense_value
gold_reward=gold_dropped
```

### dialogues.txt Format
```
[MEMORY_ID]
trigger_item=item_name
memory_text=The memory text to display
```

## Future Enhancement
These files would be loaded by a FileManager class to populate the game world dynamically.
