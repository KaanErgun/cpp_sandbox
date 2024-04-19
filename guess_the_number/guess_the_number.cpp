#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    int secretNumber, guess;
    int attemptCount = 0;
    bool isGuessed = false;

    // Initialize random seed based on current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a secret number between 1 and 100
    secretNumber = rand() % 100 + 1;

    cout << "Welcome to Guess the Number Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    // Game loop
    while (!isGuessed) {
        cout << "Enter your guess: ";
        if (!(cin >> guess)) {
            cout << "Please enter valid numbers only." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore wrong input
            continue;
        }

        attemptCount++;

        if (guess == secretNumber) {
            isGuessed = true;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    cout << "Congratulations! You guessed the number in " << attemptCount << " attempts." << endl;

    return 0;
}
