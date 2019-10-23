#include <limits.h>
#include "conversions.h"
#include "my_library.h"

#include <gtest/gtest.h>

TEST(Conversions, givenNumber_callingtoHex_mustReturnHexValue) {
    // ARRANGE
    int input = 10;
    int input2 = 255;
    int input3 = 2147483647;

    // ACT
    std::string result = convertToHex(input);
    std::string result2 = convertToHex(input2);
    std::string result3 = convertToHex(input3);

    // ASSERT
    ASSERT_EQ(result, "a");
    ASSERT_EQ(result2, "ff");
    ASSERT_EQ(result3, "7fffffff");
}

TEST (Conversions, givenNumber_callingToBin_musReturnBinValue) {
    // ARRANGE
    int input = 10;
    int input2 = 2147483647;

    // ACT
    std::string result = convertToBin(input);
    std::string result2 = convertToBin(input2);

    // ASSERT
    ASSERT_EQ(result, "1010");
    ASSERT_EQ(result2, "1111111111111111111111111111111");
}

TEST (convert, givenNumber_callingMainConvert_mustReturnStringWithValues) {
    int input1 = 12;
    int input2 = INT_MAX;

    std::string result1 = convert(input1);
    std::string result2 = convert(input2);

    ASSERT_EQ(result1, "For integer 12 result is c and 1100.");
    ASSERT_EQ(result2, "For integer 2147483647 result is 7fffffff and 1111111111111111111111111111111.");
}
