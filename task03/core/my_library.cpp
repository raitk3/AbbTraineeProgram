#include "my_library.h"
#include <iostream>

std::vector<std::string> StringTriangle(int input) {
    std::vector<std::string> rows;
    std::string row;
    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1) {
                row += "*";
            } else {
            row += " *";
            }
        }
        rows.push_back(row);
        row = "";

    }
    return rows;
}

void printTriangle(std::vector<std::string> StringTriangle) {
    for (auto row : StringTriangle) {
        std::cout << row << "\n";
    }
}
