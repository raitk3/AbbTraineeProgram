#include "select.h"

//Position selecter tool.
void selectStuff(Data& d, int genPosOrDep) {
    std::vector<std::string> choices;
    int width;
    int numberOfChoices;
    int cursorPosition;
    std::vector<std::string>::iterator it;
    int index = 0;

    if (genPosOrDep == 0) {
        choices = genders;
        width = 6;
        cursorPosition = 3;
        it = std::find(choices.begin(), choices.end(), d.people.at(d.x).getGender());
    } else if (genPosOrDep == 1) {
        choices = positions;
        width = 19;
        cursorPosition = 4;
        it = std::find(choices.begin(), choices.end(), d.people.at(d.x).getPosition());
    } else if (genPosOrDep == 2) {
        choices = departments;
        width = 16;
        cursorPosition = 5;
        it = std::find(choices.begin(), choices.end(), d.people.at(d.x).getDepartment());
    }
    if (it != choices.end()) {
        index = static_cast<int>(it - choices.begin());
    }

    numberOfChoices = static_cast<int>(choices.size());

    bool chosen = false;
    Person personToChange = d.people.at(d.x);
    while (!chosen) {
        setColor(d, CHOSEN_COLOR);
        std::cout << std::setw(width) << std::left << choices.at(static_cast<unsigned long>(index));
        setCursorPosition(cursorPosition, d.x);
        switch (getch()) {
            // LEFT
            case 75:
                index = (index - 1) % numberOfChoices;
                if (index == -1) index += numberOfChoices;
                break;
            // RIGHT
            case 77:
                index = (index + 1) % numberOfChoices;
                break;
            // ENTER
            case 13:
                chosen = true;
                setColor(d, WHITE);
                std::cout << std::setw(width) << std::left << choices.at(static_cast<unsigned long>(index));
                switch (genPosOrDep) {
                    case 0:
                        personToChange.setGender(choices.at(static_cast<unsigned long>(index)));
                        break;
                    case 1:
                        personToChange.setPosition(choices.at(static_cast<unsigned long>(index)));
                        break;
                    case 2:
                        personToChange.setDepartment(choices.at(static_cast<unsigned long>(index)));
                }

                d.people.erase(d.x);
                d.people.insert(std::make_pair(d.x, personToChange));
                break;
        }
    }
}
