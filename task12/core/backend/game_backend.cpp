#include "game_backend.h"
#include <iostream>
#include <map>

#define BLANK 32

// Generate a new board
GameBackEnd generate(int sizeX, int sizeY, int sizeSz, char player1, char player2, WORD X_COLOR, WORD O_COLOR) {
    GameBackEnd newGbe;
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            newGbe.board.insert(std::make_pair(std::make_tuple(j, i), BLANK));
        }
    }
    newGbe.sizeX = sizeX;
    newGbe.sizeY = sizeY;
    newGbe.chosenX = sizeX / 2;
    newGbe.chosenY = sizeY / 2;
    newGbe.sizeSz = sizeSz;
    newGbe.player1 = player1;
    newGbe.player2 = player2;
    newGbe.X_COLOR = X_COLOR;
    newGbe.O_COLOR = O_COLOR;
    return newGbe;
}

// Check win from left to right.
bool checkNeighbouring(GameBackEnd gbe, int x, int y) {
    if (gbe.sizeSz != 1 && x == gbe.sizeX - 1) {
        return false;
    }
    if (gbe.board.at(std::make_tuple(x, y)) == BLANK) {
        return false;
    }
    if (gbe.sizeSz == 1) {
        return true;
    }
    gbe.sizeSz -= 1;
    bool othersWere = checkNeighbouring(gbe, x + 1, y);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x+1, y))));
}

// Check win from up to down.
bool checkUnder(GameBackEnd gbe, int x, int y) {
    if ((gbe.sizeSz != 1 && y == gbe.sizeY - 1) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (gbe.sizeSz == 1) {
        return true;
    }
    gbe.sizeSz -= 1;
    bool othersWere = checkUnder(gbe, x, y + 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x, y + 1))));
}

// Check win diagonally.
bool checkDiagRight(GameBackEnd gbe, int x, int y) {
    if ((gbe.sizeSz != 1 && (x == gbe.sizeX - 1 || y == gbe.sizeY - 1)) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (gbe.sizeSz == 1) {
        return true;
    }
    gbe.sizeSz -= 1;
    bool othersWere = checkDiagRight(gbe, x + 1, y + 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x + 1, y + 1))));
}

// Check win diagonally.
bool checkDiagLeft(GameBackEnd gbe, int x, int y) {
    if ((gbe.sizeSz != 1 && (x == 0 || y == gbe.sizeY - 1)) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (gbe.sizeSz == 1) {
        return true;
    }
    gbe.sizeSz -= 1;
    bool othersWere = checkDiagLeft(gbe, x - 1, y + 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x - 1, y + 1))));
}

// Check win conditions.
bool checkForWin (GameBackEnd gbe) {
    for ( int i = 0; i < gbe.sizeY; i++) {
        for (int j = 0; j < gbe.sizeX; j++) {
            if (checkNeighbouring(gbe, j, i)
                    || checkUnder(gbe, j, i)
                    || checkDiagRight(gbe, j, i)
                    || checkDiagLeft(gbe, j, i)) {
                return true;
            }
        }
    }
    return false;
}

// Check if draw.
bool checkForFull (GameBackEnd gbe) {
    for (int i = 0; i < gbe.sizeY; i++) {
        for (int j = 0; j < gbe.sizeX; j++) {
            if (gbe.board.at(std::make_tuple(j, i)) == BLANK) {
                return false;
            }
        }
    }
    return true;
}

// Do the move if able to.
bool check(GameBackEnd& gbe, HANDLE& hConsole){
    char insert;
    std::tuple<int, int> chosenSquare = std::make_tuple(gbe.chosenX, gbe.chosenY);
    if (gbe.board.at(chosenSquare) == BLANK) {

        // Backend stuff.
        gbe.board.erase(chosenSquare);
        insert = (gbe.turnO) ? gbe.player2 : gbe.player1;
        gbe.board.insert(std::make_pair(chosenSquare, insert));

        // Changes color depending on whose turn it was.
        FlushConsoleInputBuffer(hConsole);
        SetConsoleTextAttribute(hConsole, gbe.turnO ? gbe.O_COLOR : gbe.X_COLOR);

        // Switches turn.
        gbe.turnO = !gbe.turnO;

        std::cout << insert;
        return true;
    }
    return false;

}
