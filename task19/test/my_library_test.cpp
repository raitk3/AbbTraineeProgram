#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenString_callingParser_mustReturnTextParsedInMapsRowByRow) {
    // ARRANGE
    std::string input = "a,b,a\n"
                        "f,\"a,e\",n\n";
    int row_index = 0;
    int max = 0;
    std::map<int, std::vector<std::string>> expectedResult =
    {
        {0, {"a", "b", "a"}},
        {1, {"f", "a,e", "n"}}
    };

     // ACT
    std::map<int, std::vector<std::string>> result = parser(input, row_index, max);

    // ASSERT
    ASSERT_EQ(result, expectedResult);
}
