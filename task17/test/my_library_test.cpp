#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingSwitchLines_mustReturnVectorOfSwitchedLines) {
    // ARRANGE
    std::vector<std::string> lines = {"1", "2", "3"};
    std::vector<std::string> switchedLines = {"2", "1", "3"};

    std::vector<std::string> lines2 = {"1", "2", "3", "4"};
    std::vector<std::string> switchedLines2 = {"2", "1", "4", "3"};

    // ACT
    std::vector<std::string> result = switchLines(lines);
    std::vector<std::string> result2 = switchLines(lines2);

    // ASSERT
    ASSERT_EQ(switchedLines, result);
    ASSERT_EQ(switchedLines2, result2);

}
