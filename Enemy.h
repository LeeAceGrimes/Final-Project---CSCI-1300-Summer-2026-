// ENEMY class - Inherited class from character, will house all infor/values for Enemy characters (mobs)
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"


#include <string>
#include <vector>

using namespace std;

class Enemy : public Character {
    private:
        int damage; //attack but for enemy, maybe change later if confusing
        int sanityDam;
        int loot; // maybe add additional loot detail for strings??
        bool defeated;


    public:
        //constructor
        Enemy(int d, int sD, int L);

        //setters
        int setDam(int newDam); // set damage
        int setSanityDam(int newSanityDam); // set sanity damage
        int setLoot(int newLoot); //set loot
        bool setIsDefeated(bool newIsDefeated); //set defeated status

        //getters
        int getDam(); // get damage
        int getsanityDam(); //get sanity damage
        int getLoot(); // get loot
        bool getIsDefeated(); // get defeated status
};
#endif