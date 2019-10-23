#include <iostream>

#include "string_manip.h"
#include "ask_input.h"

int main() {
    auto [initialWord, word] = askInput();
    //Check.
    if (checkPalindrome(word)) {
        std::cout << initialWord << " is a palindrome." << "\n";
    } else {
        std::cout << initialWord << " is not a palindrome." << "\n";
    }
}
