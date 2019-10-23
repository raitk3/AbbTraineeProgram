#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingPrintCircle_mustReturnCircleWithGivenRadiusInAsterisks) {
    // ARRANGE
    int input = 4;
    int input2 = 0;

    // ACT
    std::string result = printCircle(input);
    std::string result2 = printCircle(input2);

    // ASSERT
    ASSERT_EQ(result, "  ***  \n"
                      " ***** \n"
                      "*******\n"
                      "*******\n"
                      "*******\n"
                      " ***** \n"
                      "  ***  \n");

    ASSERT_EQ(result2, "");
}
