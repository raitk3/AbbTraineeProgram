#include <iostream>
#include <map>
#include <list>
#include <vector>

#include "my_library.h"

int main() {
    std::string number;
    std::cout << "Insert a number!\n";
    std::cin >> number;
    std::vector<std::string> combinations = generateWords(number);
    for (std::string &combination: combinations) {
        std::cout << combination << "\n";
    }
}
