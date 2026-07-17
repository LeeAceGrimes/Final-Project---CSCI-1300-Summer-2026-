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

void Player::setSanity(int newSanity) { //come back to this mechanic!!!!!!!!!!!!
    sanity = newSanity;
}

void Player::moveLocation(int newLocation) {
    currentLocation = newLocation;
}


//player inventory setter
void Player::addItem(Item newItem) { // push new item into inventory vector
    inventory.push_back(newItem);
}

bool Player::removeItem(string itemName) { //probvably serves closer to a getter function, removal and adding are in setters for now. //remove item from vector
    for(size_t i = 0; i < inventory.size(); i++) {
        if(inventory[i].getItemName() == itemName) {
            inventory.erase(inventory.begin() + i); // .erase() function removes item @ index, specific opposite of push_back
            return true;
        }
    }
    return false;
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

    displayInventory(); // call inventory function to display inventory items
}

//player inventory getters
void Player::displayInventory() {
    if(inventory.size() == 0) { // if index size 0
        cout << "Inventory is empty." << endl; //empty inventory
    }
    else {
        cout << "----------Inventory----------" << endl; // header

        for(size_t i = 0; i < inventory.size(); i++) {
            cout << i + 1 << ". "; //numbering each new index
            cout << "Name: " << inventory[i].getItemName() << endl; // item name
            cout << "Type: " << inventory[i].getItemType() << endl; // item type
            cout << "Value: " << inventory[i].getItemValue() << endl; // item value
        }
    } 
}

bool Player::hasItem(string itemName) { // required item check for story progression
    for(size_t i = 0; i < inventory.size(); i++) { // scan vector
        if(inventory[i].getItemName() == itemName) { // get name == item name true otherwise false
            return true;
        }  
    }
    return false;
}

int Player::getInventorySize() { // inventory size total items
    return static_cast<int>(inventory.size()); // static cast size_t vector to int
}
