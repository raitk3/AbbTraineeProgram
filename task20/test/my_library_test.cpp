#include "my_library.h"

#include <gtest/gtest.h>

TEST(MyLibrary, giventext_callingParser_mustReturnCsvText) {
    // ARRANGE
    std::string input = "Aga,mina,olen;kahe-realine,tekst,\"vist; eksju?\";";
    std::string expected = "Aga,mina,olen\nkahe-realine,tekst,\"vist; eksju?\"";
    // ACT
    std::string output = parser(input);
    // ASSERT
    ASSERT_EQ(output, expected);
}
