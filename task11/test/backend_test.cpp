#include "back_end.h"

#include <gtest/gtest.h>

TEST(MyLibrary, givenMap_callingHasRoute_shouldReturnIfHasRouteToExit) {

    // ARRANGE
    std::vector<std::tuple<int, int>> hasVisitedAlready;
    std::vector<std::tuple<int, int>> hasVisitedAlready2;
    std::vector<std::tuple<int, int>> hasVisitedAlready3;

    //...
    //.G.
    //...
    //X..
    BackEndData backEnd {3, 4, 2, 1, 0, 3}; // Map size, PlayerLocation, ExitLocation
    backEnd = mapGenerate(backEnd);
    std::tuple<int, int> playerLocation = std::make_tuple(backEnd.player_x, backEnd.player_y);
    backEnd = replaceObject(backEnd, playerLocation, PLAYER);
    backEnd = replaceObject(backEnd, std::make_tuple(backEnd.exit_x, backEnd.exit_y), EXIT);

    //...
    //.G.
    //TTT
    //X..
    BackEndData backEnd2 = backEnd;
    backEnd2 = replaceObject(backEnd2, std::make_tuple(0, 2), OBSTACLE);
    backEnd2 = replaceObject(backEnd2, std::make_tuple(1, 2), OBSTACLE);
    backEnd2 = replaceObject(backEnd2, std::make_tuple(2, 2), OBSTACLE);

    //TTT
    //.G.
    //TTT
    //X..
    BackEndData backEnd3 = backEnd2;
    backEnd3 = replaceObject(backEnd3, std::make_tuple(0, 0), OBSTACLE);
    backEnd3 = replaceObject(backEnd3, std::make_tuple(1, 0), OBSTACLE);
    backEnd3 = replaceObject(backEnd3, std::make_tuple(2, 0), OBSTACLE);



    // ACT
    bool hasresult = hasRoute(backEnd, hasVisitedAlready, playerLocation);
    bool hasresult2 = hasRoute(backEnd2, hasVisitedAlready2, playerLocation);
    bool hasresult3 = hasRoute(backEnd3, hasVisitedAlready3, playerLocation);

    // ASSERT
    ASSERT_EQ(hasresult, true);
    ASSERT_EQ(hasresult2, true);
    ASSERT_EQ(hasresult3, false);

}
