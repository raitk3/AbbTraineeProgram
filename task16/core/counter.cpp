#include "counter.h"
#include <iostream>

std::tuple<int, int, int, int> getCount(std::vector<char> chars) {
    int upperCase = 0;
    int lowerCase = 0;
    int numbers = 0;
    int other = 0;
    for (char ch : chars) {
        if (UPPER_LOW <= ch && ch <= UPPER_HIGH) {
            upperCase++;
        } else if (LOWER_LOW <= ch && ch <= LOWER_HIGH) {
            lowerCase++;
        } else if (NUM_LOW <= ch && ch <= NUM_HIGH) {
            numbers++;
        } else {
        other ++;
        }
    }
    return std::make_tuple(upperCase, lowerCase, numbers, other);
}
