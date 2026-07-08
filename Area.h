// AREA class - Base Class, will house all infor/values for map locations and current exploration area.
#ifndef AREA_H
#define AREA_H


#include <string>
#include <vector>

using namespace std;

class Area {
    private:
        int locationPOS; // integer map location
        string locationName; // location name
        string areaDescription; // brief description / flavor text
        bool areaUnlocked; // is area unlocked

    public:
        //contructor
        Area(int locPOS, string locName);
        //setters
        int setLocationPOS(int newLocationPOS); // set location position integer
        string setLocationName(string setLocationName); // set location string name
        string setAreaDescription(string newAreaDescription); // set area description
        bool setAreaUnlocked(bool newAreaUnlocked); // set area lock/unlock


        //getters
        int getLocationPOS(); // get location integer value
        string getLocationName(); // get location name based on integer value
        string getAreaDescription(); // get area description
        bool getAreaUnlocked(); // get whether area unlocked or locked still
};
#endif