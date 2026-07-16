//ITEM class - base class, will house collectibles for player as well as loot drops in item vector, Necessary for inventory.
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

using namespace std;

class Item {
    private:
        string itemName;
        string itemType;
        int itemValue;
        bool needForObj;

    public:
        //constructor
        Item(string newItemName, string newItemType, int newitemValue, bool newNeedForObj);

        //setters
        void setItemName(string newItemName); //set item name
        void setNewItemType(string newItemType); //set item type
        void setNewItemValue(int newItemValue); // set item value
        void setNewNeedForObj(bool newNeedForObj); // set required for objective

        //getters
        string getItemName(); //get item name string
        string getItemType(); // get item type string
        int getItemValue(); // get item value int
        bool getNeedForObj(); // get need for obj bool
};
#endif