#include "movement.h"

#include <gtest/gtest.h>

/* **************
 * *TestBackEnds*
 * **************/

BackEndData generateBlankTestBackend () {
    //...
    //.G.
    //...
    BackEndData backEndData {3, 3, 1, 1};
    backEndData = mapGenerate(backEndData);
    backEndData = replaceObject(backEndData, std::make_tuple(backEndData.player_x, backEndData.player_y), PLAYER);
    return backEndData;
}

BackEndData generateWallCrasherTestBackend () {
    //G.
    //..
    BackEndData backEndData = {2, 2, 0, 0};
    backEndData = mapGenerate(backEndData);
    backEndData = replaceObject(backEndData, std::make_tuple(backEndData.player_x, backEndData.player_y), PLAYER);
    return backEndData;
}

BackEndData generateTestBackend () {
    //GX
    //T.
    BackEndData backEndData {2, 2, 0, 0, 1, 0, 1, {}};
    backEndData = mapGenerate(backEndData);
    backEndData = replaceObject(backEndData, std::make_tuple(backEndData.player_x, backEndData.player_y), PLAYER);
    backEndData = replaceObject(backEndData, std::make_tuple(backEndData.exit_x, backEndData.exit_y), EXIT);
    backEndData = replaceObject(backEndData, std::make_tuple(0, 1), OBSTACLE);
    return backEndData;
}

/* *******
 * *TESTS*
 * *******/

/*
 * Movements
 */

//LEFT

TEST (Movement, givenTable_callingMoveLeft_mustChangePositionLeft) {
    BackEndData backEnd = generateBlankTestBackend();

    movement(backEnd, LEFT);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 1)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 1)), PLAYER);
}

TEST (Movement, givenTable_callingMoveLeftIntoWall_mustChangePositionRightMostCell) {
    BackEndData backEnd = generateWallCrasherTestBackend();

    bool continuePlaying = movement(backEnd, LEFT);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 0)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 0)), PLAYER);
    ASSERT_EQ(continuePlaying, true);
}

// RIGHT

TEST (Movement, givenTable_callingMoveRight_mustChangePositionRight) {
    BackEndData backEnd = generateBlankTestBackend();

    movement(backEnd, RIGHT);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 1)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(2, 1)), PLAYER);
}

TEST (Movement, givenTable_callingMoveRightIntoWall_mustChangePositionLeftMostCell) {
    BackEndData backEnd = generateWallCrasherTestBackend();

    movement(backEnd, RIGHT);
    bool continuePlaying = movement(backEnd, RIGHT);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 0)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 0)), PLAYER);
    ASSERT_EQ(continuePlaying, true);
}

// UP

TEST (Movement, givenTable_callingMoveUp_mustChangePositionUp) {
    BackEndData backEnd = generateBlankTestBackend();

    movement(backEnd, UP);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 1)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 0)), PLAYER);
}

TEST (Movement, givenTable_callingMoveUpIntoWall_mustChangePositionBottomMostCell) {
    BackEndData backEnd = generateWallCrasherTestBackend();

    bool continuePlaying = movement(backEnd, UP);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 0)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 1)), PLAYER);
    ASSERT_EQ(continuePlaying, true);
}

// DOWN

TEST (Movement, givenTable_callingMoveDown_mustChangePositionDown) {
    BackEndData backEnd = generateBlankTestBackend();

    movement(backEnd, DOWN);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 1)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(1, 2)), PLAYER);
}

TEST (Movement, givenTable_callingMoveDownIntoWall_mustChangePositionUpMostCell) {
    BackEndData backEnd = generateWallCrasherTestBackend();

    movement(backEnd, DOWN);
    bool continuePlaying = movement(backEnd, DOWN);

    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 1)), EMPTY_CELL);
    ASSERT_EQ(backEnd.map.at(std::make_tuple(0, 0)), PLAYER);
    ASSERT_EQ(continuePlaying, true);
}

/*
 *  BoolToContinuePlaying.
 */

TEST (Movement, givenTable_callingMoveIntoEmptyCell_mustReturnTrue) {
    BackEndData backEnd = generateBlankTestBackend();

    bool continuePlaying = movement(backEnd, RIGHT);

    ASSERT_EQ(continuePlaying, true);
}

TEST (Movement, givenTable_callingMoveIntoExit_mustReturnFalse) {
    BackEndData backEnd = generateTestBackend();

    bool continuePlaying = movement(backEnd, RIGHT);

    ASSERT_EQ(continuePlaying, false);
}

TEST (Movement, givenTable_callingMoveIntoObstacle_mustReturnFalse) {
    BackEndData backEnd = generateTestBackend();

    bool continuePlaying = movement(backEnd, DOWN);

    ASSERT_EQ(continuePlaying, false);
}

