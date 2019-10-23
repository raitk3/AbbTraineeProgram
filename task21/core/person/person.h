#pragma once

#include <string>
#ifndef PERSON_H
#define PERSON_H


class Person
{
    std::string name;
    std::string surname;
    std::string gender;
    std::string position;
    std::string department;
    std::string birthday;
    int telephone = 0;
    int salary = 0;

public:
    Person();

    void setName(std::string newName);

    void setSurname(std::string newSurname);

    void setGender(std::string newGender);

    void setPosition(std::string newPosition);

    void setDepartment(std::string newDepartment);

    void setBirthday(std::string newBirthday);

    void setTelephone(int newTelephone);

    void setSalary(int newSalary);

    std::string printName();

    std::string printSurname();

    std::string printGender();

    std::string printPosition();

    std::string printDepartment();

    std::string printBirthday();

    std::string printTelephone();

    std::string printSalary();

    std::string getName();

    std::string getSurname();

    std::string getGender();

    std::string getPosition();

    std::string getDepartment();

    std::string getBirthday();

    int getTelephone();

    int getSalary();

    std::string toCSV();
};

#endif // PERSON_H
