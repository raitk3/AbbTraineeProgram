#include "char.h"

#include <gtest/gtest.h>

TEST(Char, givenNumber_callingLowToLow_mustReturnNextLowercaseLetter) {
    // ARRANGE
    char input = 104; // h
    char input2 = 122; // z

    // ACT
    char result = nextLowerToLower(input);
    char result2 = nextLowerToLower(input2);

    // ASSERT
    ASSERT_EQ(result, 105); // i
    ASSERT_EQ(result2, 97); // a
}

TEST(Char, givenNumber_callingUpToUp_mustReturnNextUppercaseLetter) {
    // ARRANGE
    char input = 72; // H
    char input2 = 90; // Z

    // ACT
    char result = nextUpperToUpper(input);
    char result2 = nextUpperToUpper(input2);

    // ASSERT
    ASSERT_EQ(result, 73); // I
    ASSERT_EQ(result2, 65); // A
}

TEST(Char, givenNumber_callingLowToUp_mustReturnNextUppercaseLetter) {
    // ARRANGE
    char input = 104; // h
    char input2 = 122; // z

    // ACT
    char result = nextLowerToUpper(input);
    char result2 = nextLowerToUpper(input2);

    // ASSERT
    ASSERT_EQ(result, 73); // I
    ASSERT_EQ(result2, 65); // A
}

TEST(Char, givenNumber_callingUpToLow_mustReturnNextLowercaseLetter) {
    // ARRANGE
    char input = 72; // H
    char input2 = 90; // Z

    // ACT
    char result = nextUpperToLower(input);
    char result2 = nextUpperToLower(input2);

    // ASSERT
    ASSERT_EQ(result, 105); // i
    ASSERT_EQ(result2, 97); // a
}

TEST (Char, givenCharAndTimeItsDone_mustReturnNextChar) {
    char input1 = 72; // H
    int time1 = 1;
    char input2 = 90; // Z
    int time2 = 2;

    char result1 = getNextLetter(input1, time1);
    char result2 = getNextLetter(input2, time2);

    ASSERT_EQ(result1, 73); // I
    ASSERT_EQ(result2, 97); // a
}

TEST (Char, givenChar_callingGetLetters_mustReturn10LettersAfterGivenInSwitchingCases) {
    char input1 = 97; // a
    char input2 = 122; // z
    char input3 = 75; // K
    char input4 = 86; // V

    std::string result1 = getLetters(input1);
    std::string result2 = getLetters(input2);
    std::string result3 = getLetters(input3);
    std::string result4 = getLetters(input4);

    ASSERT_EQ(result1, "bCdEfGhIjK");
    ASSERT_EQ(result2, "aBcDeFgHiJ");
    ASSERT_EQ(result3, "LmNoPqRsTu");
    ASSERT_EQ(result4, "WxYzAbCdEf");
}
