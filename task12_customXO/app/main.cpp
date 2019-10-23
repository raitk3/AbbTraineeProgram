#include <iostream>
#include <conio.h>
#include <map>
#include <windows.h>

#define BLANK 32
#define CROSS 88
#define NOUGHT 79
#define X_COLOR 9
#define O_COLOR 12
#define WHITE 15
#define BLACK 0


//Disable cursor blinking.

struct GameBackEnd {
    int chosenX;
    int chosenY;
    int sizeX;
    int sizeY;
    int sizeSz;
    std::map <std::tuple<int, int>, char> board;
    bool turnO = false;
};

struct GameFrontEnd {
    int cursorX;
    int cursorY;
};

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


// Set cursor position.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (short)x, (short)y };
    SetConsoleCursorPosition(hOut, coord);
}

// Generate a new board
GameBackEnd generate(GameBackEnd gbe, int x, int y, int sz, int chosenX, int chosenY) {
    GameBackEnd newGbe = gbe;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            newGbe.board.insert(std::make_pair(std::make_tuple(j, i), BLANK));
        }
    }
    newGbe.sizeX = x;
    newGbe.sizeY = y;
    newGbe.sizeSz = sz;
    newGbe.chosenX = chosenX;
    newGbe.chosenY = chosenY;
    return newGbe;
}

// Draw the board.

void draw(GameBackEnd gbe) {
    for (int i = 0; i < 4 * gbe.sizeY - 1; i++) {
        if ((i - 3) % 4 == 0) {
            std::cout << "---";
            for (int j = 0; j < gbe.sizeX - 1; j++) {
                std::cout << "+---";
            }
            std::cout << "\n";
        } else {
        std::cout << "   ";
            for (int j = 0; j < gbe.sizeX - 1; j++) {

                std::cout << "|   ";
            }
        std::cout << "\n";
    }
}
}

// Check Combos.

bool checkNeighbouring(GameBackEnd gbe, int x, int y, int sz) {
    if (sz != 1 && x == gbe.sizeX - 1) {
        return false;
    }
    if (gbe.board.at(std::make_tuple(x, y)) == BLANK) {
        return false;
    }
    if (sz == 1) {
        return true;
    }
    bool othersWere = checkNeighbouring(gbe, x + 1, y, sz - 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x+1, y))));
}

bool checkUnder(GameBackEnd gbe, int x, int y, int sz) {
    if ((sz != 1 && y == gbe.sizeY - 1) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (sz == 1) {
        return true;
    }
    bool othersWere = checkUnder(gbe, x, y + 1, sz - 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x, y + 1))));
}

bool checkDiagRight(GameBackEnd gbe, int x, int y, int sz) {
    if ((sz != 1 && (x == gbe.sizeX - 1 || y == gbe.sizeY - 1)) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (sz == 1) {
        return true;
    }
    bool othersWere = checkDiagRight(gbe, x + 1, y + 1, sz - 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x + 1, y + 1))));
}

bool checkDiagLeft(GameBackEnd gbe, int x, int y, int sz) {
    if ((sz != 1 && (x == 0 || y == gbe.sizeY - 1)) || (gbe.board.at(std::make_tuple(x, y)) == BLANK)) {
        return false;
    }
    if (sz == 1) {
        return true;
    }
    bool othersWere = checkDiagLeft(gbe, x - 1, y + 1, sz - 1);
    return (othersWere && (gbe.board.at(std::make_tuple(x, y)) == gbe.board.at(std::make_tuple(x - 1, y + 1))));
}

// Master checker.
bool checkForWin (GameBackEnd gbe) {
    int sz = gbe.sizeSz;
    for ( int i = 0; i < gbe.sizeY; i++) {
        for (int j = 0; j < gbe.sizeX; j++) {
            if (checkNeighbouring(gbe, j, i, sz) || checkUnder(gbe, j, i, sz) || checkDiagRight(gbe, j, i, sz)
                    || checkDiagLeft(gbe, j, i, sz)) {
                return true;
            }
        }
    }
    return false;
}

