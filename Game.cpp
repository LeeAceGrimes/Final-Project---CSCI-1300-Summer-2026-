// GAME CLASS - controls all actions of the game, master class for game mechanics and game loop
#include "Game.h"
#include "Area.h" //including all files for game controller class, already included in game.h file
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream> // included libraries agin just in case, already included in game.h file
#include <string>
#include <vector>

using namespace std;

//constructor
Game::Game(int newDay, int newTime, bool newRunning, int newCurrentLocationIndex) 
    : player(100, 130, 0) { // 100 gold 130 sanity 0 index position is guild hall
    
        day = newDay; //set day
        time = newTime; //set time
        running = newRunning; //set running
        currentLocationIndex = newCurrentLocationIndex; //set local location index

        //add area object to area vector // did not push description into each location. !!!!!!!!!!!!!!!! FIXED
        areas.push_back(Area(0, "Guild Hall")); // 0 = Guild Hall
        areas[0].setAreaDescription("The Hall of Conquest, the most prominent Guild Hall in the region, a mere shell of it's former Glory. Now willing to offer jobs to even the craziest of Adventurers.");
        areas[0].setAreaUnlocked(true); // STARTING ZONE (set to unlock for demo purposes)

        areas.push_back(Area(1, "Whispered Forest")); // 1 = Forest
        areas[1].setAreaDescription("A Large Forest seemingly ordinary on the outside, however rumors tell of a constant whispering near dusk. The area has since been overwhelmed by monsters.");
        areas[1].setAreaUnlocked(true); //set to unlocked for demo purposes

        areas.push_back(Area(2, "Underbelly")); // 2 = underbelly
        areas[2].setAreaDescription("The deep Underbelly of the local town. Recent monster attacks have driven most criminal organizations underground. What can be found?");
        areas[2].setAreaUnlocked(true); //set to unlocked for demo purposes

        areas.push_back(Area(3, "Porcelain Fortress")); // 3 = fortress
        areas[3].setAreaDescription("A magnificent fortress that once radiated glory across the region. Since then the shine has become quite dull, what happened at the Fortress?");
        areas[3].setAreaUnlocked(true); // set to unlocked for 

        //add enemy object to enemy vector
        enemies.push_back(Enemy(3, 2, 8, 1));
        enemies.push_back(Enemy(3, 2, 8, 1));
        enemies.push_back(Enemy(3, 2, 8, 1)); // x3 simple mobs

        enemies.push_back(Enemy(5, 2, 15, 2)); 
        enemies.push_back(Enemy(5, 2, 15, 2));
        enemies.push_back(Enemy(5, 2, 15, 2)); // x3 normal mobs

        enemies.push_back(Enemy(10, 5, 100, 3)); // mini-boss
}

//setters
void Game::startGame() { // start game method
    while(running == true) { //while program running
        displayMenu();
        processMenuChoice(); 
    }
}

void Game::displayMenu() { // display menu formatting - purely text
    cout << endl; //add space for better formatting between output
    cout << "------------------------------" << endl;
    cout << "          Main Menu           " << endl;
    cout << "------------------------------" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Quit Game" << endl;
    cout << "------------------------------" << endl;
    cout << "Select an option (1-3): " << endl;
}

void Game::processMenuChoice(){ // recieve player input perform action associated
    int menuChoice = 0;
    cin >> menuChoice;

    if(menuChoice == 1) { //start game upon selecting option 1 // maybe loop while running true????????
        while(running) {
        displayDash(); //display dashboard
        processDashChoice(); // prompt user for input
        }
    }
    else if(menuChoice == 2) { //place holder Instructions -- if all three are if statements they are independent if followed by else if is interconnected
        cout << "Terminal text adventure game, respond to the on-screen prompts and select your action via the respective integer!" << endl;
    }
    else if(menuChoice == 3) {
        endGame(); // sets running to false - terminates program
    }
    else{
        cout << "Invalid Selection, please choose from the availble options." << endl; // default invalid selection option
    }
}

