#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * Game: Draw the last stick and lose.
 * Player vs. Computer.
 * Both can draw 1-3 sticks in a turn.
 * Computer tries to force the player to lose if possible (by leaving only 1 stick).
 * The first turn is decided by random selection.
 */

 // Struct to represent a player
struct Player {
    int choice;              // Number of sticks picked by the player
    int numberOfSticksTaken;  // Total sticks taken by the player
    double startValue;        // Value to decide who starts first
};

// Struct to represent the computer
struct Computer {
    int choice;              // Number of sticks picked by the computer
    int numberOfSticksTaken;  // Total sticks taken by the computer
    double startValue;        // Value to decide who starts first
};

// Function prototypes
void displayRules();              // Display game rules
void playGame(Player& player, Computer& computer);  // Main game loop
int computerNumber();             // Generate random choice for the computer
int getUserInput();               // Get valid input from the user (1-3 sticks)
bool decideFirstTurn();           // Randomly decide who starts first

int main() {
    Player player = { 0, 0, 0 };     // Initialize player struct
    Computer computer = { 0, 0, 0 }; // Initialize computer struct

    bool loop = true;
    while (loop) {
        std::cout << "Welcome to the game! " << std::endl
            << "1. Play Game" << std::endl
            << "2. Show Rules" << std::endl
            << "3. Exit" << std::endl;

        int userInput;
        std::cin >> userInput;

        switch (userInput) {
        case 1:
            if (decideFirstTurn()) {
                std::cout << "You start first!" << std::endl;
            }
            else {
                std::cout << "Computer starts first!" << std::endl;
            }
            playGame(player, computer); // Start the game
            break;
        case 2:
            displayRules();  // Show game rules
            break;
        case 3:
            loop = false;  // Exit game loop
            break;
        default:
            std::cout << "Please input a valid option! " << std::endl;
        }
    }
    return 0;
}

// Function to display the game rules
void displayRules() {
    std::cout << "The game is simple:" << std::endl
        << "1. There are 20 sticks." << std::endl
        << "2. Pick a number between 1-3 sticks." << std::endl
        << "3. If you pick the last stick, you lose." << std::endl;
}

// Function to get valid input from the user
int getUserInput() {
    int playerInput;
    while (true) {
        std::cin >> playerInput;
        if (playerInput >= 1 && playerInput <= 3) {
            return playerInput;
        }
        else {
            std::cout << "Invalid input, please pick a number between 1 and 3: ";
        }
    }
}

// Function to generate random choice (1-3) for the computer
int computerNumber() {
    return (rand() % 3) + 1;
}

// Function to randomly decide who starts first
bool decideFirstTurn() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    return rand() % 2 == 0;  // 50% chance to return true (player starts first)
}

// Main game loop
void playGame(Player& player, Computer& computer) {
    int numberOfSticks = 20;   // Total sticks in the game
    bool playerTurn = (player.startValue > computer.startValue);  // Determine who starts first

    while (numberOfSticks > 0) {
        if (playerTurn) {
            // Player's turn
            std::cout << "Pick an integer number between 1-3: ";
            player.choice = getUserInput();
            numberOfSticks -= player.choice;
            player.numberOfSticksTaken += player.choice;

            if (numberOfSticks <= 0) {
                std::cout << "You picked the last stick, you lost!" << std::endl;
                break;
            }
            std::cout << "Number of sticks remaining: " << numberOfSticks << std::endl;
        }
        else {
            // Computer's turn
            if (numberOfSticks >= 2 && numberOfSticks <= 4) {
                int n = numberOfSticks - 1;  // Force player to take the last stick
                computer.choice = n;
                numberOfSticks -= n;
                std::cout << "The computer picked " << computer.choice << " stick(s)." << std::endl;
            }
            else if (numberOfSticks <= 1) {
                std::cout << "The computer picked the last stick, you win!" << std::endl;
                break;
            }
            else {
                computer.choice = computerNumber();  // Random pick if not in winning position
                std::cout << "The computer picked " << computer.choice << " stick(s)." << std::endl;
                numberOfSticks -= computer.choice;
                computer.numberOfSticksTaken += computer.choice;
            }
        }
        playerTurn = !playerTurn;  // Switch turns
    }
}
