#include "maths.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenNumber_callingFindMin_mustReturnNumberMinimum) {
    // ARRANGE
    int a = 3;
    int b = 5;
    int c = 8;

    // ACT
    int result = findMin(a, b, c);

    // ASSERT
    ASSERT_EQ(result, 3);


    a = 19;
    b = 121;
    c = 1;

    result = findMin(a, b, c);

    ASSERT_EQ(result, 1);
}

TEST(MyLibrary, givenNumber_callingFindMax_mustReturnNumberMaximum) {
    // ARRANGE
    int a = 3;
    int b = 5;
    int c = 8;

    // ACT
    int result = findMax(a, b, c);

    // ASSERT
    ASSERT_EQ(result, 8);


    a = 2312;
    b = 1;
    c = 128112;

    result = findMax(a, b, c);

    ASSERT_EQ(result, 128112);
}

TEST(MyLibrary, givenNumber_callingFindSum_mustReturnSum) {
    // ARRANGE
    int a = 3, b = 5, c = 8;
    int d = 2147483647, e = 2147483647, f = 2147483647;
    // ACT
    double result = findSum(a, b, c);
    double result2 = findSum(d, e, f);

    // ASSERT
    ASSERT_EQ(result, 16);
    ASSERT_EQ(result2, 6442450941);
}

TEST(MyLibrary, givenNumber_callingFindProduct_mustReturnProduct) {
    // ARRANGE
    int a = 2, b = 5, c = 8;

    // ACT
    double result = findProduct(a, b, c);

    // ASSERT
    ASSERT_EQ(result, 80);
}
