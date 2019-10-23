#pragma once
enum Status {HIGH, LOW, EQUAL};
struct Values {
    int number = 0;
    int numberToGuess;
    int turnsTaken;
    Status status;
};
