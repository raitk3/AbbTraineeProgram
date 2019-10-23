#include "backend/game_backend.h"

#include <gtest/gtest.h>

static HANDLE hTest;

TEST(BackEnd, givenSize_callingGenerate_mustReturnBoardThatSize) {
    // ARRANGE
    int x = 3;
    int y = 4;
    int sz = 3;
    char p1 = 88; // X
    char p2 = 79; // O
    WORD c1 = 1;
    WORD c2 = 2;

    // ACT
        GameBackEnd testBackEnd = generate(x, y, sz, p1, p2, c1, c2);

    // ASSERT
        ASSERT_EQ(testBackEnd.board.size(), 12);
}

TEST(BackEnd, givenBoard_callingCheck_mustReturnIfCouldDoAnything) {
    // ARRANGE
    GameBackEnd testBackEnd = generate(2, 2, 3, 1, 2, 1, 2);
    testBackEnd.board.at(std::make_pair(0, 0)) = 1;
    testBackEnd.board.at(std::make_pair(0, 1)) = 2;
    testBackEnd.board.at(std::make_pair(1, 0)) = 2;
    testBackEnd.chosenX = 1;
    testBackEnd.chosenY = 0;
    GameBackEnd testBackEnd2 = generate(2, 2, 3, 1, 2, 1, 2);
    testBackEnd2.board.at(std::make_pair(0, 0)) = 1;
    testBackEnd2.board.at(std::make_pair(0, 1)) = 2;
    testBackEnd2.board.at(std::make_pair(1, 0)) = 2;
    testBackEnd2.chosenX = 1;
    testBackEnd2.chosenY = 1;

    // ACT
    bool checked = check(testBackEnd, hTest);
    bool checked2 = check(testBackEnd2, hTest);

    // ASSERT
    ASSERT_EQ(checked, false);
    ASSERT_EQ(checked2, true);
}


TEST(BackEnd, givenWinningBoard_callingCheckForWin_MustReturnTrue) {
    // ARRANGE
    int x = 3;
    int y = 4;
    int sz = 3;
    char p1 = 88; // X
    char p2 = 79; // O
    WORD c1 = 1;
    WORD c2 = 2;

    GameBackEnd testBackEnd = generate(x, y, sz, p1, p2, c1, c2);
    testBackEnd.board.at(std::make_pair(1, 1)) = p1;
    testBackEnd.board.at(std::make_pair(1, 2)) = p1;
    testBackEnd.board.at(std::make_pair(1, 3)) = p1;
    GameBackEnd testBackEnd2 = generate(x, y, sz, p1, p2, c1, c2);
    testBackEnd2.board.at(std::make_pair(1, 1)) = p1;
    testBackEnd2.board.at(std::make_pair(1, 2)) = p2;
    testBackEnd2.board.at(std::make_pair(1, 3)) = p1;

    // ACT
    bool win = checkForWin(testBackEnd);
    bool notWin = checkForWin(testBackEnd2);

    // ASSERT
    ASSERT_EQ(win, true);
    ASSERT_EQ(notWin, false);
}

TEST(BackEnd, givenFullBoardAllWinningCombinations_MustReturnAllCombosTrue) {
    GameBackEnd testBackEnd = generate(5, 5, 5, 1, 2, 1, 2);
    testBackEnd.board.at(std::make_pair(0, 0)) = 1;
    testBackEnd.board.at(std::make_pair(1, 1)) = 1;
    testBackEnd.board.at(std::make_pair(2, 2)) = 1; //  X| |X| |X
    testBackEnd.board.at(std::make_pair(3, 3)) = 1; //  -+-+-+-+-
    testBackEnd.board.at(std::make_pair(4, 4)) = 1; //   |X| |X|
    testBackEnd.board.at(std::make_pair(2, 0)) = 1; //  -+-+-+-+-
    testBackEnd.board.at(std::make_pair(2, 1)) = 1; //  X|X|X|X|X
    testBackEnd.board.at(std::make_pair(2, 3)) = 1; //  -+-+-+-+-
    testBackEnd.board.at(std::make_pair(2, 4)) = 1; //   |X|X|X|
    testBackEnd.board.at(std::make_pair(0, 4)) = 1; //  -+-+-+-+-
    testBackEnd.board.at(std::make_pair(1, 3)) = 1; //  X| |X| |X
    testBackEnd.board.at(std::make_pair(3, 1)) = 1;
    testBackEnd.board.at(std::make_pair(4, 0)) = 1;
    testBackEnd.board.at(std::make_pair(0, 2)) = 1;
    testBackEnd.board.at(std::make_pair(1, 2)) = 1;
    testBackEnd.board.at(std::make_pair(3, 2)) = 1;
    testBackEnd.board.at(std::make_pair(4, 2)) = 1;

    bool diagLR = checkDiagRight(testBackEnd, 0, 0);
    bool diagRL = checkDiagLeft(testBackEnd, 4, 0);
    bool horizontal = checkNeighbouring(testBackEnd, 0, 2);
    bool vertical = checkUnder(testBackEnd, 2, 0);

    ASSERT_EQ(diagLR, true);
    ASSERT_EQ(diagRL, true);
    ASSERT_EQ(horizontal, true);
    ASSERT_EQ(vertical, true);

}

TEST(BackEnd, givenFullBoard_callingCheckFull_mustReturnTrue) {
    GameBackEnd testBackEnd = generate(2, 2, 2, 1, 2, 1, 2);
    testBackEnd.board.at(std::make_pair(0, 0)) = 1;
    testBackEnd.board.at(std::make_pair(0, 1)) = 2;
    testBackEnd.board.at(std::make_pair(1, 0)) = 2;
    testBackEnd.board.at(std::make_pair(1, 1)) = 1;

    bool full = checkForFull(testBackEnd);

    ASSERT_EQ(full, true);
}



