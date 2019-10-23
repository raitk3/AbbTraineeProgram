#include "char.h"

char nextLowerToLower(char input) {
    // -1 -> next letter -(-1) = +1
    input -=MINIMAL_LOWERCASE_NUMBER - 1;
    input %= ALPHABET_SIZE;
    input += MINIMAL_LOWERCASE_NUMBER;
    return input;
}

char nextUpperToUpper(char input) {
    input -=MINIMAL_UPPERCASE_NUMBER - 1;
    input %= ALPHABET_SIZE;
    input += MINIMAL_UPPERCASE_NUMBER;
    return input;
}

char nextUpperToLower(char input) {
    input -= MINIMAL_UPPERCASE_NUMBER - 1;
    input %= ALPHABET_SIZE;
    input += MINIMAL_LOWERCASE_NUMBER;
    return input;
}

char nextLowerToUpper(char input) {
    input -= MINIMAL_LOWERCASE_NUMBER - 1;
    input %= ALPHABET_SIZE;
    input += MINIMAL_UPPERCASE_NUMBER;
    return input;
}

char getNextLetter (char input, int time) {
    if (time == 1) {
        if (input >= MINIMAL_LOWERCASE_NUMBER &&input <= MAXIMUM_LOWERCASE_NUMBER) {
            return nextLowerToLower(input);
        } else {
            return nextUpperToUpper(input);
        }
    } else {
        if (input >= MINIMAL_LOWERCASE_NUMBER &&input <= MAXIMUM_LOWERCASE_NUMBER) {
            return nextLowerToUpper(input);
        } else {
            return nextUpperToLower(input);
        }
    }
}

std::string getLetters(char input) {
    std::string nextLetters;
    for (int i = 1; i <= 10; i++) {
        input = getNextLetter(input, i);
        nextLetters += input;
    }
    return nextLetters;
}
