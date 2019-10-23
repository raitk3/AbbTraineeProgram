#include "conversions.h"
#include <iostream>

std::string convertToHex(int input) {
    static char hex [31];
    std::sprintf(hex, "%x", input);
    return hex;
}

std::string convertToBin(int input) {
    std::bitset binary = std::bitset< 31 >( static_cast<unsigned long>(input) );
    std::string binText = binary.to_string();
    // Cut leading zeros.
    while(binText.substr(0, 1) == "0") {
        binText = binText.substr(1);
    }
    return binText;
}
