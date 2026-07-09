// ENEMY class - Inherited class from character, will house all infor/values for Enemy characters (mobs)
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"


#include <string>
#include <vector>

using namespace std;

class Enemy : public Character {
    private:
        int damageStat; //attack but for enemy, maybe change later if confusing
        int sanityDamStat;
        int loot; // maybe add additional loot detail for strings??
        bool defeated;
        //location?


    public:
        //constructor
        Enemy(int d, int sD, int L);

        //setters
        void setDam(int newDamStat); // set damage
        void setSanityDam(int newSanityDamStat); // set sanity damage
        void setLoot(int newLoot); //set loot
        void setIsDefeated(bool newIsDefeated); //set defeated status

        //getters
        int getDam(); // get damage
        int getSanityDam(); //get sanity damage
        int getLoot(); // get loot
        bool getIsDefeated(); // get defeated status
        void displayEnemy();
};
#endif