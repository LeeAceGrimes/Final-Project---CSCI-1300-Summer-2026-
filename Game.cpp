// GAME CLASS - controls all actions of the game, master class for game mechanics and game loop
#include "Game.h"
#include "Area.h" //including all files for game controller class, already included in game.h file
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

#include <iostream> // included libraries agin just in case, already included in game.h file
#include <string>
#include <vector>
#include <random>

using namespace std;

//constructor
Game::Game(int newDay, int newTime, bool newRunning, int newCurrentLocationIndex) 
    : player(100, 130, 0) { // 100 gold 130 sanity 0 index position is guild hall

        //player.displayInventory(); // Come back to this after fully stretching inventory
    
        day = newDay; //set day
        time = newTime; //set time
        running = newRunning; //set running
        currentLocationIndex = newCurrentLocationIndex; //set local location index

        //test quest prog
        //end test quest prog


        //END GAME Relic Progress (x5 Quests?)
        relicProgress = 0;

        guildEmblemDonated = false;
        whisperingBarkDonated = false;
        eldritchSilkDonated = false;
        underbellyKeyDonated = false;
        porcelainShardDonated = false;

        //add area object to area vector 
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

//game.h setters
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
    cout << "------------------------------" << endl;
    cout << "------------Actions-----------" << endl;
    cout << "------------------------------" << endl;
    cout << "1. Travel" << endl;
    cout << "2. Fight Nearby Enemies" << endl;
    cout << "3. View Player Information" << endl;
    cout << "4. Current Area" << endl;
    cout << "5. View Nearby Enemies" << endl;
    cout << "6. Donate Relic" << endl;
    cout << "7. End Game" << endl;
    cout << "------------------------------" << endl;
    cout << "Select an Option (1-7): " << endl;
}

