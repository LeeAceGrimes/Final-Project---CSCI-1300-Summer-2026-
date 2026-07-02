# CSCI 1300 Final Project
## CheckPoint 1 Reqs - Theme, Planned Classes, Planned Limited Resource System, Time Management, Trade Off System, Mapping Style, Win/Loss

## Title

Moonveil

## Theme
The Following is a terminal based RPG Adventure borrowing elements from multiple games. The basic premise is the player starts as a new adventurer in a Lovecraftian world. Eager to earn a buck at the small town of Moonveil who has had increased monster appearances. Through a serious of Jobs provided by the local Guild, you are to journey deeper into the secrets of the city uncovering the root of the corruption with guidance from the guild as well as your trusty companion of your choice. Together you must battle eldritch horrors, unlike new companions and abilities, all with guidance from the guild on stopping an evil fate from befalling the town.

## Classes
Begining with a minimum of 3 classes, I require at minimum the following initial classes:
Enemy - houses all Enemy based attributes, health, attack, defense, crit chance, loot chance, level.
Player - Will carry all attricutes of the player similarly to enemy. (I may use this as well for character NPCs, otherise will create a similar class.
Inventory - class to manage the inventory of the player directly. Tracks inventory space and outputs contents to user.
Gear - regardless of the spot the gear goes (very simple inventory) All gear share the same attributes. I'd like for this class to deal with gear and equipment

Additionally:
Quest - this will house all quests and their shared attributes. name, bool, reward, difficulty, time.
NPC - this can be used in similar fashion to house the 4+ NPC builds.
Area - If I design the game in text adventure fashion it might be beneficial to have a class for the area, to make it easier to hold multiple details about a visited area.

(Other Classes currently TBD)

## How to play
As a Text based RPG adventure, the game takes place completely in the terminal. All details, information, options and actions will be prompted to the user via the terminal. From there the player will be able to take a serious of actions, The main hub with available options will always be avilable for the player. Any necessary artwork such as the map will be done in ASCII. The goal is simple as a new adventurer in town trying to earn their keep, you find out something more sinister is occurring. The game will present the basic game loop of completing quests to earn money for various upgrades. There is no XP in this game, the town currency fills that role. As you set out to quest, each action takes an informed amount of time away from the 24 hour day cycle. Despite this the player will have the option to adventure at night for increased drop rewards at the risk of greater danger. Additionally you trusty companion is more than a morale comfort, you pet companion during combat restores sanity, which must be managed. At random intervals of play, 1 of 2 quests may spawn at the Guild, this will prompt a further investigation into what eldritch dealings are happening in Moonveil. 

## Time Management
The game will run on a 24 hour system similar to stardew valley. Availble actions will have a time cost associated with them. The game is intended to run from 8AM to 8PM, after that the day is considered complete unless the player chooses to adventure at night. If the player chooses to adventure at night the stakes will be raised. However the clock will continue to tick with each action. By 8AM return to base to turn in for the day. (The system is fixed, however I am unsure if I want to allow for player choice due to complexity, or to emulate stardew valley and have a firm start and end time.)

## Limited Resources
Coins & Sanity

Limited Resources Come in the form of Coins from defeating monsters and completing quests and Sanity from time spent adventuring. Coins work as a form of XP, you can you coins to purchase certain rarities of gear, this gear acts as a direct stat modifier and level boost. Sanity is a limited resource That you lose during combat as well as over time when adventuring at night. There are ways of restoring your sanity, each time your pet companion scores a critical hit on a mob you restore a portion of your sanity. Additionally there are potions that can be purchased. As well as the option of retreating if the player feels "stuck". (Sanity will be a resource managed by the player using Companion to relieve stress as well as maintain battle readiness through pet actions i.e. Critical Hit would reduce stress.)

## Trade Off System
Currently the biggest trade-off system I can offer thematically to the player is the night cycle. As loot is fairly scarce in a town plagued by Eldritch sightings and horrors. However at night the difficulty scales which is a major drawback, however the trade off is Loot chance as well as amount is much higher. This allows the player to make a trade. With the death of your character or sanity reaching 0 ending the game the player is forced to make a choice whenever they feel comfortable. Adventure during the day much more comfortably, or endure challenge and progress quicker.

## Mapping Style/System
Mapping style will be in very basic ASCII as most of the time will be spent developing the game's systems. The interaction menu will be a list availble to the user.

## Locations
Guild Hall
Town
Cave
Forest
TBD
TBD

## Characters
(TBA)

## Quests
2 quest chains. Triggered on RNG, 5 Quests per chain. Defeating one quest chain Wins the game.
Chain 1 - Start Triggered -> Q2 -> Q3 -> Q4 -> Q5 
Chain 2 - Start Triggered -> Q2 -> Q3 -> Q4 -> Q5
These quest changes will be different in flavor however the quest objective or mechanics may be shared between both questlines.

## Enemies
(TBA)

## Win/Lose Condition

The Win condition is simple, Survive. If you can successfully earn your keep as an adventurer, begin and successfully complete the quest chain you have won. If your character falls sanity reaches 0, the game will RESET in souls-like fashion (As this game is not very long this mechanic should not be too punishing. Will revise after continued evaluation. In case of revision I would remove the night cycle, make sanity harder to manage but give more tools to manage, without it oppressing the game loop.

## Extra credit

(TBA) (Additionally I have alot of things I would like to add on to the game, but I am unaware of how to implement currently)
