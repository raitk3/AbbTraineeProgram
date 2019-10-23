#include "person.h"

Person::Person()
{
    std::string name;
    std::string surname;
    std::string gender;
    std::string position;
    std::string department;
    std::string birthday;
}
void Person::setName(std::string newName) {
    name = newName;
}

void Person::setSurname(std::string newSurname) {
    surname = newSurname;
}

void Person::setGender(std::string newGender) {
        gender = newGender;
}

void Person::setPosition(std::string newPosition) {
    position = newPosition;
}

void Person::setDepartment(std::string newDepartment) {
    department = newDepartment;
}

void Person::setBirthday(std::string newBirthday) {
    birthday = newBirthday;
}

void Person::setTelephone(int newTelephone) {
    telephone = newTelephone;
}

void Person::setSalary(int newSalary) {
    salary = newSalary;
}

std::string Person::printName() {
    if (name.length() > 10) {
        return name.substr(0, 7) + "...";
    }
    if (name.length() == 0) {
        return "N/A";
    }
    return name;
}

std::string Person::printSurname() {
    if (surname.length() > 12) {
        return surname.substr(0, 9) + "...";
    }
    if (surname.length() == 0) {
        return "N/A";
    }
    return surname;
}

std::string Person::printGender() {
    if (gender.length() == 0) {
        return "N/A";
    }
    return gender;
}

std::string Person::printPosition() {
    if (position.length() == 0) {
        return "N/A";
    }
    return position;
}

std::string Person::printDepartment() {
    if (department.length() == 0) {
        return "N/A";
    }
    return department;
}

std::string Person::printBirthday() {
    if (birthday.length() > 10) {
        return birthday.substr(0, 7) + "...";
    }
    if (birthday.length() == 0) {
        return "N/A";
    }
    return birthday;
}

std::string Person::printTelephone() {
    std::string number = std::to_string(telephone);
    if (number.length() > 11) {
        return number.substr(0, 8) + "...";
    }
    if (telephone == 0) {
        return "N/A";
    }
    return number;
}

std::string Person::printSalary() {
    std::string number = std::to_string(salary);
    if (number.length() > 6) {
        return number.substr(0, 3) + "...";
    }
    if (salary == 0) {
        return "N/A";
    }
    return number;
}


std::string Person::getName() {
    return name;
}

std::string Person::getSurname() {
    return surname;
}

std::string Person::getGender() {
    return gender;
}

std::string Person::getPosition() {
    return position;
}

std::string Person::getDepartment() {
    return department;
}

std::string Person::getBirthday() {
    return birthday;
}

int Person::getTelephone() {
    return telephone;
}

int Person::getSalary() {
    return salary;
}
std::string Person::toCSV() {
    return getName()
            + "," + getSurname()
            + "," + getGender()
            + "," + getPosition()
            + "," + getDepartment()
            + "," + getBirthday()
            + "," + std::to_string(getTelephone())
            + "," + std::to_string(getSalary());
}
