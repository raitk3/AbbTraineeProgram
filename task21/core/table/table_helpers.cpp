#include "table.h"

void print_divider() {
    std::cout << "+------------+--------------+--------+---------------------+------------------+------------+-------------+--------+\n";
}

void draw_line(Data d, bool blank) {
    ShowConsoleCursor(false);
    Person person;
    if (!blank) {
        person = d.people.at(d.x);
    }
    std::cout <<"| " << std::setw(10) << person.printName() << " | "
              << std::setw(12) << person.printSurname() <<" | "
              << std::setw(6) << person.printGender() << " | "
              << std::setw(19) << person.printPosition() << " | "
              << std::setw(16) << person.printDepartment() << " | "
              << std::setw(10) << person.printBirthday() << " | "
              << std::setw(11) << person.printTelephone() << " | "
              << std::setw(6) << person.printSalary() << " | "
              << "\n";
    setCursorPosition(d.y, d.x);
    ShowConsoleCursor(true);
}

void draw_new_row(Data d) {
    ShowConsoleCursor(false);
    setCursorPosition(0, static_cast<int>(d.people.size()));
    draw_line(d, true);
    setCursorPosition(0, static_cast<int>(d.people.size() + 1));
    print_footer(d);
    setCursorPosition(d.y, d.x);
    ShowConsoleCursor(true);
}

void remove_row(Data d) {
    ShowConsoleCursor(false);
    setCursorPosition(0, static_cast<int>(d.people.size() + 1));
    print_footer(d);
    setCursorPosition(d.y, d.x);
    ShowConsoleCursor(true);
}

void print_footer(Data d) {
    ShowConsoleCursor(false);
    print_divider();
    std::cout << std::left;
    std::cout << "Navigate using arrow keys, press ";
    setColor(d, HELP_COLOR);
    std::cout << "'Enter'";
    setColor(d, WHITE);
    std::cout << " to edit the field.                                                        \nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'Backspace'";
    setColor(d, WHITE);
    std::cout << " to empty chosen cell                                          \nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'m'";
    setColor(d, WHITE);
    std::cout << " to create a new row on the next row and save the file.        \nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'n'";
    setColor(d, WHITE);
    std::cout << " to create a new row at the end of the table and save the file.\nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'r'";
    setColor(d, WHITE);
    std::cout << " to remove the line and save the file.                          \nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'s'";
    setColor(d, WHITE);
    std::cout << " to save the file.                      \nPress ";
    setColor(d, HELP_COLOR);
    std::cout << "'Esc'";
    setColor(d, WHITE);
    std::cout << "to exit.           \n                    ";
    ShowConsoleCursor(true);
}
