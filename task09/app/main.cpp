#include "characters.h"

int main() {
    std::string number;
    std::vector<std::string> text;
    std::cout << "Insert a message!\n";
    while (true) {
        std::getline(std::cin, number);
        text = createVector(number);
        for (auto el : text) {
            std::cout << el << std::endl;
        }
    }
}
