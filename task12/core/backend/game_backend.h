#pragma once

#include <iostream>
#include <map>
#include <windows.h>

struct GameBackEnd {
    int chosenX;
    int chosenY;
    int sizeX;
    int sizeY;
    int sizeSz;
    char player1 = 88;
    char player2 = 79;
    WORD X_COLOR = 9;
    WORD O_COLOR = 12;
    std::map <std::tuple<int, int>, char> board;
    bool turnO = false;
};

GameBackEnd generate(int sizeX, int sizeY, int sizeSz, char player1, char player2, WORD X_COLOR, WORD O_COLOR);

void draw(GameBackEnd gbe);

bool checkNeighbouring(GameBackEnd gbe, int x, int y);

bool checkUnder(GameBackEnd gbe, int x, int y);

bool checkDiagRight(GameBackEnd gbe, int x, int y);

bool checkDiagLeft(GameBackEnd gbe, int x, int y);

bool check(GameBackEnd& gbe, HANDLE& hConsole);

bool checkForWin (GameBackEnd gbe);

bool checkForFull (GameBackEnd gbe);
