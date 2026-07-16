//ITEM class - base class, will house collectibles for player as well as loot drops in item vector, Necessary for inventory.
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructor
Item::Item(string newItemName, string newItemType, int newItemValue, bool newNeedForObj) {
    itemName = newItemName;
    itemType = newItemType;
    itemValue = newItemValue;
    needForObj = newNeedForObj;
}

//setters
void Item::setItemName(string newItemName) { //set item name
    itemName = newItemName;
}

void Item::setNewItemType(string newItemType) { //set item type
    itemType = newItemType;
}

void Item::setNewItemValue(int newItemValue) { // set item value
    itemValue = newItemValue;
}

void Item::setNewNeedForObj(bool newNeedForObj) { // set required for objective
    needForObj = newNeedForObj;
}

//getters
string Item::getItemName() { //get item name string
    return itemName;
}
string Item::getItemType() { // get item type string
    return itemType;
}
int Item::getItemValue() { // get item value int
    return itemValue;
}
bool Item::getNeedForObj() { // get need for obj bool
    return needForObj;
}