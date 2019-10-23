#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingStringTriangle_TriangleSizeMustBeNumberOfRows) {

    // ARRANGE
    int input = 0;
    std::vector<std::string> expectedResult {};
    int input2 = 4;
    std::vector<std::string> expectedResult2 {
        "*",
        "* *",
        "* * *",
        "* * * *"
    };

    // ACT
    std::vector result = StringTriangle(input);
    std::vector result2 = StringTriangle(input2);

    // ASSERT
    ASSERT_EQ(result, expectedResult);
    ASSERT_EQ(result2, expectedResult2);
}
