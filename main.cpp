//Main.cpp small file, creates game object once start game is initiated.
//Inlcude Header files
#include "Game.h" // game.h is master controller file. Should inherit access to all functions as they are all included on game.h

//include libraries
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//call functions (if needed)


int main() {
    //game constructor, make game object, game.cpp controls everything else
    Game game(1, 1, true, 0); //day, time, running, locationindex 

    game.startGame(); // start game function display menu take user choice

    return 0;
}

//still need to adjust day and time cycles
//combat
//companion
//npcs
//quest system
//leveling system

//Total Compilation
// add newline in after each text block for better visibility --- FIXED
// total enemies in area formatting ---- FIXED
// areas available output ---- FIXED