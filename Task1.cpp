#include <iostream>
#include <cstdlib> 
#include <ctime>   

int main() {
    // random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int userguess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Try to guess the number between 1 and 100.\n\n";
    std::cout << "*************************************************\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userguess;

        // Inc number of attempts
        attempts++;

        if (userguess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        } else if (userguess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }

    } while (userguess != secretNumber);

    return 0;
}

