/**
 * Guess the Number Game
 *
 * This program is a console-based game where the computer randomly selects a number
 * between 1 and 100, and the player attempts to guess it. The game provides feedback
 * on whether a guess is too high or too low, and continues until the correct number
 * is guessed. It also counts and displays the number of attempts taken to correctly
 * guess the number.
 *
 * Features:
 * - Random number generation
 * - Input validation
 * - Loop until correct guess
 * - Count number of attempts
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    int secretNumber, guess;
    int attemptCount = 0;
    bool isGuessed = false;

    // Initialize the random seed based on the current system time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random secret number between 1 and 100
    secretNumber = rand() % 100 + 1;

    cout << "Welcome to Guess the Number Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    // Game loop that continues until the number is correctly guessed
    while (!isGuessed) {
        cout << "Enter your guess: ";
        // Input validation to ensure the user enters a valid integer
        if (!(cin >> guess)) {
            cout << "Please enter valid numbers only." << endl;
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip to the next newline to ignore the rest of the incorrect input
            continue;
        }

        attemptCount++; // Increment the count of attempts with each guess

        // Check if the guess is correct, too high, or too low
        if (guess == secretNumber) {
            isGuessed = true; // End the loop if the guess is correct
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    // Congratulate the player and display the number of attempts taken
    cout << "Congratulations! You guessed the number in " << attemptCount << " attempts." << endl;

    return 0;
}
