#include <fstream>
#include <iostream>
#include "csv.h"


//Read in from CSV.
std::map<int, Person> readFromCSV(Data d) {
    int row_index = 1;
    std::map<int, Person> people;
    bool quotationMarks = false;
    std::vector<std::string> words;
    char ch;
    std::string input;
    std::fstream fin(d.database_location, std::fstream::in);
    while (fin >> std::noskipws >> ch || fin.eof()) {
        if ((ch == 10 || fin.eof())) {
            if(fin.eof()) {
                break;
            }
            words.push_back(input);
            Person person;
            person.setName(words.at(0));
            if (words.size() > 1) person.setSurname(words.at(1));
            if (words.size() > 2) person.setGender(words.at(2));
            if (words.size() > 3) person.setPosition(words.at(3));
            if (words.size() > 4) person.setDepartment(words.at(4));
            if (words.size() > 5) person.setBirthday(words.at(5));
            if (words.size() > 6) {
                int telephone;
                std::istringstream iss (words.at(6));
                iss >> telephone;
                person.setTelephone(telephone);
                }
            if (words.size() > 7){
                int salary;
                std::istringstream iss2 (words.at(7));
                iss2 >> salary;
                person.setSalary(salary);
            }
            people.insert(std::make_pair(row_index, person));
            words.clear();
            input = "";
            row_index++;
        } else if (ch == 34) {
            quotationMarks = !quotationMarks;
        } else if (ch == 44 && !quotationMarks) {
            words.push_back(input);
            input = "";
        } else if (ch == 44 && quotationMarks) {
            input += ch;
        } else {
            input += ch;
        }
    }
    return people;
}

// Write the CSV file.
void writeCSV(Data d) {
    std::string output;
    for (auto person: d.people) {
        output += person.second.toCSV() + "\n";
    }
    std::ofstream newFile (d.database_location);
    newFile << output;
    newFile.close();
}
