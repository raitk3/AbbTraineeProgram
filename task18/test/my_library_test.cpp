#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenText_callingGetText_mustReturnTextFromBeginToEndChar) {
    // ARRANGE
    std::string text = "InputText";
    char begin = 112; // p
    int length = 6;
    char end = 84; // T

    // ACT
    std::string result = get_text(text, begin, length, end);

    // ASSERT
    ASSERT_EQ(result, "putT");
}

TEST(MyLibrary, givenText_callingGetText_mustReturnTextFromBeginToLength) {
    // ARRANGE
    std::string text = "InputText";
    char begin = 112; // p
    int length = 5;
    char end = 120; // x

    // ACT
    std::string result = get_text(text, begin, length, end);

    // ASSERT
    ASSERT_EQ(result, "putTe");
}
