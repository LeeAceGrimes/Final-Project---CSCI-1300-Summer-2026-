//Player.cpp file
#include "Player.h" //include header files
#include "Character.h"

#include <iostream> // include libraries double tap
#include <string>
#include <vector>

using namespace std;
   
Player::Player(int g, int s, int cL) //constructor
    : Character("Adventurer", "A new adventurer arrives in Moonveil. What adventures await?") // Character constructor for default values missing from Player - name, description
{
    gold = g; //set private variable to pass by value
    sanity = s;
    currentLocation = cL; //currently using cl may use currentLocationIndex same as other files.!!!!!!!!!!!!!!!!!!!!!!!
}

//setters
void Player::setGold(int newGold) { //exchange old value for new value for following 3 setter functions
    gold = newGold;
}

void Player::setSanity(int newSanity) {
    sanity = newSanity;
}

void Player::moveLocation(int newLocation) {
    currentLocation = newLocation;
}

//getters

int Player::getGold() { //getters return private variable values
    return gold;
}

int Player::getSanity() {
    return sanity;
}

int Player::getCL() {
    return currentLocation;
}

void Player::displayPlayerStats() { //display stats player inherits all getter/setter functions available to Character
    cout << endl; //extra line for better formatting
    cout << "Name: " << getName() << endl; //pure get name, no notation needed
    cout << "Info: " << getInfo() << endl;
    cout << "Level: " << getLevelStat() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << "Gold: " << getGold() << endl;
    cout << "Sanity: " << getSanity() << endl;
    cout << "Current Location: " << getCL() << endl; //replace with area control of position??????
}