// PLAYER class - Inherited class from character, will house all infor/values for player character
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"


#include <string>
#include <vector>

using namespace std;


class Player : public Character {
    private:
        int gold;
        int sanity;
        //int critChance;
        int currentLocation; // integer value for location
        string locationName; //?? need for converting numbered areas to strings CURRENTLY NOT IN USE
        vector<Item> inventory;

    public:
        Player(int g, int s, int cL); //constructor



        //setters
        void setGold(int newGold); // place temporary value in setter to replace the private value with
        void setSanity(int newSanity);
        void moveLocation(int newLocation);
        // int setCrit(int newCritChance);

        //player inventory setters
        void addItem(Item newItem);



        //Player getters
        int getGold();
        int getSanity();
        int getCL();
        void displayPlayerStats(); // will display health attack and level for now

        //Player Inventory getters
        void displayInventory();
        bool hasItem(string itemName);
        int getInventorySize()
};

#endif