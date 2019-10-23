#include "my_library.h"

#include <gtest/gtest.h>

int countStars (std::vector<std::vector<char>> map) {
    int sum = 0;
    for (std::vector<char> el: map) {
        for (char ela : el) {
            if (ela == FILLED_CELL) {
                sum ++;
            }
        }
    }
    return sum;
}


TEST(MyLibrary, givenSth_callingSth_mustReturnSth) {
    // ARRANGE
    int numberOfStars = 30;
    std::vector<std::vector<char>> map = addStars(mapGenerate(), numberOfStars);
    // ACT
    int count = countStars(map);
    // ASSERT
    ASSERT_EQ(numberOfStars, count);
}
