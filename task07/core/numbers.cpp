#include "numbers.h"

Status loopCheckInput(Values& values) {
    values.turnsTaken++;
    if (values.numberToGuess < values.number) {
        return Status::HIGH;
    } else if (values.numberToGuess > values.number) {
        return Status::LOW;
    } else {
        return Status::EQUAL;
    }
}

void gameLoop(Values& values) {
    do {
        std::cin >> values.number;
        values.status = loopCheckInput(values);
        switch (values.status) {
            case Status::LOW:
                std::cout << "Too low!" << std::endl;
                break;
            case Status::HIGH:
                std::cout << "Too high!" << std::endl;
                break;
            case Status::EQUAL:
                std::cout << "You've guessed it! Turns taken: " << values.turnsTaken << "." << std::endl;
        }
    } while (values.status != Status::EQUAL);
}

Values initialize() {
    Values values;
    // To make guessing easier.
    int MAX_NUMBER = 100;
    srand(time(NULL));
    values.numberToGuess = (std::rand() % MAX_NUMBER) + 1; // To avoid 0.
    return values;
}
