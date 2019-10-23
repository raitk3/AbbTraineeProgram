#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingSumOdd_mustReturnSumOfOddNumbersLessOrEqualOfNumber) {
    // ARRANGE
    int input = 6;
    int input2 = 12;
    int input3 = 2147483647;


    // ACT
    long long result = SumOdd(input);
    long long result2 = SumOdd(input2);
    long long result3 = SumOdd(input3);

    // ASSERT
    ASSERT_EQ(result, 9);
    ASSERT_EQ(result2, 36);
    ASSERT_EQ(result3, 1152921504606846976);
}
