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

using namespace std;


class Game {
    private: // private variables
        Player player; // create one object from player class - EXISTS
        vector<Area> areas; //create a vector of locations starting with one location - EXISTS
        vector<Enemy> enemies; // create a vector of enemies starting with 1 enemy - EXISTS
        int currentLocationIndex;  // game index for area locations, have 2 similar variables in Area.h maybe problem??????
        int day;
        int time;
        bool running; //control variable for overall sample game loop

    public:

    //constructor
    Game(int d, int t, bool r, int currentLocationIndex);

    //prototype functions for game commands
    void startGame(); // start game method
    void processChoice(); // recieve player input perform action associated
    void displayDash(); // displays dashboard
    void displayMenu(); //displays menu maybe combine dash and menu
    void displayCurrentArea(); // displays current active area
    void displayEnemies(); // displays enemies in area
    void travel(); // trave action to move location
    void endGame(); // ends game

    //add combat systems here as well as additional game mechanics
    //getters
    int getDay();
    int getTime();
    bool getRunning();
};
#endif