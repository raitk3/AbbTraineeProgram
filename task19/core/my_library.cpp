#include "my_library.h"
#include <iostream>

//Print the table.
void print_Table(std::map<int, std::vector<std::string>> rows, int max_length, int number_of_rows) {
    for (int i = 1; i < number_of_rows; i++) {
        std::cout << "| ";
        for (std::string word : rows.at(i)) {
            std::cout << std::setw(max_length) << word << " | ";
        }
        std::cout << "\n";
    }
}

std::string getTextFromCsv(std::string myFileName) {
    std::string string;
    char ch;
    std::fstream fin(myFileName, std::fstream::in);
    while (fin >> std::noskipws >> ch && !fin.eof()) {
        string += ch;
    }
    string += "\n";
    return string;
}

//Parse the text.
std::map<int, std::vector<std::string>> parser(std::string string, int& row_index, int& max_length) {
    std::map<int, std::vector<std::string>> rows;
    bool quotationMarks = false;
    std::vector<std::string> words;
    std::string input;
    for (char ch : string) {
        if (ch == NEW_LINE) {
            if (static_cast<int>(input.length()) > max_length) {
                max_length = static_cast<int>(input.length());
            }
            words.push_back(input);
            rows.insert(std::make_pair(row_index, words));
            words.clear();
            input = "";
            row_index++;
        } else if (ch == QUOTATION_MARK) {
            quotationMarks = !quotationMarks;
        } else if (ch == COMMA && !quotationMarks) {
            if (static_cast<int>(input.length()) > max_length) {
                max_length = static_cast<int>(input.length());
            }
            words.push_back(input);
            input = "";
        } else if (ch == COMMA && quotationMarks) {
            input += ch;
        } else {
            input += ch;
        }
    }
    return rows;
}
