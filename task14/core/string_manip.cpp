#include "string_manip.h"
#include <iostream>


// Convert string to lowercase.
std::string toLowerCase(const std::string &word) {
    char newChar;
    std::string lowerWord;
    for (char c:word) {
        newChar = static_cast<char>(std::tolower(c));
        lowerWord += newChar;
    }
    return lowerWord;
}

// Reverse the string.
std::string reverse(std::string word) {
    if (word.size() == 1) {
        return word;
    } else {
        return reverse(word.substr(1)) + word.substr(0, 1);
    }
}

// Check if given word is palindrome. -> Check if word is same as the same word reversed.
bool checkPalindrome(const std::string &word) {
    std::string wordReversed = reverse(word);
    return word == wordReversed;
}
