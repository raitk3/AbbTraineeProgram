#pragma once

#include <iostream>
#include <string>
#define ALPHABET_SIZE 26
#define MINIMAL_UPPERCASE_NUMBER 65
#define MINIMAL_LOWERCASE_NUMBER 97
#define MAXIMUM_LOWERCASE_NUMBER 122

char nextLowerToLower(char input);

char nextUpperToUpper(char input);

char nextUpperToLower(char input);

char nextLowerToUpper(char input);

char getNextLetter (char input, int time);

std::string getLetters(char input);
