//Task13
#include <iostream>
#include "reverse.h"
#include <string>


int main() {
    std::string word;
    std::cout << "Insert the word you would like to reverse.\n";
    std::cin >> word;
    std::string reversed = reverse(word);
    std::cout << reversed << "\n";
}
