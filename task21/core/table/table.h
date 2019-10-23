#pragma once

#include <iostream>
#include <windows.h>
#include <iomanip>

#include "../data.h"
#include "../person/person.h"
#include "../colors/colors.h"

void ShowConsoleCursor(bool showFlag);

void setCursorPosition(int x, int y);

void draw(Data d);

void draw_line(Data d, bool blank);

void print_divider();

void remove_row(Data d);

void draw_new_row(Data d);

void print_footer(Data d);

