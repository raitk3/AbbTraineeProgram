#include <windows.h>
#include "characters.h"

int main() {
    std::string number;
    std::vector<std::string> text;
    std::cout << "Insert a message!\n";
    while (true) {
        std::getline(std::cin, number);
        system("cls");
        text = createVector(number);
        if (number == "0") std::cout << "Number of fucks Rait has to give:" << std::endl;
        for (auto el : text) {
            std::cout << el << std::endl;
        }
    }
}
