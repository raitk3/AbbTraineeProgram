#include <iostream>
#include <map>
#include <windows.h>

#include "front_end.h"
#include "back_end.h"

void print(BackEndData m) {
    system("cls");
    std::tuple<int, int> coordinates;
    for (int i = 0; i < m.map_size_y; i++) {
        for (int j = 0; j < m.map_size_x; j++) {
            coordinates = std::make_tuple(j, i);
            std::cout << m.map.at(coordinates);
        }
        std::cout << std::endl;
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

// As the name says. Repositions the cursor.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(hOut, coord);
}

