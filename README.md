# The Hall of Conquest

Final project for CSCI 1300, Summer 2026.

## Theme and Goal

The Hall of Conquest is a single-player, text-based fantasy adventure game written in C++. The player is a new adventurer tasked with restoring the ruined Hall of Conquest before time expires.

Recover and donate five relics before the end of Day 7:

1. Guild Emblem
2. Whispering Bark
3. Eldritch Silk
4. Abyssal Coin
5. Porcelain Shard

Relics can be earned by defeating monsters or purchased from the shady merchant Harry. Harry provides a faster route, but every purchase costs gold, raises Dark Influence, and can change the ending.

## Compiling

Open a terminal in the project directory and compile every source file:

```bash
g++ -Wall -Werror -Wpedantic main.cpp Game.cpp Player.cpp Character.cpp Enemy.cpp Item.cpp Area.cpp -o game
```

## Running

Windows PowerShell:

```powershell
.\game.exe
```

macOS or Linux:

```bash
./game
```

## How to Play

Select actions by entering the corresponding integer shown in the terminal.

1. Start the game from the main menu.
2. Speak with Guildmaster Elara at the Guild Hall to receive the first relic.
3. Travel to unlocked locations and speak with characters to open later areas.
4. Fight enemies to earn gold and roll for location-specific relic drops.
5. Retreat when necessary and rest at the Guild Hall to restore health and sanity.
6. View player information to inspect the inventory.
7. Return to the Guild Hall to donate collected relics.
8. If needed, visit Harry in the Underbelly to purchase missing relics at the cost of gold and Dark Influence.
9. Donate all five relics before the seven-day limit expires.

The ASCII map marks the current location and displays whether later areas are locked or unlocked.

## Locations

- **Guild Hall:** Starting location, donation site, and resting area.
- **Whispered Forest:** First combat area and source of Whispering Bark and Eldritch Silk.
- **The Underbelly:** Unlocked through Scout Rowan and source of the Abyssal Coin.
- **Porcelain Fortress:** Unlocked through Warden Celeste and source of the Porcelain Shard.

## Characters

- **Guildmaster Elara:** Introduces the objective and gives the Guild Emblem.
- **Scout Rowan:** Unlocks access to the Underbelly.
- **Warden Celeste:** Unlocks access to the Porcelain Fortress.
- **Harry:** Sells missing relics and increases Dark Influence.

## Resources and Gameplay

- **Time:** Seven days with five action periods per day.
- **Health:** Reduced by physical enemy attacks.
- **Sanity:** Reduced by enemy sanity attacks.
- **Gold:** Earned through combat and spent at Harry's shop.
- **Dark Influence:** Increased by buying relics from Harry and used to determine the ending.
- **Inventory:** Stores relics until they are donated at the Guild Hall.

Combat is turn-based. The player may attack or retreat. Defeated enemies award gold and may drop a relic associated with their location. After every enemy in an area is defeated, enemies respawn so the player can make additional drop attempts.

## Endings

- **The Honorable Restoration:** Complete the objective without using Harry.
- **The Tainted Restoration:** Complete the objective with limited Dark Influence.
- **Harry's Ascendance:** Complete the objective after relying heavily on Harry.
- **Time Expired:** Fail to complete the objective before the deadline.
- **Combat Defeat:** Reach zero health or sanity.

## Classes

- **Character:** Base class containing shared name, description, health, attack, and level data.
- **Player:** Inherits from `Character` and stores gold, sanity, current location, and a vector of `Item` objects.
- **Enemy:** Inherits from `Character` and stores damage, sanity damage, loot, location, and defeated status.
- **Item:** Represents a collectible with a name, type, value, and objective status.
- **Area:** Represents a location with a name, description, index, and unlocked status.
- **Game:** Owns the player and vectors of areas and enemies, and controls menus, travel, combat, NPC interactions, time, relic donations, the map, and endings.

## Project Files

main.cpp
Game.h / Game.cpp
Character.h / Character.cpp
Player.h / Player.cpp
Enemy.h / Enemy.cpp
Item.h / Item.cpp
Area.h / Area.cpp
README.md
