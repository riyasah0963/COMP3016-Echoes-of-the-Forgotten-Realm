# Sample Gameplay Session

This document shows what a typical gameplay session looks like.

## Game Start
```
========================================
   Echoes of the Forgotten Realm
========================================

You awaken in a ruined world with no memory...
Explore, survive, and uncover your forgotten past.

Enter your name: Hero

Welcome, Hero!
Type 'help' for available commands.

=== Wrecked Village ===
You stand in the ruins of what was once a thriving village. Collapsed houses and broken carts litter the area. A sense of ancient tragedy hangs in the air.

Items here:
- rusty sword (An old but serviceable blade)
- health potion (A small vial of red liquid)

Exits: north, east
```

## Basic Exploration
```
> help

=== AVAILABLE COMMANDS ===
Movement:
  move [direction] / go [direction] / [direction]
  north/n, south/s, east/e, west/w

Interaction:
  look/l - Examine your surroundings
  take [item] / get [item] - Pick up an item
  use [item] - Use an item from inventory
  attack [enemy] / fight - Start combat

Info:
  inventory/i - Show your items
  memory/journal - View recovered memories
  status - Show your character status

Game:
  save - Save your progress
  load - Load saved game
  help/h - Show this help
  quit/exit/q - Exit the game
=========================

> take rusty sword
You picked up: rusty sword
You equipped: rusty sword (+5 attack)

*** MEMORY RECOVERED ***
You remember wielding this blade in battle against the Shadow Forces...
**********************

> inventory

=== INVENTORY ===
Gold: 50
Equipped Weapon: rusty sword (+5 attack)
Items:
- rusty sword (Weapon) [Effect: 5]
=================

> move north
You move north...

=== Misty Forest ===
Dense fog swirls between ancient trees. The forest feels alive with whispers of the past. Strange shadows dance between the branches.

A Goblin Scout appears!

Items here:
- iron dagger (A sharp, well-balanced dagger)

Enemies present:
- Goblin Scout (Goblin)

Exits: south, north, east
```

## Combat Example
```
> attack

*** COMBAT BEGINS ***
Goblin Scout (Goblin)
Health: 25/25
Attack: 8 | Defense: 2
**********************

What do you want to do?
1. Attack
2. Use item
3. Try to flee
> 1

You attack the Goblin Scout for 15 damage!
Goblin Scout takes 15 damage. Health: 10/25
Goblin Scout attacks for 7 damage!
You take 2 damage. Current health: 98/100

What do you want to do?
1. Attack
2. Use item
3. Try to flee
> 1

You attack the Goblin Scout for 15 damage!
Goblin Scout takes 15 damage. Goblin Scout is defeated!

*** COMBAT ENDS ***

You defeated the Goblin Scout!
You gained 15 gold.
```

## Story Progression
```
> move east
You move east...

=== Abandoned Temple ===
Crumbling stone pillars support a partially collapsed roof. Ancient runes glow faintly on the walls, hinting at forgotten power.

Items here:
- ancient key (An ornate key humming with power)
- crystal shard (A glowing fragment of pure energy)

Exits: west, north

> take ancient key
You picked up: ancient key

*** MEMORY RECOVERED ***
This key once opened the doors to your forgotten castle...
**********************

> take crystal shard
You picked up: crystal shard

*** MEMORY RECOVERED ***
The crystal resonates with power - a fragment of the Realm's heart...
**********************

> use ancient key
The ancient key fits perfectly! A hidden passage opens.
You unlock the hidden chamber! A passage opens to the north.

> memory

=== MEMORY JOURNAL ===
1. You remember wielding this blade in battle against the Shadow Forces...
2. This key once opened the doors to your forgotten castle...
3. The crystal resonates with power - a fragment of the Realm's heart...
=====================

> move north
You move north...

=== Hidden Chamber ===
A secret chamber revealed by the ancient key. Mystical energy fills the air, and a portal of swirling darkness dominates the center.

Dark energy pervades this place. Your soul feels heavy.

Items here:
- legendary blade (The weapon of a forgotten hero)

Exits: south

> take legendary blade
You picked up: legendary blade
You equipped: legendary blade (+15 attack)
```

## Final Area
```
> move south
You move south...

> move north
You move north...

> move east
You move east...

=== Ruined Keep ===
The once-mighty fortress now lies in ruins. A throne room opens before you, where shadows seem to gather with unnatural purpose.

Enemies present:
- Shadow Lord (Boss)

Exits: west, south

> status

=== CHARACTER STATUS ===
Name: Hero
Health: 96/100
Attack: 25
Defense: 5
Gold: 65
Current Location: Ruined Keep
Turns Played: 15
========================

> attack

*** COMBAT BEGINS ***
Shadow Lord (Boss)
Health: 100/100
Attack: 20 | Defense: 8
**********************

[Combat continues...]

You defeated the Shadow Lord!
You gained 100 gold.

*** MEMORY RECOVERED ***
You have defeated the Shadow Lord and restored balance to the realm!
**********************

========================================
         CONGRATULATIONS!
   You have restored the realm!
Your memories have returned, and the
Shadow Lord's curse is broken forever.
========================================

Final Stats:
Turns played: 23
Memories recovered: true

Thank you for playing Echoes of the Forgotten Realm!
```

## Key Features Demonstrated

1. **Character Creation**: Player enters name and starts adventure
2. **Room Navigation**: Movement between connected areas
3. **Item Management**: Picking up items, automatic weapon equipping
4. **Memory System**: Story progression through item interactions
5. **Combat System**: Turn-based fighting with multiple options
6. **Puzzle Elements**: Using keys to unlock new areas
7. **Environmental Hazards**: Rooms that affect player health
8. **Multiple Endings**: Victory condition based on story completion
9. **Statistics Tracking**: Game keeps track of progress and stats
10. **Command System**: Rich text-based interface with help system

This sample shows approximately 20-30 minutes of gameplay, demonstrating all major features of the game.
