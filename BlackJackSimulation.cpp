#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Function: rollDice
// Simulates rolling a 14-sided die, returning a card value.
// Numbers 2-10 represent their face values, 11-13 represent Jack, Queen, King (all 10 points), and 14 represents Ace (11 points).
int rollDice() {
    int roll = rand() % 13 + 2;  // Generate a random number between 2 and 14
    // Map the roll result to card values
    return (roll >= 11) ? 10 : (roll == 14) ? 11 : roll;
}

// Function: playerTurn
// Handles the player's turn in the Blackjack game.
// Parameters:
// - money: The current balance of the player.
// - wager: The wager placed by the player in this round (passed by reference).
// - total: The player's total score from the rolls (passed by reference).
// - bust: Whether the player has busted (passed by reference).
// - houseRoll: The house's first visible roll.
void playerTurn(int& money, int& wager, int& total, bool& bust, int houseRoll) {
    // Input and validation for the player's wager
    do {
        cout << "Enter your wager (current balance: $" << money << "): ";
        cin >> wager;
    } while (wager <= 0 || wager > money);  // Ensure valid wager amount

    // Deduct the wager from the player's money
    money -= wager;

    // The player rolls two dice/cards
    total = rollDice() + rollDice();

    // Show the house's first card to the player
    cout << "House shows: " << houseRoll << endl;

    // Display the player's total
    cout << "Your total: " << total << endl;

    // Check if the player has an automatic blackjack (22 treated as blackjack)
    if (total == 22) {
        cout << "Blackjack!" << endl;
        return;
    }

    // Allow the player to hit or stand
    char choice;
    while (total < 21) {  // Only prompt if total is less than 21
        cout << "(h)it or (s)tand? ";
        cin >> choice;
        if (choice == 'h') {  // Player chooses to hit
            total += rollDice();
            cout << "New total: " << total << endl;

            // Check if the player has busted
            if (total > 21) {
                bust = true;
                cout << "You busted!" << endl;
                return;
            }
        }
        else {  // Player chooses to stand
            break;
        }
    }
}

// Function: houseTurn
// Handles the house's turn in the Blackjack game.
// The house must hit until their total is at least 17.
// Parameters:
// - total: The house's total score from the rolls (passed by reference).
// - bust: Whether the house has busted (passed by reference).
void houseTurn(int& total, bool& bust) {
    // House keeps hitting until total is at least 17
    while (total < 17) {
        total += rollDice();  // Add a new roll to the house's total
    }
    cout << "House total: " << total << endl;

    // Check if the house has busted
    if (total > 21) bust = true;
}

// Function: determineWinner
// Determines the outcome of the round and updates the player's money.
// Parameters:
// - playerTotal: The player's final total score.
// - houseTotal: The house's final total score.
// - wager: The player's wager for the round.
// - playerBust: Whether the player busted.
// - houseBust: Whether the house busted.
// - money: The player's balance of money (passed by reference).
void determineWinner(int playerTotal, int houseTotal, int wager, bool playerBust, bool houseBust, int& money) {
    // If the player busted, they lose the wager
    if (playerBust) {
        cout << "House wins! You lose the wager." << endl;
    }
    // If the house busted, the player wins and doubles their wager
    else if (houseBust) {
        money += 2 * wager;
        cout << "House busts! You win." << endl;
    }
    // If neither busted, compare the totals to determine the winner
    else if (playerTotal > houseTotal) {
        money += 2 * wager;  // Player wins and doubles the wager
        cout << "You win!" << endl;
    }
    else if (houseTotal > playerTotal) {
        cout << "House wins!" << endl;
    }
    else {
        // If it's a tie (push), return the player's wager without change
        money += wager;
        cout << "It's a push!" << endl;
    }
}

// Main function
// Handles the game loop, where rounds continue until the player either runs out of money or chooses to quit.
int main() {
    srand(time(0));  // Initialize random seed for random number generation

    int money = 500;  // Player starts with $500
    int playerWager, playerTotal, houseTotal;
    bool playerBust, houseBust;

    ofstream logFile("blackjack_log.txt");  // Create a log file to record game events

    // Game loop continues as long as the player has money
    while (money > 0) {
        playerBust = houseBust = false;  // Reset bust flags at the start of each round
        houseTotal = rollDice();  // The house's first card is rolled

        cout << "\nNew round starts!" << endl;

        // Handle the player's turn
        playerTurn(money, playerWager, playerTotal, playerBust, houseTotal);

        // If the player hasn't busted, proceed with the house's turn
        if (!playerBust) {
            houseTurn(houseTotal, houseBust);
        }

        // Determine the winner of the round and update the player's money
        determineWinner(playerTotal, houseTotal, playerWager, playerBust, houseBust, money);

        // Log the results of the round to the log file
        logFile << "Player total: " << playerTotal << ", House total: " << houseTotal << ", Final balance: $" << money << endl;

        // If the player runs out of money, end the game
        if (money <= 0) {
            cout << "You ran out of money!" << endl;
            break;
        }

        // Ask if the player wants to play another round
        char playAgain;
        cout << "Play another round? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') break;  // Exit the loop if the player chooses not to continue
    }

    // Log the final game outcome and close the log file
    logFile << "Game over. Final balance: $" << money << endl;
    logFile.close();

    // Display final balance and game over message
    cout << "Game over. Final balance: $" << money << endl;

    return 0;
}
