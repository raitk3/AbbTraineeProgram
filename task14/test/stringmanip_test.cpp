#include "string_manip.h"

#include <gtest/gtest.h>

TEST(StringManip, givenString_callingReverse_mustReturnReversedString) {
    // ARRANGE
    std::string input1 = "palindroom";
    std::string input2 = "PaPa";

    // ACT
    std::string result1 = reverse(input1);
    std::string result2 = reverse(input2);

    // ASSERT
    ASSERT_EQ(result1, "moordnilap");
    ASSERT_EQ(result2, "aPaP");
}

TEST(StringManip, givenString_callingToLowerCase_mustReturnLowerCaseString) {
    // ARRANGE
    std::string input1 = "AHHHHHHHH";
    std::string input2 = "PaPa";

    // ACT
    std::string result1 = toLowerCase(input1);
    std::string result2 = toLowerCase(input2);

    // ASSERT
    ASSERT_EQ(result1, "ahhhhhhhh");
    ASSERT_EQ(result2, "papa");
}

TEST(StringManip, givenString_callingCheckPalindrome_mustReturnIfPalindrome) {
    // ARRANGE
    std::string input1 = "palindroom";
    std::string input2 = "kook";

    // ACT
    bool result1 = checkPalindrome(input1);
    bool result2 = checkPalindrome(input2);

    // ASSERT
    ASSERT_EQ(result1, false);
    ASSERT_EQ(result2, true);
}
