#include "game_frontend.h"


// Set cursor position.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(hOut, coord);
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

// Show console cursor or not.
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Move cursor around.
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

