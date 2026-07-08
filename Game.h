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
        int day;
        int time;
        bool running; //control variable for overall sample game loop
        Player player; // create one object from player class - EXISTS
        vector<Area> location; //create a vector of locations starting with one location - EXISTS
        vector<Enemy> enemy; // create a vector of enemies starting with 1 enemy - EXISTS
        int currentAreaI;  // game index for area locations, have 2 similar variables in Area.h maybe problem??????


    public:

    //constructor
    Game(int d, int t, bool r, int currentAI);



    //setters
    int setDay(int newDay);

    int setTime(int newTime);

    bool setRunning(bool newRunning);



    //startGame
    //displayDash
    //displayMenu
    //displayCurrentArea
    //displayEnemies
    //travel
    //endGame





    //getters













};

#endif