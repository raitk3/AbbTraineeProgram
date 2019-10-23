#include "numbers.h"

#include <gtest/gtest.h>

TEST (Numbers, givenValues_callingCheckInput_MustReturnLow) {
    Values values {0, 5, 2};        //First number - numberToTest
                                    // Second number - numberToGuess
                                    // Third number - turns taken
    Status result = loopCheckInput(values);

    ASSERT_EQ(result, Status::LOW);
}

TEST (Numbers, givenValues_callingCheckInput_MustReturnEqual) {
    Values values {2, 2, 4};         //First number - numberToTest
                                     // Second number - numberToGuess
                                     // Third number - turns taken
    Status result = loopCheckInput(values);

    ASSERT_EQ(result, Status::EQUAL);
}

TEST (Numbers, givenValues_callingCheckInput_MustReturnHigh) {
    Values values {123, 121, 9};      //First number - numberToTest
                                       // Second number - numberToGuess
                                       // Third number - turns taken
    Status result = loopCheckInput(values);

    ASSERT_EQ(result, Status::HIGH);
}


TEST (Numbers, givenValues_callingLoopCheckInput_MustIncreaseTurnsTaken) {
    Values values {0, 1, 2};

    loopCheckInput(values);

    ASSERT_EQ(values.turnsTaken, 3);
}
