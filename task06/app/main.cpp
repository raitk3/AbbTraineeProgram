#include "char.h"

int main() {
    char input;
    std::cout << "Insert a letter!\n";
    std::cin >> input;
    std::cout << getLetters(input) << "\n";
}
