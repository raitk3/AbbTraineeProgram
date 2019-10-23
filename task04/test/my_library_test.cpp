#include "space_add.h"

#include <gtest/gtest.h>

TEST(SpaceAdd, givenNumber_callingSpaceAdd_mustReturnInputSeparatedWith5Spaces) {
    // ARRANGE
    std::string input = "12345";
    std::string input2 = "1";

    // ACT
    std::string result = spaceAdd(input);
    std::string result2 = spaceAdd(input2);

    // ASSERT
    ASSERT_EQ(result, "1     2     3     4     5");
    ASSERT_EQ(result2, "1");
}
