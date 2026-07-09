#include "Enemy.h" //include header files enemy and character
#include "Character.h"

#include <iostream> // probably don't need to keep redeclaring but is a habit
#include <String>
#include <vector>

using namespace std;

Enemy::Enemy(int d, int sD, int L) // contructor similar to player but with enemy variables
    : Character("Vile Spider", "An invasive species of spider native to this region, however they have since grown quite large and increased in aggression lately.")
{   //default name and description for starting enemy
    damageStat = d;
    sanityDamStat = sD;
    loot = L;
}

//setters - Don't need to rewrite the same functions if inherited from one class to another
void Enemy::setDam(int newDamStat) { 
    damageStat = newDamStat;
}

void Enemy::setSanityDam(int newSanityDamStat) { //set sanity dam stat
    sanityDamStat = newSanityDamStat;
}

void Enemy::setLoot(int newLoot) { // set loot value
    loot = newLoot;
}

void Enemy::setIsDefeated(bool newIsDefeated) { //set defeated status (eventually during combat if health reaches 0 defeated = true)
    defeated = newIsDefeated;
}

//getters
int Enemy::getDam() {
    return damageStat;
}

int Enemy::getSanityDam() {
    return sanityDamStat;
}

int Enemy::getLoot() {
    return loot;
}

bool Enemy::getIsDefeated() {
    return defeated;
}
