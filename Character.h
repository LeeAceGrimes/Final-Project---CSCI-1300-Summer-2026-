// CHARACTER class - will house all stats available to Player, Pet, Enemies, and NPCs.The latter will inherit, all class information
#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include <vector>

using namespace std;

class Character {
    private: // name, levle, health, attack, critchance??, character info for checkpoint 2
        string name;
        int levelStat;
        int healthStat;
        int attackStat;
        //int critChance; mobs can no longer crit, exclusive to player
        string info;
        //creature type?
        // int defense; ??

    public:
        //setters/methods - set setters to void as they return nothing
        Character(string n, int lvl); // for other parameters set to default in .cpp file

        void setName(string newName);
        void setHealth(int newHealthStat);
        void setAttack(int newAttackStat);
        void setInfo(string newInfo); // may not use but have available.
        void setLevelStat(int newLevelStat);


        //getters - getters return values do not make void
        string getName();
        int getHealth();
        int getAttack();
        string getInfo();
        int getLevelStat();
};


#endif