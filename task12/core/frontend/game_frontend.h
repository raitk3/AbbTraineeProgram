#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "../backend/game_backend.h"

struct GameFrontEnd {
    int cursorX;
    int cursorY;
};

void setCursorPosition(int x, int y);

void ShowConsoleCursor(bool showFlag);

void move(GameBackEnd& gbe, GameFrontEnd& gfe, HANDLE& hConsole);
