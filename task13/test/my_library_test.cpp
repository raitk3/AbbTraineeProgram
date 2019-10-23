#include "reverse.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenString_callingReverse_mustReturnWordReversed) {
    // ARRANGE
    std::string input = "Fawkd";

    // ACT
    std::string result = reverse(input);

    // ASSERT
    ASSERT_EQ(result, "dkwaF");
}
