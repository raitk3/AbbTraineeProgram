#include "table.h"

//Move the cursor to a new location.
void setCursorPosition(int x, int y)
{
    switch (x) {
        case 1:
            x = 2;
            break;
        case 2:
            x = 15;
            break;
        case 3:
            x = 30;
            break;
        case 4:
            x = 39;
            break;
        case 5:
            x = 61;
            break;
        case 6:
            x = 80;
            break;
        case 7:
            x = 93;
            break;
        case 8:
            x = 107;
            break;
    }

    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { static_cast<short>(x), static_cast<short>(y + 2) };
    SetConsoleCursorPosition(hOut, coord);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

//Draw the table.
void draw(Data d) {
    system("cls");
    setColor(d, HEADER_COLOR);

    std::cout << std::left;
    print_divider();
    std::cout << "| " << std::setw(10) << "Name" << " | "
              << std::setw(12) << "Surname" <<" | "
              << std::setw(6) << "Gender" << " | "
              << std::setw(19) << "Position" << " | "
              << std::setw(16) << "Department" << " | "
              << std::setw(10) << "Birthday" << " | "
              << std::setw(11) << "Telephone" << " | "
              << std::setw(6) << "Salary" << " | "
              << "\n";
    print_divider();
    setColor(d, WHITE);
    for (auto person : d.people) {
        std::cout <<"| " << std::setw(10) << person.second.printName() << " | "
                  << std::setw(12) << person.second.printSurname() <<" | "
                  << std::setw(6) << person.second.printGender() << " | "
                  << std::setw(19) << person.second.printPosition() << " | "
                  << std::setw(16) << person.second.printDepartment() << " | "
                  << std::setw(10) << person.second.printBirthday() << " | "
                  << std::setw(11) << person.second.printTelephone() << " | "
                  << std::setw(6) << person.second.printSalary() << " | "
                  << "\n";
    }
    print_footer(d);
}
