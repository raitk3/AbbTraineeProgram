#include "colors.h"

void setColor(Data&d, WORD color) {
    FlushConsoleInputBuffer(d.hConsole);
    SetConsoleTextAttribute(d.hConsole, color);
}
