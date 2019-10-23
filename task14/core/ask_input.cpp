#include "ask_input.h"
#include "string_manip.h"

std::pair<std::string, std::string> askInput() {
    std::string initialWord;
    std::string word;
    std::string caseSensitive = "n";
    std::cout << "Does case matter? [Y/n]\n";
    std::cin >> caseSensitive;
    if (toLowerCase(caseSensitive) != "y" && toLowerCase(caseSensitive) != "n") {
        std::cout << "That is a no then.\n";
    }
    std::cout << "Insert the word you'd like to check whether it's a palindrome or not!\n";
    std::cin >> initialWord;
    word = initialWord;
    //To lowercase if neccessary.
    if (toLowerCase(caseSensitive) != "y") {
        word = toLowerCase(word);
    }
    return std::make_pair(initialWord, word);
}
