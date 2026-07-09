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

        //add area object to area vector
        areas.push_back(Area(0, "Guild Hall")); // 0 = Guild Hall
        areas[0].setAreaUnlocked(true); // STARTING ZONE (set to unlock for demo purposes)

        areas.push_back(Area(1, "Whispered Forest")); // 1 = Forest
        areas[1].setAreaUnlocked(true); //set to unlocked for demo purposes

        areas.push_back(Area(2, "Underbelly")); // 2 = underbelly
        areas[2].setAreaUnlocked(true); //set to unlocked for demo purposes

        areas.push_back(Area(3, "Porcelain Fortress")); // 3 = fortress

        //add enemy object to enemy vector
        enemies.push_back(Enemy(3, 2, 8, 1));
        enemies.push_back(Enemy(3, 2, 8, 1));
        enemies.push_back(Enemy(3, 2, 8, 1)); // x3 simple mobs

        enemies.push_back(Enemy(5, 2, 15, 2)); 
        enemies.push_back(Enemy(5, 2, 15, 2));
        enemies.push_back(Enemy(5, 2, 15, 2)); // x3 normal mobs

        enemies.push_back(Enemy(10, 5, 100, 2)); // mini-boss
}

//setters
void Game::startGame() { // start game method
    while(running == true) {
        displayMenu();
        processMenuChoice();
    }
}

void Game::processMenuChoice(){ // recieve player input perform action associated
    int choice;
    if(choice == 1) {
        displayMenu()
    }
    if(choice == 2) {
        //show instructions
    }
    if(choice == 3) {
        //terminate program
    }
    else{
        cout << "Invalid Selection, please choose from the availble options." << endl;
    }
}

void Game::displayDash() { // displays dashboard


}

void Game::processDashChoice() {
    
}

void Game::displayMenu() { //display menu formatting
    cout << "------------------------------" << endl;
    cout << "          Main Menu           " << endl;
    cout << "------------------------------" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Quit Game" << endl;
    cout << "------------------------------" << endl;
    cout << "Select an option (1-3): " << endl;
}

void Game::displayCurrentArea() { // displays current active area


}

void Game::displayEnemies() { // displays enemies in area
    int enemyCount = 0; //total nearby enemy count
    for(size_t i = 0; i < enemies.size(); i++) { //scan array
        if(enemies[i].getEnemyLocationIndex() == currentLocationIndex) { //if enemy area matches current location
            enemyCount++; // add enemy to count
            enemies[i].displayEnemy(); // display enemy details
        }
    }
    if(enemyCount > 0){
        cout << "There are " << enemyCount << "in this Area." << endl; // cout total enemy count nearby for user if enemy count > 0
    }
    else {
        cout << "No Enemies in this area." << endl; // default is 0 enemies nearby
    }
}


void Game::travel() { // trave action to move location

}

void Game::endGame() { // ends game
    running = false;

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
