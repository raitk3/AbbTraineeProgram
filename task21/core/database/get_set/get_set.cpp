#include "get_set.h"

std::string getData(Data d, Person personToChange) {
    std::string newData;
    switch (d.y){
        case 1:
            newData = personToChange.getName();
            break;
        case 2:
            newData = personToChange.getSurname();
            break;
        case 6:
            newData = personToChange.getBirthday();
            break;
        case 7:
            newData = std::to_string(personToChange.getTelephone());
            break;
        case 8:
            newData = std::to_string(personToChange.getSalary());
            break;
    }
    return newData;
}

Person setData(Data& d, Person personToChange, std::string newData) {
    int number;
    std::istringstream iss (newData);
    iss >> number;
    if (iss.fail()) {
    }
    switch (d.y){
        case 1:
            personToChange.setName(newData);
            break;
        case 2:
            personToChange.setSurname(newData);
            break;
        case 3:
            personToChange.setGender(newData);
            break;
        case 4:
            personToChange.setPosition(newData);
            break;
        case 5:
            personToChange.setDepartment(newData);
            break;
        case 6:
            personToChange.setBirthday(newData);
            break;
        case 7:
            personToChange.setTelephone(number);
            break;
        case 8:
            personToChange.setSalary(number);
            break;
    }
    return personToChange;
}
