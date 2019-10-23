#include "move.h"

void move(Data& d) {
    switch (getch()) {
        // UP
        case 72:
            if (d.x - 1 > 0) {
                d.x--;
            }
            break;
        // LEFT
        case 75:
            if (d.y - 1 > 0) {
            d.y--;
            }
            break;
        // DOWN
        case 80:
            if (d.x + 1 <= static_cast<int>(d.people.size())) {
            d.x++;
            }
            break;
        // RIGHT
        case 77:
            if (d.y + 1 < 9) {
                d.y++;
            }
            break;
        // ENTER
        case 13:
        if (d.people.count(d.x) && d.y == 3) {
                selectStuff(d, 0);
            } else if (d.people.count(d.x) && d.y == 4) {
                selectStuff(d, 1);
            } else if (d.people.count(d.x) && d.y == 5) {
                selectStuff(d, 2);
            } else if (d.people.count(d.x)) {
                changeData(d);
            }
            break;
        // m
        case 109:
            addPersonNextLine(d);
            setCursorPosition(d.y, d.x);
            writeCSV(d);
            break;
        // n
        case 110:
            addPerson(d);
            setCursorPosition(d.y, d.x);
            writeCSV(d);
            break;
        // r
        case 114:
            removePerson(d);
            writeCSV(d);
            break;
        // s
        case 115:
            writeCSV(d);
            break;
        // Backspace
        case 8:
            nullData(d);
            break;
        // Esc
        case 27:
            writeCSV(d);
            setCursorPosition(0, static_cast<int>(d.people.size()) + 8);
            exit(true);
    }
    if (d.x > static_cast<int>(d.people.size())) d.x--;
    setCursorPosition(d.y, d.x);
}
