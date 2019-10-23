#include "my_library.h"
#include <algorithm>


#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingGenerateWords_mustReturnPermutationsInAlphabbeticalOrder) {
    // ARRANGE
    std::string shortInput = "23";
    std::vector<std::string> shortAnswer {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };

    std::string input = "23456";

    std::string input2 = "7799";

    // ACT
    std::vector shortResult = generateWords(shortInput);

    std::vector result = generateWords(input);
    std::vector sorted = result;
    std::sort(sorted.begin(), sorted.end());

    std::vector result2 = generateWords(input2);
    std::vector sorted2 = result2;
    std::sort(sorted2.begin(), sorted2.end());

    // ASSERT
    ASSERT_EQ(shortResult, shortAnswer);

    ASSERT_EQ(result.size(), 243);
    ASSERT_EQ(result, sorted);

    ASSERT_EQ(result2.size(), 256);
    ASSERT_EQ(result2, sorted2);
}
