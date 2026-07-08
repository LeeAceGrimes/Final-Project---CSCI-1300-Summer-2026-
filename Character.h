// CHARACTER class - will house all stats available to Player, Pet, Enemies, and NPCs.The latter will inherit, all class information
#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include <vector>

using namespace std;

class Character {
    private: // name, levle, health, attack, critchance??, character info for checkpoint 2
        string name;
        int level;
        int health;
        int attack;
        //int critChance; mobs can no longer crit, exclusive to player
        string info;
        //creature type?
        // int defense; ??

    public:
        //setters/methods
        Character(string n, int lvl);

        string setName(string newName);
        int setHealth(int newHealth);
        int setAttack(int newAttack);
        string setInfo(string newInfo); // may not use but have available.


        //getters
        string getName();
        int getHealth();
        int getAttack();
        string getInfo();
};


#endif