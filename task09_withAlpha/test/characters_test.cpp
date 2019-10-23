#include "characters.h"

#include <gtest/gtest.h>


TEST (characters, givenChar_callinReturnRow_mustReturnCertainRowOfTheChar) {
    char input = 52; // 4
    int row = 4;

    std::string result = returnRow(row, input);

    ASSERT_EQ(result, "*  * ");
}
TEST(characters, givenChar_callingCreateVector_mustReturnCharsInAsterisks) {
    // ARRANGE
    std::string input = "A";
    std::vector<std::string> expectedResult1 = {
        " ***  ",
        "*   * ",
        "*   * ",
        "***** ",
        "*   * ",
        "*   * ",
        "*   * ",
        "      ",
        "      "
    };
    std::string input2 = "p";
    std::vector<std::string> expectedResult2 {
        "      ",
        "      ",
        "****  ",
        "*   * ",
        "*   * ",
        "*   * ",
        "****  ",
        "*     ",
        "*     "
    };
    std::string input3 = "0";
    std::vector<std::string> expectedResult3 = {
        " ***  ",
        "*   * ",
        "*  ** ",
        "* * * ",
        "**  * ",
        "*   * ",
        " ***  ",
        "      ",
        "      "
    };

    // ACT
    std::vector<std::string> result = createVector(input);
    std::vector<std::string> result2 = createVector(input2);
    std::vector<std::string> result3 = createVector(input3);

    // ASSERT     //ToDo - split into vectors.
    ASSERT_EQ(result, expectedResult1);

    ASSERT_EQ(result2, expectedResult2);

    ASSERT_EQ(result3, expectedResult3);
    }

TEST(characters, givenChars_callingCreatePrint_mustReturnCharsInAsterisks) {
    std::string input = "0ARq";

    std::vector<std::string> result = createVector(input);
    std::vector<std::string> expected {
        " ***   ***  ****        ",
        "*   * *   * *   *       ",
        "*  ** *   * *   *  **** ",
        "* * * ***** ****  *   * ",
        "**  * *   * * *   *   * ",
        "*   * *   * *  *  *   * ",
        " ***  *   * *   *  **** ",
        "                      * ",
        "                      * "
    };

    ASSERT_EQ(result, expected);
}
