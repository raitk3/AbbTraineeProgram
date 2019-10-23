#include <iostream>

#include <map>
#include <windows.h>
#include "backend/game_backend.h"
#include "frontend/game_frontend.h"
#include "game_loop.h"

int main() {
    bool gameOver = false;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    auto [sizeX, sizeY, sizeSz, player1, X_COLOR, player2, O_COLOR] = askInput(hConsole);
    GameBackEnd gbe = generate(sizeX, sizeY, sizeSz, player1, player2, X_COLOR, O_COLOR);
    int cursor_x = 4 * (gbe.chosenX) + 1;
    int cursor_y = 4 * (gbe.chosenY) + 1;
    GameFrontEnd gfe {cursor_x, cursor_y};
    draw(gbe);

    setCursorPosition(cursor_x, cursor_y);

    //Game loop
    while (!gameOver) {
        if(!gameLoop(gbe, gfe, hConsole)) {
            gameOver = true;
        }
    }
}