// Check if board is full.
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
void check(GameBackEnd& gbe, HANDLE& hConsole){
    char insert;
    std::tuple<int, int> chosenSquare = std::make_tuple(gbe.chosenX, gbe.chosenY);
    if (gbe.board.at(chosenSquare) == BLANK) {

        // Backend stuff.
        gbe.board.erase(chosenSquare);
        insert = (gbe.turnO) ? NOUGHT : CROSS;
        gbe.board.insert(std::make_pair(chosenSquare, insert));

        // Changes color depending on whose turn it was.
        FlushConsoleInputBuffer(hConsole);
        SetConsoleTextAttribute(hConsole, gbe.turnO ? O_COLOR : X_COLOR);

        // Switches turn.
        gbe.turnO = !gbe.turnO;

        std::cout << insert;
    }

}

// Moves cursor around.
void move(GameBackEnd& gbe, GameFrontEnd& gfe, HANDLE& hConsole) {
    switch (getch()) {
        // UP
        case 72:
            if (gbe.chosenY - 1 >= 0) {
                gbe.chosenY -= 1;
            }
            break;
        // LEFT
        case 75:
            if (gbe.chosenX - 1 >= 0) {
                gbe.chosenX -= 1;
            }
            break;
        // DOWN
        case 80:
            if (gbe.chosenY + 1 < gbe.sizeY) {
                gbe.chosenY += 1;
            }
            break;
        // RIGHT
        case 77:
            if (gbe.chosenX + 1 < gbe.sizeX) {
                gbe.chosenX += 1;
            }
            break;
        // SPACE
        case 32:
            check(gbe, hConsole);
            break;
        // ENTER
        case 13:
            check(gbe, hConsole);
            break;
    }
    gfe.cursorX = 4 * (gbe.chosenX) + 1;
    gfe.cursorY = 4 * (gbe.chosenY) + 1;
    setCursorPosition(gfe.cursorX, gfe.cursorY);
}

int main() {
    int size_x;
    int size_y;
    int size_sz;

    // Board parameters.
    std::cout << "How many columns?\n";
    std::cin >> size_x;
    while (size_x < 3) {
        system("cls");
        std::cout << "How many columns?\n";
        std::cin >> size_x;
    }
    system("cls");
    std::cout << "How many rows?\n";
    std::cin >> size_y;
    while (size_y < 3) {
        system("cls");
        std::cout << "How many rows?\n";
        std::cin >> size_y;
    }
    system("cls");
    std::cout << "How many in a row to win?\n";
    std::cin >> size_sz;
    while (size_sz > std::max(size_x, size_y) || size_sz < 1) {
        system("cls");
        std::cout << "How many in a row to win?\n";
        std::cin >> size_sz;
    }
    system("cls");

    int chosenX = size_x / 2;
    int chosenY = size_y / 2;
    int cursor_x = 4 * (chosenX) + 1;
    int cursor_y = 4 * (chosenY) + 1;

    bool gameOver = false;

    GameBackEnd gbe;
    GameFrontEnd gfe {cursor_x, cursor_y};
    gbe = generate(gbe, size_x, size_y, size_sz, chosenX, chosenY);
    draw(gbe);

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setCursorPosition(cursor_x, cursor_y);

    //Game loop
    while (!gameOver) {
        move(gbe, gfe, hConsole);

        if (checkForWin(gbe)) {
            setCursorPosition(0, gbe.sizeY * 4);
            ShowConsoleCursor(false);
            gameOver = true;
            std::string whoWon = (gbe.turnO) ? "X" : "O";
            // Doesn't change to white, so it shows winning text in winners colour.
            std::cout << "Game over! " << whoWon << " won!\n";
            SetConsoleTextAttribute(hConsole, BLACK);
            return 0;
        }

        if (checkForFull(gbe)) {
            setCursorPosition(0, gbe.sizeY * 4);
            ShowConsoleCursor(false);
            // Draw - no winner - white.
            SetConsoleTextAttribute(hConsole, WHITE);
            gameOver = true;
            std::cout << "Game over! It's a draw!\n";
            // To hide "Press return to leave text."
            SetConsoleTextAttribute(hConsole, BLACK);
            return 0;
          }
    }
}
