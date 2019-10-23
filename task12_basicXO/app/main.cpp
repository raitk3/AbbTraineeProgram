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

// Draw the board.

void draw(char char1, char char2, char char3, char char4, char char5, char char6, char char7, char char8, char char9) {
    std::string tinyDivider = " | ";
    std::string blankRow = "   |   |   \n";
    std::string end = "\n   |   |   \n";
    std::string divider = "---+---+---\n";
    std::cout << blankRow
              << " " << char1 << tinyDivider << char2 <<  tinyDivider << char3 << "\n"
              << blankRow
              << divider
              << blankRow
              << " " << char4 << tinyDivider << char5 << tinyDivider << char6 << "\n"
              << blankRow
              << divider
              << blankRow
              << " " << char7 << tinyDivider << char8 << tinyDivider << char9
              << end;
}

// Check all combinations for win.

bool checkForWin (bool turnO, char char1, char char2, char char3, char char4, char char5, char char6, char char7, char char8, char char9) {
    char comparable = (turnO) ? NOUGHT : CROSS;
    if((char1 == char2 && char2 == char3 && char3 == comparable)
            || (char4 == char5 && char5 == char6 && char6 == comparable)
            || (char7 == char8 && char8 == char9 && char9 == comparable)
            || (char1 == char4 && char4 == char7 && char7 == comparable)
            || (char2 == char5 && char5 == char8 && char8 == comparable)
            || (char3 == char6 && char6 == char9 && char9 == comparable)
            || (char1 == char5 && char5 == char9 && char9 == comparable)
            || (char3 == char5 && char5 == char7 && char7 == comparable)) {
        return true;
    }
    return false;
}

// Check if board is full.
bool checkForFull (char char1, char char2, char char3, char char4, char char5, char char6, char char7, char char8, char char9) {
    return (
            char1 != BLANK
            && char2 != BLANK
            && char3 != BLANK
            && char4 != BLANK
            && char5 != BLANK
            && char6 != BLANK
            && char7 != BLANK
            && char8 != BLANK
            && char9 != BLANK)
        ? true : false;
}

// Do the move if able to.
void check(std::map<int, char>& board, int chosenSquare, bool& turnO, HANDLE& hConsole){
    char insert;
    if (board.at(chosenSquare) == BLANK) {

        // Backend stuff.
        board.erase(chosenSquare);
        insert = (turnO) ? NOUGHT : CROSS;
        board.insert(std::pair<int, char>(chosenSquare, insert));

        // Changes color depending on whose turn it was.
        FlushConsoleInputBuffer(hConsole);
        SetConsoleTextAttribute(hConsole, turnO ? O_COLOR : X_COLOR);

        // Switches turn.
        turnO = !turnO;

        std::cout << insert;
    }

}


int main() {
    int selectedSquare = 5;
    int cursor_x = 5;
    int cursor_y = 5;
    bool gameOver = false;
    bool turnO = false;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::map<int, char> board = {
        {1, BLANK},
        {2, BLANK},
        {3, BLANK},
        {4, BLANK},
        {5, BLANK},
        {6, BLANK},
        {7, BLANK},
        {8, BLANK},
        {9, BLANK},
    };
    system("cls");
    draw(board.at(1), board.at(2), board.at(3), board.at(4), board.at(5), board.at(6), board.at(7), board.at(8), board.at(9));
    setCursorPosition(cursor_x, cursor_y);
    while (!gameOver) {
        switch (getch()) {
            case 72:
                if (selectedSquare - 3 > 0) {
                    selectedSquare -= 3;
                    cursor_y -= 4;
                    }
                break;
            case 75:
                if (selectedSquare - 1 > 0 && (selectedSquare - 1) % 3 != 0) {
                    selectedSquare -= 1;
                    cursor_x -= 4;
                    }
                break;
            case 80:
                if (selectedSquare + 3 < 10) {
                selectedSquare += 3;
                cursor_y += 4;
                }
                break;
            case 77:
            if (selectedSquare + 1 > 0 && (selectedSquare) % 3 != 0) {
                selectedSquare += 1;
                cursor_x += 4;
                }
                break;
            case 32:
                check(board, selectedSquare, turnO, hConsole);
                break;
            case 13:
                check(board, selectedSquare, turnO, hConsole);
                break;
        }
        setCursorPosition(cursor_x, cursor_y);

        if (checkForWin(!turnO, board.at(1), board.at(2), board.at(3), board.at(4), board.at(5), board.at(6), board.at(7), board.at(8), board.at(9))) {
            setCursorPosition(0, 12);
            ShowConsoleCursor(false);
            gameOver = true;
            std::string whoWon = (turnO) ? "X" : "O";
            // Doesn't change to white, so it shows winning text in winners colour.
            std::cout << "Game over! " << whoWon << " won!\n";
            SetConsoleTextAttribute(hConsole, BLACK);
            return 0;
        }

        if (checkForFull(board.at(1), board.at(2), board.at(3), board.at(4), board.at(5), board.at(6), board.at(7), board.at(8), board.at(9))) {
            setCursorPosition(0, 12);
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
