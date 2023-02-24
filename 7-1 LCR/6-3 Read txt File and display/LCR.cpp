//Left Center Right
//Developer: Dale Ayers
//In loving memory of my Late Grandmother Connie Miller; For all the games we played on holidays 
//and the fun we had. Gone but not forgotten.
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

// Constant values for the die faces
const int L = 1;
const int R = 2;
const int C = 3;
const int DOT = 4;

// Constant values for the number of chips and starting pot size
const int NUM_CHIPS_PER_PLAYER = 3;
const int STARTING_POT_SIZE = 0;
const int MAX_DICE_PER_PLAYER = 3;

// Function to print the rules from the text file
void printRules() {
    std::string line;
    std::ifstream rulesFile("LCR_Rules.txt");
    if (rulesFile.is_open()) {
        while (getline(rulesFile, line)) {
            std::cout << line << std::endl;
        }
        rulesFile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
}

// Function to get the number of players from the user
int getNumPlayers() {
    int numPlayers;
    std::cout << "Enter the number of players (minimum 3): ";
    std::cin >> numPlayers;
    while (numPlayers < 3) {
        std::cout << "Invalid number of players. Please enter at least 3: ";
        std::cin >> numPlayers;
    }
    return numPlayers;
}

// Function to get the names of all the players from the user
std::vector<std::string> getPlayerNames(int numPlayers) {
    std::vector<std::string> playerNames(numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        std::cout << "Enter the name of player " << i + 1 << ": ";
        std::cin >> playerNames[i];
    }
    return playerNames;
}

// Function to roll a die and return the result
// Function to roll a die and return the result
int rollDie() {
    int result = rand() % 6 + 1;
    if (result == 1) {
        return L;
    }
    else if (result == 2) {
        return R;
    }
    else if (result == 3) {
        return DOT;
    }
    else if (result == 4) {
        return C;
    }
    else if (result == 5) {
        return DOT;
    }
    else {
        return DOT;
    }
}

// Function to play one round of the game
void playRound(std::vector<int>& playerChips, int& potSize, int currentPlayer, const std::vector<std::string>& playerNames) {
    int numDiceToRoll = std::min(playerChips[currentPlayer], MAX_DICE_PER_PLAYER);
    if (numDiceToRoll == 0) {
        std::cout << playerNames[currentPlayer] << " has no chips and cannot play." << std::endl;
       
    }
    std::cout << playerNames[currentPlayer] << ", press r to roll the dice... ";
    char rollChar;
    std::cin >> rollChar;
    if (rollChar != 'r') {
        std::cout << "Invalid input. Skipping turn." << std::endl;
        return;
    }
    std::cout << std::endl << playerNames[currentPlayer] << " is rolling " << numDiceToRoll << " dice..." << std::endl;
    int numChipsToPass = 0;
    for (int i = 0; i < numDiceToRoll; i++) {
        int rollResult = rollDie();
        if (rollResult == L) {
            std::cout << " Left." << std::endl;
            playerChips[currentPlayer]--;
            if (currentPlayer == 0) {
                playerChips[playerChips.size() - 1]++;
            }
            else {
                playerChips[currentPlayer - 1]++;
            }
        }
        else if (rollResult == R) {
            std::cout << " Right." << std::endl;
            playerChips[currentPlayer]--;
            if (currentPlayer == playerChips.size() - 1) {
                playerChips[0]++;
            }
            else {
                playerChips[currentPlayer + 1]++;
            }
        }
        else if (rollResult == C) {
            std::cout << " Center." << std::endl;
            playerChips[currentPlayer]--;
            potSize += 1;
            //std::cout << "Pot size: " << potSize << std::endl;
        }
        else {
            std::cout << " Dot.(Keep)" << std::endl;
        }
    }
    if (playerChips[currentPlayer] == 0) {
        std::cout << playerNames[currentPlayer] << " has no chips left." << std::endl;
        
    }
    if (potSize > 0) {
        numChipsToPass = std::min(playerChips[currentPlayer], potSize);
        std::cout << playerNames[currentPlayer] << ", you must pass " << numChipsToPass << " chip(s) to the pot." << std::endl;
        playerChips[currentPlayer] -= numChipsToPass;
        //potSize += numChipsToPass;
    }
    else {
        std::cout << "The pot is empty." << std::endl;
    }

    std::cout << "Current chip counts:" << std::endl;
    for (int i = 0; i < playerChips.size(); i++) {
        std::cout << playerNames[i] << ": " << playerChips[i] << " Chips" << std::endl;
        
    }
    std::cout << "Pot Size: " << potSize << std::endl;
    std::cout << playerNames[currentPlayer] << " passed " << numChipsToPass << " chips." << std::endl;
}

// Function to check if the game has ended
bool isGameOver(const std::vector<int>& playerChips) {
    int numPlayersWithChips = 0;
    for (int i = 0; i < playerChips.size(); i++) {
        if (playerChips[i] > 0) {
            numPlayersWithChips++;
        }
    }
    return numPlayersWithChips == 1;
}

// Function to print the winner of the game
void printWinner(const std::vector<int>& playerChips, const std::vector<std::string>
    & playerNames) {
    for (int i = 0; i < playerChips.size(); i++) {
        if (playerChips[i] > 0) {
            std::cout << playerNames[i] << " wins with " << playerChips[i] << " chips!" << std::endl;
            break;
        }
    }
}

// Main function
int main() {
    // Print the rules of the game
    printRules();

    // Seed the random number generator
    srand(time(0));

    // Get the number of players from the user
    int numPlayers = getNumPlayers();

    // Get the names of all the players from the user
    std::vector<std::string> playerNames = getPlayerNames(numPlayers);

    // Initialize the player chips and pot size
    std::vector<int> playerChips(numPlayers, NUM_CHIPS_PER_PLAYER);
    int potSize = STARTING_POT_SIZE;

    // Play rounds of the game until it ends
    int currentPlayer = 0;
    while (!isGameOver(playerChips)) {
        playRound(playerChips, potSize, currentPlayer, playerNames);
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }

    // Print the winner of the game
    printWinner(playerChips, playerNames);

    return 0;
}

