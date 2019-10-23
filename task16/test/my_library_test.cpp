#include "counter.h"

#include <gtest/gtest.h>

TEST(Counter, givenCharVector_callingGetCount_MustReturnNumberOfDifferentTypesOfChars) {
    // ARRANGE
    std::vector<char> input1 {65, 66, 97, 98, 99, 49, 95}; // A, B, a, b, c, 1, _
    std::vector<char> input2;
    // ACT
    std::tuple result1 = getCount(input1);
    std::tuple result2 = getCount(input2);
    // ASSERT
    ASSERT_EQ(result1, std::make_tuple(2, 3, 1, 1));
    ASSERT_EQ(result2, std::make_tuple(0, 0, 0, 0));
}
