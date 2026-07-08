// ENEMY class - Inherited class from character, will house all infor/values for Enemy characters (mobs)
#ifndef ENEMY_H
#define ENEMY_H


#include <string>
#include <vector>

using namespace std;

class Enemy {
    private:
        int damage; //attack but for enemy, maybe change later if confusing
        int sanityDam;
        int loot; // maybe add additional loot detail for strings??
        bool defeated;


    public:
        //constructor
        Enemy(int d, int sD, int L);
        
        //setters
        int setDam();
        int setSanityDam();
        int setLoot();
        bool setIsDefeated();

        //getters
        int getDam();
        int getsanityDam();
        int getLoot();
        bool getIsDefeated();
};
#endif