void Game::processDashChoice() { // process dash choices for player!
    int dashChoice = 0;
    cin >> dashChoice;

    if(dashChoice == 1) {
        travel(); // travel option for player
    }
    else if(dashChoice == 2) {
        combat(); // combat
    }
    else if(dashChoice == 3) {
        player.displayPlayerStats(); // display player stats using display players stats player function
    }
    else if(dashChoice == 4) {
        displayCurrentArea(); // double back on this
    }
    else if(dashChoice == 5) {
        displayEnemies(); // display enemies
    }
    else if(dashChoice == 6) {
        donateRelic(); //donate relic
    }
    else if(dashChoice == 7) {
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
    
}

void Game::displayCurrentArea() { // displays current active area
    cout << endl;
    cout << "Current Area Index: " << areas[currentLocationIndex].getLocationIndex() << endl;  //access areas vector at current location index, print 
    cout << "Current Area Name: " << areas[currentLocationIndex].getLocationName() << endl; // cout location name
    cout << "Description: " << areas[currentLocationIndex].getAreaDescription() << endl; // area description
}

void Game::displayEnemies() { // displays total enemies in area
    int enemyCount = 0; //total nearby enemy count
    cout << endl;
    cout << "------------------------------" << endl; // enemies header
    cout << "------------Enemies-----------" << endl;
    cout << "------------------------------" << endl;

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


//game.h getters
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



//ENDGAME RELIC PROGRESS FUNCTIONS
void Game::displayObjective() { //display objectives
    //header
    cout << "------------------------------" << endl;
    cout << "-----------Objective----------" << endl;
    cout << "------------------------------" << endl;
    cout << "Progress: " << relicProgress << " / " << 5 << endl;
    cout << endl;
    // bool each relic print option for true/false
    if(guildEmblemDonated) {
        cout << "[Donated] [Guild Emblem]" << endl;
    }
    else{
        cout << "[Needed] [Guild Emblem]" << endl;
    }
    if(whisperingBarkDonated == true) {
        cout << "[Donated] [Whispering Bark]" << endl;
    }
    else{
        cout << "[Needed] [Whispering Bark]" << endl;
    }
    if(eldritchSilkDonated) {
        cout << "[Donated] [Eldritch Silk]" << endl;
    }
    else{
        cout << "[Needed] [Eldritch Silk]" << endl;
    }
    if(underbellyKeyDonated) {
        cout << "[Donated] [Underbelly Key]" << endl;
    }
    else{
        cout << "[Needed] [Underbelly Key]" << endl;
    }
    if(porcelainShardDonated) {
        cout << "[Donated] [Porcelain Shard]" << endl;
    }
    else{
        cout << "[Needed] [Porcelain Shard]" << endl;
    }
}

void Game::donateRelic() { //donate relic for objective progression
    int donateChoice = 0; //donate relic 0

    if(currentLocationIndex !=0) { //check location index, turn-ins must happen at starting guild hall
        cout << "Relics can only be donated at the Guild Hall!" << endl;
        return;
    }

    displayObjective(); // display objective
    player.displayInventory(); // display player inventory

    // output text
    cout << endl;
    cout << "Select a relic to donate: " << endl;
    cout << "1. [Guild Emblem]" << endl;
    cout << "2. [Whispering Bark]" << endl;
    cout << "3. [Eldritch Silk]" << endl;
    cout << "4. [Underbelly Key]" << endl;
    cout << "5. [Porcelain Shard]" << endl;
    cout << "6. Cancel" << endl;
    cout << "--------------------------" << endl;
    cout << "Select an option (1-6): ";
    cin >> donateChoice; // player choice

    //handle player donation input
    if(donateChoice == 1){ // 1-5 for relic to turn in #1
        if(guildEmblemDonated == true){ //if true do not recieve duplicate
            cout << endl;
            cout << "That Item has already been donated." << endl;
        }
        else if(player.hasItem("Guild Emblem")) { //if player has item
            player.removeItem("Guild Emblem"); // remove item from player inventory via name
            guildEmblemDonated = true; // set donation status to true
            relicProgress++; // +1 to relic progression count

            cout << "[Guild Emblem] donated!" << endl; // donate item
            displayObjective(); // return user to objective screen
            cout << endl;
        }
        else {
            cout << "You have not accquired the Guild Emblem." << endl; // Do not have item
        }

        if (checkWin()){ // check for win condition
        cout << "All five relics have been restored!" << endl;
        }
    }

    else if(donateChoice == 2){ // 1-5 for relic to turn in #2
        if(whisperingBarkDonated == true){ //if true do not recieve duplicate
            cout << endl;
            cout << "That Item has already been donated." << endl;
        }
        else if(player.hasItem("Whispering Bark")) { //if player has item
            player.removeItem("Whispering Bark"); // remove item from player inventory via name
            whisperingBarkDonated = true; // set donation status to true
            relicProgress++; // +1 to relic progression count

            cout << "[Whispering Bark] donated!" << endl; // donate item
            displayObjective(); // return user to objective screen
            cout << endl;
        }
        else {
            cout << "You have not accquired Whispering Bark." << endl; // Do not have item
        }

        if (checkWin()){ // check for win condition
        cout << "All five relics have been restored!" << endl;
        }
    }

    else if(donateChoice == 3){ // 1-5 for relic to turn in #3
        if(eldritchSilkDonated == true){ //if true do not recieve duplicate
            cout << endl;
            cout << "That Item has already been donated." << endl;
        }
        else if(player.hasItem("Eldritch Silk")) { //if player has item
            player.removeItem("Eldritch Silk"); // remove item from player inventory via name
            eldritchSilkDonated = true; // set donation status to true
            relicProgress++; // +1 to relic progression count

            cout << "[Eldritch Silk] donated!" << endl; // donate item
            displayObjective(); // return user to objective screen
            cout << endl;
        }
        else {
            cout << "You have not accquired Eldritch Silk." << endl; // Do not have item
        }

        if (checkWin()){ // check for win condition
        cout << "All five relics have been restored!" << endl;
        }
    }

    else if(donateChoice == 4){ // 1-5 for relic to turn in #4
        if(underbellyKeyDonated == true){ //if true do not recieve duplicate
            cout << endl;
            cout << "That Item has already been donated." << endl;
        }
        else if(player.hasItem("Underbelly Key")) { //if player has item
            player.removeItem("Underbelly Key"); // remove item from player inventory via name
            underbellyKeyDonated = true; // set donation status to true
            relicProgress++; // +1 to relic progression count

            cout << "[Underbelly Key] donated!" << endl; // donate item
            displayObjective(); // return user to objective screen
            cout << endl;
        }
        else {
            cout << "You have not accquired the Underbelly Key." << endl; // Do not have item
        }

        if (checkWin()){ // check for win condition
        cout << "All five relics have been restored!" << endl;
        }
    }

    else if(donateChoice == 5){ // 1-5 for relic to turn in #5
        if(porcelainShardDonated == true){ //if true do not recieve duplicate
            cout << endl;
            cout << "That Item has already been donated." << endl;
        }
        else if(player.hasItem("Porcelain Shard")) { //if player has item
            player.removeItem("Porcelain Shard"); // remove item from player inventory via name
            porcelainShardDonated = true; // set donation status to true
            relicProgress++; // +1 to relic progression count

            cout << "[Porcelain Shard] donated!" << endl; // donate item
            displayObjective(); // return user to objective screen
            cout << endl;

            if (checkWin()){ // check for win condition
            cout << "All five relics have been restored!" << endl;
            }
        }
        else {
            cout << "You have not accquired a Porcelain Shard." << endl; // Do not have item
        }
    }
    
    else if(donateChoice == 6) { // cancel operations
        cout << "Donation cancelled." << endl;
    }

    else{ // invaild input
        cout << "Invaild donation selection." << endl;
    }
}

bool Game::checkWin() { // game win condition turn in all 5 required items
    return relicProgress == 5;
}

void Game::combat() { // combat function -- targets first available enemy ADD TARGET SELECTION LATER!!!!!!!!!!!!!!
    int enemyIndex = -1; // default enemy index

    for(size_t i = 0; i < enemies.size(); i++){ //scan enemies locates first enemy
        if(enemies[i].getEnemyLocationIndex() == currentLocationIndex && enemies[i].getIsDefeated() == false) { // enemies at i location matches current plauyer location AND enemies defeated == false
            enemyIndex = static_cast<int>(i); //static cast since size t i in scan loop
            break; // break after saving first matching index
        }
    }
    if(enemyIndex == -1){
        cout << "There are no enemies to fight here." << endl;
    }
    else{
        enemies[enemyIndex].displayEnemy(); // display enemies

        //variables for combat user choice and fighting bool
        bool fighting = true;
        int combatChoice = 0;

        while(fighting && player.getHealth() > 0 && player.getSanity() > 0 && enemies[enemyIndex].getHealth() > 0) {
            //combat hud
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "-------------Combat-----------" << endl;
            cout << "------------------------------" << endl;
            cout << "Player Health: " << player.getHealth() << " HP" << endl;
            cout << "Player Sanity: " << player.getSanity() << " SP" << endl;
            cout << "Enemy Health: " << enemies[enemyIndex].getHealth() << " HP" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Retreat" << endl;
            cout << "------------------------------" << endl;
            cout << "Select an Option (1-2): " << endl;
            //user input stored in combat choice
            cin >> combatChoice;

            if(combatChoice == 1) { // PLAYER CHOOSES COMBAT
                int newEnemyHealth = enemies[enemyIndex].getHealth() - player.getAttack(); // COMBAT FORMULA
                enemies[enemyIndex].setHealth(newEnemyHealth); // set new enemy health

                if(enemies[enemyIndex].getHealth() <= 0) { // player defeats monster - VICTORY
                    enemies[enemyIndex].setHealth(0); // set enemy health
                    enemies[enemyIndex].setIsDefeated(true); // mob defeated
                    fighting = false; // stop fighting

                    cout << enemies[enemyIndex].getName() << " defeated!" << endl; // enemy defeated output

                    int newPlayerGold = player.getGold() + enemies[enemyIndex].getLoot(); // Loot drop add monster gold to player gold
                    player.setGold(newPlayerGold); // set player gold
                    cout << "You collected " << enemies[enemyIndex].getLoot() << " gold." << endl; // output for looted gold

                    rollRelicDrop(enemyIndex); // RELIC DROP CHANCE
                    respawnClearedArea(currentLocationIndex); // respawn mobs function after combat will activate once all mobs in area are cleared!

                }
                else{ // enemy retaliates
                    int newPlayerHealth = player.getHealth() - enemies[enemyIndex].getDam(); // enemy attacks player health
                    player.setHealth(newPlayerHealth); // set new health

                    if(player.getHealth() < 0) { // if player health reaches 0 - DEATH
                        player.setHealth(0); // set health to 0
                        cout << "Your health has reached 0 and you have fallen!" << endl; // Health Defeat
                    }
                    int newPlayerSanity = player.getSanity() - enemies[enemyIndex].getSanityDam(); // enemy attacks player sanity
                    player.setSanity(newPlayerSanity); // set new sanity

                    if(player.getSanity() < 0) { // if player sanity reaches 0 - DEATH
                        player.setSanity(0); // set sanity to 0
                        cout << "Your sanity has reached 0 and you have gone mad!" << endl; // Sanity Defeat
                    }
                }
            }
            else if(combatChoice == 2) { // PLAYER CHOOSES RETREAT
                fighting = false; // stop fighting
                enemies[enemyIndex].setHealth(100);
                cout << "You retreat from combat." << endl;
            }
            else {
                cout << "Invalid Selection" << endl; // invalid input
            }
        }
    }
}

void Game:: rollRelicDrop(int enemyIndex) { // roll drop chance, using random function. For duplicate drop protection manually code each item to a drop location
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> distribution(1, 100); // generate number from 1-100

    int dropRoll = distribution(generator);
    cout << "Loot Crit: " << dropRoll << endl;

    if(dropRoll > 70) { // if number is 71-100
        cout << "The Enemy dropped no Relic" << endl; // no relic
        return; // end function
    }
    int enemyLocation = enemies[enemyIndex].getEnemyLocationIndex(); // get enemy location

    if(enemyLocation == 1) { // LOCATION 1 RELIC -- WHISPERING FOREST
        if(whisperingBarkDonated == false && !player.hasItem("Whispering Bark")) { // Player has not donated AND player dows not have relic
            player.addItem(Item("Whispering Bark", "Relic", 100, true));
            cout << "The Enemy has dropped [Whispering Bark]!" << endl;
        }
        else if(eldritchSilkDonated == false && !player.hasItem("Eldritch Silk")) { // Player has not donated AND player dows not have relic
            player.addItem(Item("Eldritch Silk", "Relic", 100, true));
            cout << "The Enemy has dropped [Eldritch Silk]!" << endl;
        }
        else {
            cout << "No additional Relic required from Whispering Forest." << endl;
        }
    }

    if(enemyLocation == 2) { // LOCATION 2 RELIC -- UNDERBELLY
        if(underbellyKeyDonated == false && !player.hasItem("Underbelly Key")) { // Player has not donated AND player dows not have relic
            player.addItem(Item("Underbelly Key", "Relic", 100, true)); // create Relic
            cout << "The Enemy has dropped [Underbelly Key]!" << endl;
        }
        else {
            cout << "No additional Relic required from The Underbelly." << endl;
        }
    }
    if(enemyLocation == 3) { // LOCATION 3 RELIC -- PORCELAIN FORTRESS
        if(porcelainShardDonated == false && !player.hasItem("Porcelain Shard")) { // Player has not donated AND player dows not have relic
            player.addItem(Item("Porcelain Shard", "Relic", 100, true)); // create relic
            cout << "The Enemy has dropped [Porcelain Shard]!" << endl;
        }
        else {
            cout << "No additional Relic required from Porcelain Fortress." << endl;
        }
    }   
}

void Game::respawnClearedArea(int locationIndex) {
    bool areaHasEnemies = false; // confirm area has enemies set to false
    bool activeEnemyFound = false;

    for(size_t i = 0; i < enemies.size(); i++) {
        if(enemies[i].getEnemyLocationIndex() == locationIndex) { // check where enemy belongs to area checking
            areaHasEnemies = true; // set area enemies to true

            if(enemies[i].getIsDefeated() == false) { 
                activeEnemyFound = true;
            }
        }
    }

    if(areaHasEnemies == true && activeEnemyFound == false){
        for(size_t i = 0; i < enemies.size(); i++) {
            if(enemies[i].getEnemyLocationIndex() == locationIndex) {
                enemies[i].setIsDefeated(false);
                enemies[i].setHealth(100);

            }
        }
        cout << "The area has been cleared, but new enemies continue to appear!" << endl;
    }


}