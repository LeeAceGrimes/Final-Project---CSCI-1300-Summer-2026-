#include "Character.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Character::Character(string newName, string newInfo) {
    if(newName == "") {
        name = "Hollowed"; // default name if no input
    }
    else {
        name = newName; // user input name
    }
    if(newInfo == "") {
        information = "No record remains of this individual's past."; //defaul information
    }
    else {
        information = newInfo;
    }
    //initiazlize default starting values
    levelStat = 1;
    healthStat = 100;
    attackStat = 10;
}


// setter functions for character
void Character::setName(string newName) {
    name = newName;
}
void Character::setHealth(int newHealthStat) {
    healthStat = newHealthStat;
}
void Character::setAttack(int newAttackStat) {
    attackStat = newAttackStat;
}
void Character::setInfo(string newInformation) {
    information = newInformation;
}
void Character::setLevelStat(int newLevelStat) {
    levelStat = newLevelStat;
}




//getter functions defined
string Character::getName() {
    return name;
}
int Character::getHealth() {
    return healthStat;
}
int Character::getLevelStat() {
    return levelStat;
}
int Character::getAttack() {
    return attackStat;
}
string Character::getInfo() {
    return information;
}

