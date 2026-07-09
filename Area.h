// AREA class - Base Class, will house all infor/values for map locations and current exploration area.
#ifndef AREA_H
#define AREA_H


#include <string>
#include <vector>

using namespace std;

class Area {
    private:
        int currentLocationIndex; // integer map location
        string locationName; // location name
        string areaDescription; // brief description / flavor text
        bool areaUnlocked; // is area unlocked

    public:
        //contructor
        Area(int newCurrentLocationIndex, string newLocationName);

        //setters
        void setLocationIndex(int newCurrentLocationIndex); // set location integer
        void setLocationName(string newLocationName); // set location string name
        void setAreaDescription(string newAreaDescription); // set area description
        void setAreaUnlocked(bool newAreaUnlocked); // set area lock/unlock


        //getters
        int getLocationIndex(); // get location integer value
        string getLocationName(); // get location name based on integer value
        string getAreaDescription(); // get area description
        bool getAreaUnlocked(); // get whether area unlocked or locked still
        
};
#endif