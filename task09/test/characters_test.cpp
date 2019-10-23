#include "characters.h"

#include <gtest/gtest.h>


TEST (characters, givenChar_callinReturnRow_mustReturnCertainRowOfTheChar) {
    char input = 52; // 4
    int row = 4;

    std::string result = returnRow(row, input);

    ASSERT_EQ(result, "*****");
}

TEST(characters, givenChars_callingCreatePrint_mustReturnCharsInAsterisks) {
    std::string input = "12";

    std::vector<std::string> result = createVector(input);
    std::vector<std::string> expected {
        "  *    *** ",
        " **   *   *",
        "* *       *",
        "  *      * ",
        "  *     *  ",
        "  *    *   ",
        "***** *****"
    };

    ASSERT_EQ(result, expected);
}
