#include "conversions.h"
#include "my_library.h"

int main() {
    int numberToConvert;
    while (true) {
        std::cout << "Enter the number to convert:\n";
        std::cin >> numberToConvert;
        std::cout << convert(numberToConvert) << "\n";
    }
}