void Game::displayDash() { // displays dashboard ---- add additional functions such as companion and combat for user here!
    cout << endl;
    cout << "------------------------------" << endl;
    cout << "          Dashboard           " << endl;
    cout << "------------------------------" << endl;
    cout << "Day: " << getDay() << endl; //current day
    cout << "Time: " << getTime() << endl; //current time
    cout << "Location: " << areas[currentLocationIndex].getLocationName() << " (" << currentLocationIndex << ")" << endl; // player location //replacing with area call for location instead of player?
    cout << "Gold: " << player.getGold() << endl;
    cout << "Sanity: " << player.getSanity() << endl;
    cout << "------------Actions-----------" << endl;
    cout << "1. Travel" << endl;
    cout << "2. View Player Information" << endl;
    cout << "3. Current Area" << endl;
    cout << "4. View Nearby Enemies" << endl;
    cout << "5. End Game" << endl; // later save function for reaccess
    cout << "Select an Option (1-5): " << endl;
}

void Game::processDashChoice() { // process dash choices for player!
    int dashChoice = 0;
    cin >> dashChoice;

    if(dashChoice == 1) {
        travel(); // travel option for player
    }
    else if(dashChoice == 2) {
        player.displayPlayerStats(); // display player stats using display players stats player function
    }
    else if(dashChoice == 3) {
        displayCurrentArea(); // double back on this
    }
    else if(dashChoice == 4) {
        displayEnemies(); // display enemies
    }
    else if(dashChoice == 5) {
        endGame(); // end game
    }
    else {
       cout << "Invalid Selection, please choose from the availble options." << endl; // default invalid selection option  
    }
}

void Game::travel() { // travel action to move location
    int newLocation = 0;
    for(size_t i = 0; i < areas.size(); i++) { // reformat for better visual?????????? //didn't intitialize i
        cout << areas[i].getLocationIndex() << ". " << areas[i].getLocationName() << " " << endl; // No i + 1 needed since using 0, probably the best decision made so far
    }

    cout << "Select Travel Destination: ";
    cin >> newLocation;
    

    if(newLocation >= 0 && newLocation < static_cast<int>(areas.size())) { // newlocation will always be greater than 0 & less than VALIDATION //SIZE_T instead of INT here??????? COMPILES!
        if(areas[newLocation].getAreaUnlocked()) { //check unlocked or locked by function

            currentLocationIndex = newLocation;
            player.moveLocation(newLocation);

            cout << "Now arriving at " << areas[currentLocationIndex].getLocationName() << " (" << currentLocationIndex << ")" << endl; // print location name from areas vector object currentLocation index, followed by index
        }
        else {
            cout << "That area is currently locked." << endl;
        }
    }

    else {
        cout << "That destination does not exist." << endl;
    }
    
} //bracket confusion oin fgoqewrngvqowE'AIRSFNGVqwao'srgvfnm !!!!!!!!!!!!!

void Game::displayCurrentArea() { // displays current active area
    cout << endl;
    cout << "Current Area Index: " << areas[currentLocationIndex].getLocationIndex() << endl;  //access areas vector at current location index, print 
    cout << "Current Area Name: " << areas[currentLocationIndex].getLocationName() << endl; // cout location name
    cout << "Description: " << areas[currentLocationIndex].getAreaDescription() << endl; // area description
}

void Game::displayEnemies() { // displays total enemies in area
    int enemyCount = 0; //total nearby enemy count
    for(size_t i = 0; i < enemies.size(); i++) { //scan array
        if(enemies[i].getEnemyLocationIndex() == currentLocationIndex) { //if enemy area matches current location
            enemyCount++; // add enemy to count
            enemies[i].displayEnemy(); // display enemy details
        }
    }
    if(enemyCount > 0){
        cout << "There are " << enemyCount << " Enemies in this Area." << endl; // cout total enemy count nearby for user if enemy count > 0
    }
    else {
        cout << "No Enemies in this area." << endl; // default is 0 enemies nearby
    }
}

void Game::endGame() { // ends game
    running = false; //switch running variable to false.
}


//getters
int Game::getDay() { //get day
    return day;
}

int Game::getTime() { //get time
    return time;
}

bool Game::getRunning() { //get running confirmation
    return running;
}

//include time logic for day and clock cycles