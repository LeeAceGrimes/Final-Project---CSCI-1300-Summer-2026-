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
void Area::setLocationIndex(int newCurrentLocationIndex) {
    currentLocationIndex = newCurrentLocationIndex;
}

void Area::setLocationName(string newLocationName) {
    locationName = newLocationName;
}

void Area::setAreaDescription(string newAreaDescription) {
    areaDescription = newAreaDescription;
}

void Area::setAreaUnlocked(bool newAreaUnlocked) {
    areaUnlocked = newAreaUnlocked;
}
