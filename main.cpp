#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <limits>    // for numeric_limits

int main() {
    // seed the RNG with current time so it's diff every run
    srand(static_cast<unsigned int>(time(nullptr)));

    const int MIN = 1;
    const int MAX = 100;
    const int MAX_ATTEMPTS = 10;

    // generate secret number in range [1, 100]
    int secret = (rand() % (MAX - MIN + 1)) + MIN;

    int guess      = 0;
    int attempts   = 0;
    bool won       = false;

    std::cout << "=== Number Guessing Game ===\n";
    std::cout << "Guess a number between " << MIN << " and " << MAX << "\n";
    std::cout << "You have " << MAX_ATTEMPTS << " attempts. GL HF!\n\n";

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Attempt " << (attempts + 1) << "/" << MAX_ATTEMPTS << " → ";
        std::cin >> guess;

        // handle bad input (letters, symbols, etc.)
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "bruh, enter a valid number\n";
            continue;
        }

        // validate range
        if (guess < MIN || guess > MAX) {
            std::cout << "Out of range! Enter between " << MIN << " and " << MAX << "\n";
            continue;
        }

        attempts++;

        if (guess == secret) {
            won = true;
            break;
        } else if (guess < secret) {
            std::cout << "Too low! Go higher.\n";
        } else {
            std::cout << "Too high! Chill out.\n";
        }

        int left = MAX_ATTEMPTS - attempts;
        if (left > 0)
            std::cout << left << " attempt(s) left\n\n";
    }

    // result
    if (won) {
        std::cout << "\nGG! You got it in " << attempts << " attempt(s)!\n";
    } else {
        std::cout << "\nL rn. The number was " << secret << ". Run it back!\n";
    }

    return 0;
}
