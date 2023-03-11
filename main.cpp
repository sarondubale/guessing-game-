#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    int minNumber, maxNumber, secretNumber, guess, tries;
    char difficulty;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Choose your difficulty level (E = Easy, M = Medium, H = Hard): ";
    cin >> difficulty;

    switch (difficulty) {
        case 'E':
            minNumber = 1;
            maxNumber = 10;
            break;
        case 'M':
            minNumber = 1;
            maxNumber = 100;
            break;
        case 'H':
            minNumber = 1;
            maxNumber = 1000;
            break;
        default:
            cout << "Invalid difficulty level. Please choose E, M, or H." << endl;
            return 0;
    }

    srand(time(NULL)); // initialize random seed
    secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber; // generate secret number within difficulty level range
    tries = 0;

    do {
        cout << "Enter your guess (between " << minNumber << " and " << maxNumber << "): ";
        if (!(cin >> guess)) { // check for invalid input
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (guess < minNumber || guess > maxNumber) { // check if guess is within difficulty level range
            cout << "Your guess is out of range. Please enter a number between " << minNumber << " and " << maxNumber << "." << endl;
            continue;
        }
        tries++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the secret number in " << tries << " tries." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}