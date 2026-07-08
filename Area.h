// AREA class - Base Class, will house all infor/values for map locations and current exploration area.
#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <vector>

using namespace std;

class Area {
    private:
        int locationPOS;
        string locationName;
        string areaDescription;
        bool areaUnlocked;

    public:
        //contructor
        Area(int locPOS, string locName);
        //setters
        int setLocationPOS();
        string setLocationName();
        string setAreaDescription();
        bool setAreaUnlocked();


        //getters
        int getLocationPOS();
        string getLocationName();
        string getAreaDescription();
        bool getAreaUnlocked();
};
#endif