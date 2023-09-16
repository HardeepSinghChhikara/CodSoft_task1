#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    srand(time(0)); // Seed for random number generation

    int secretNumber = rand() % 100 + 1; // Generates a random number between 1 and 100

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100. Try to guess it." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear input buffer to handle non-integer input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid number." << std::endl;
            continue;
        }

        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}
