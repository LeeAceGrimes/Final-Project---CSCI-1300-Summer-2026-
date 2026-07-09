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
        int enemyLocationIndex; //location ADDED! This will let me define where the mob is like player


    public:
        //constructor
        Enemy(int d, int sD, int L, int locationIndex);

        //setters
        void setDam(int newDamStat); // set damage
        void setSanityDam(int newSanityDamStat); // set sanity damage
        void setLoot(int newLoot); //set loot
        void setIsDefeated(bool newIsDefeated); //set defeated status
        void setEnemyLocationIndex(int newEnemyLocationIndex); // set enemy location index

        //getters
        int getDam(); // get damage
        int getSanityDam(); //get sanity damage
        int getLoot(); // get loot
        bool getIsDefeated(); // get defeated status
        void displayEnemy();
        int getEnemyLocationIndex(); // added getter - enemy location index
};
#endif