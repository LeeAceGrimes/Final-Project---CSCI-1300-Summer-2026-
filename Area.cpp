// AREA class - Base Class, will house all infor/values for map locations and current exploration area.
#include "Area.h"
#include "Character.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructor
Area::Area(int newCurrentLocationIndex, string newLocationName) {
    currentLocationIndex = newCurrentLocationIndex;
    locationName = newLocationName;

    areaDescription = "No description available."; //default description
    areaUnlocked = false; //default locked
}

//setters
void Area::setLocationIndex(int newCurrentLocationIndex) { // set location integer
    currentLocationIndex = newCurrentLocationIndex;
}

void Area::setLocationName(string newLocationName) { // set location string name
    locationName = newLocationName;
}

void Area::setAreaDescription(string newAreaDescription) { // set area description
    areaDescription = newAreaDescription;
}

void Area::setAreaUnlocked(bool newAreaUnlocked) { // set area lock/unlock
    areaUnlocked = newAreaUnlocked;
}


//getters
int Area::getLocationIndex() { // get location integer value
    return currentLocationIndex;
}

string Area::getLocationName() { // get location name based on integer value
    return locationName;
}

string Area::getAreaDescription() { // get area description
    return areaDescription;
}

bool Area::getAreaUnlocked() { // get whether area unlocked or locked still
    return areaUnlocked;
}