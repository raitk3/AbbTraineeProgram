#include "game_loop.h"

#define WHITE 15
#define BLACK 0

bool gameLoop(GameBackEnd& gbe, GameFrontEnd& gfe, HANDLE& hConsole) {

    move(gbe, gfe, hConsole);

    if (checkForWin(gbe)) {
        setCursorPosition(0, gbe.sizeY * 4);
        ShowConsoleCursor(false);
        char whoWon = (gbe.turnO) ? gbe.player1 : gbe.player2;
        // Doesn't change to white, so it shows winning text in winners colour.
        std::cout << "Game over! " << whoWon << " won!\n";
        return false;
    }

    if (checkForFull(gbe)) {
        setCursorPosition(0, gbe.sizeY * 4);
        ShowConsoleCursor(false);
        // Draw - no winner - white.
        SetConsoleTextAttribute(hConsole, WHITE);
        std::cout << "Game over! It's a draw!\n";
        return false;
      }
    return true;
}

std::tuple<int, int, int, char, WORD, char, WORD> askInput(HANDLE& hConsole) {
    // Board parameters.
    int sizeX, sizeY, sizeSz;
    char player1, player2;
    WORD X_COLOR, O_COLOR;
    std::cout << "How many columns?" << std::endl;
    std::cin >> sizeX;
    while (sizeX < 3) {
        system("cls");
        std::cout << "How many columns?" << std::endl;
        std::cin >> sizeX;
    }
    system("cls");
    std::cout << "How many rows?" << std::endl;
    std::cin >> sizeY;
    while (sizeY < 3) {
        system("cls");
        std::cout << "How many rows?" << std::endl;
        std::cin >> sizeY;
    }
    system("cls");
    std::cout << "How many in a row to win?" << std::endl;
    std::cin >> sizeSz;
    while (sizeSz > std::max(sizeX, sizeY) || sizeSz < 1) {
        system("cls");
        std::cout << "How many in a row to win?" << std::endl;
        std::cin >> sizeSz;
    }
    system("cls");

    std::cout << "Player 1 sign?" << std::endl;
    std::cin >> player1;
    system("cls");


    printHint(hConsole);
    std::cout << "Player 1 color? (Insert number 1 - 14)" << std::endl;
    std::cin >> X_COLOR;
    while (X_COLOR > 14 || X_COLOR < 1) {
        system("cls");
        printHint(hConsole);
        std::cout << "Choose a different number! (Insert number 1 - 14)" << std::endl;
        std::cin >> X_COLOR;
    }
    system("cls");

    std::cout << "Player 2 sign?" << std::endl;
    std::cin >> player2;
    while (player1 == player2) {
        system("cls");
        std::cout << "Choose another name for player 2!" << std::endl;
        std::cin >> player2;
    }
    system("cls");


    printHint(hConsole);
    std::cout << "Player 2 color? (Insert number 1 - 14, except " << X_COLOR << ")" << std::endl;
    std::cin >> O_COLOR;
    while (O_COLOR > 14 || O_COLOR < 1 || X_COLOR == O_COLOR) {
        system("cls");
        printHint(hConsole);
        std::cout << "Choose a different number! (Insert number 1 - 14, except " << X_COLOR <<  ")\n";
        std::cin >> O_COLOR;
    }
    system("cls");

    return std::tuple(sizeX, sizeY, sizeSz, player1, X_COLOR, player2, O_COLOR);

}

void printHint(HANDLE& hConsole) {
    for (WORD i = 1; i < 15; i++) {
        SetConsoleTextAttribute(hConsole, i);
        std::cout << i;
        SetConsoleTextAttribute(hConsole, WHITE);
        if (i != 14) {
        std::cout << ", ";
        }
    }
    std::cout << "\n";
}

