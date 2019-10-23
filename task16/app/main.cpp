#include <iostream>
#include <fstream>
#include <string>

#include "file_read.h"
#include "counter.h"


int main() {
    std::vector<char> letters = getLetters();
    auto [upperCase, lowerCase, numbers, other] = getCount(letters);
    std::cout << "File contains:\n"
              << upperCase << " uppercase letters,\n"
              << lowerCase << " lowercase letters,\n"
              << numbers << " numbers and \n"
              << other << " other characters.\n";
}
