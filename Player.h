// PLAYER class - Inherited class from character, will house all infor/values for player character
#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>

using namespace std;


class Player {
    private:
        int gold;
        int sanity;
        int critChance;
        int currentLocation;
        string locationName; //?? need for converting numbered areas to strings
        // int inventoryItems;

    public:
        Player(int g, int s, int cL) { //constructor
            gold = g;
            sanity = s;
            currentLocation = cL;
        }

        //setters
        int setGold();
        int setSanity();
        int moveLocation();
        int setCrit();

        //getters
        int getGold();
        int getSanity();
        int getCL();
        int getPStats();
};

#endif