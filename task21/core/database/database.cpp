#include "database.h"

//Add a new blank person into the end of the file.
void addPerson(Data& d) {
    Person newPerson;
    int i = 1;
    bool added = false;
    while (!added) {
        if (!d.people.count(i)) {
            d.people.insert(std::make_pair(i, newPerson));
            added = true;
        }
        i++;
    }
    setCursorPosition(0, d.x);
    draw_new_row(d);
    if (d.people.size() == 1) {
        d.x = 1;
    }
}

//Add a new blank person.
void addPersonNextLine(Data& d) {
    int previous_dx = d.x;
    for (d.x = static_cast<int>(d.people.size() + 2); d.x -1 > previous_dx; d.x--) {
        setCursorPosition(0, d.x);
        if (d.x == static_cast<int>((d.people.size() + 2))) {
            print_footer(d);
        } else {
            d.people.insert(std::make_pair(d.x, d.people.at(d.x - 1)));
            d.people.erase(d.x - 1);
            draw_line(d, false);
        }
    }
    Person person;
    d.people.insert(std::make_pair(d.x, person));
    setCursorPosition(0, d.x);
    draw_line(d, true);
}

//Remove selected person and defrag people.
void removePerson(Data& d) {
    int prev_x = d.x;
    d.people.erase(d.x);
    while (d.people.count(d.x + 1)) {
        d.people.insert(std::make_pair(d.x, d.people.at(d.x + 1)));
        setCursorPosition(0, d.x);
        draw_line(d, false);
        d.people.erase(d.x + 1);
        d.x += 1;
    }
    d.x = prev_x;
    remove_row(d);
    setCursorPosition(d.y, d.x);
}

//Remove data from selected cell.
void nullData(Data& d) {
    Person personToChange = d.people.at(d.x);
    std::string newData;
    personToChange = setData(d, personToChange, newData);
    d.people.erase(d.x);
    d.people.insert(std::make_pair(d.x, personToChange));
    setCursorPosition(0, d.x);
    draw_line(d, false);
}

//Change persons data.
void changeData(Data& d) {
    bool chosen = false;
    Person personToChange = d.people.at(d.x);
    setColor(d, CHOSEN_COLOR);

    std::string newData = getData(d, personToChange);


    while (!chosen) {
        if (newData == "" || newData == "0") {
            std::cout << "   ";
        }
        setCursorPosition(d.y, d.x);
        for (int i = 0; i <= static_cast<int>(newData.size()); i++) std::cout << " ";
        setCursorPosition(d.y, d.x);
        if (!((d.y == 7 || d.y == 8) && newData == "0")) {
            std::cout << newData;
        } else {
            newData = "";
        }
        int input = getch();
        if (input == 0 || input == 224) {
            getch();
        } else if (input > 31) {
            newData += static_cast<char>(input);
        } else if (input == 8) {
            setCursorPosition(d.y, d.x);
            newData = newData.substr(0, newData.size() - 1);
        } else if (input == 13) {
            chosen = true;
        }
    }
    setColor(d, WHITE);
    if (newData.size() > 0) {
        personToChange = setData(d, personToChange, newData);
    }
    d.people.erase(d.x);
    d.people.insert(std::make_pair(d.x, personToChange));
    setCursorPosition(0, d.x);
    draw_line(d, false);
}
