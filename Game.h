// GAME CLASS - controls all actions of the game, master class for game mechanics and game loop
#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <vector>

#include "Character.h" // include all other classes for Game class access
#include "Player.h"
#include "Enemy.h"
#include "Area.h"
#include "Item.h"

using namespace std;


class Game {
    private: // private variables
        Player player; // create one object from player class - EXISTS
        vector<Area> areas; //create a vector of locations starting with one location - EXISTS
        vector<Enemy> enemies; // create a vector of enemies starting with 1 enemy - EXISTS
        int day;
        int time;
        bool running; //control variable for overall sample game loop
        int currentLocationIndex;  // game index for area locations, have 2 similar variables in Area.h maybe problem??????

        //END GAME Relic Progress (x5 Quests?)
        int relicProgress;

        bool guildEmblemDonated;
        bool whisperingBarkDonated;
        bool eldritchSilkDonated;
        bool underbellyKeyDonated;
        bool porcelainShardDonated;

    public:

    //constructor
    Game(int newDay, int newTime, bool newRunning, int newCurrentLocationIndex);

    //prototype functions for game commands some setters some getters REORGANIZE!!
    void startGame(); // start game method
    void processMenuChoice(); // recieve player input perform action associated // adjusted for two choices one for title screen menu and the other for user actions/dash
    void processDashChoice(); // recieve player dash choice
    void displayDash(); // displays dashboard
    void displayMenu(); //displays menu maybe combine dash and menu
    void displayCurrentArea(); // displays current active area
    void displayEnemies(); // displays enemies in area
    void travel(); // trave action to move location
    void endGame(); // ends game
    void combat(); // combat function

    //add combat systems here as well as additional game mechanics

    //getters
    int getDay(); //get day
    int getTime(); //get time
    bool getRunning(); //get running confirmation

    //ENDGAME RELIC PROGRESS FUNCTIONS
    void displayObjective();
    void donateRelic();
    bool checkWin();

    //relic - combat
    void rollRelicDrop(int enemyIndex); // roll chance for relic drop based on enemyIndex
    void respawnClearedArea(int LocationIndex); // respawn enemies in area once cleared
};
#endif