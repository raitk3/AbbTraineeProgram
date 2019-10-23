#include "my_library.h"
#include <iostream>

std::string convert(int number) {
    return "For integer " + std::to_string(number) + " result is " + convertToHex(number) + " and " + convertToBin(number) + ".";
}
