// PLAYER class - Inherited class from character, will house all infor/values for player character
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"


#include <string>
#include <vector>

using namespace std;


class Player : public Character {
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
        int setGold(int newGold); // place temporary value in setter to replace the private value with
        int setSanity(int newSanity);
        int moveLocation(int newLocation);
        int setCrit(int newCritChance);

        //getters
        int getGold();
        int getSanity();
        int getCL();
        int getPStats();
};

#endif