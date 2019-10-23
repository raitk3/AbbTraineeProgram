#include "characters.h"


std::vector<std::string> createVector(std::string input) {
    std::vector<std::string> newRow;
    std::string newString;
    for (int row = 0; row < 9; row++){
        std::string stringToPrint;
        for (int i = 0; i < input.size(); i++) {
            if (i != 0){
                newString += " ";
            }
            stringToPrint = returnRow(row, input.at(i));
            newString += stringToPrint;
        }
        newRow.push_back(newString);
        newString = "";
    }
    return newRow;
}
std::string returnRow(int row, char character) {
    std::string stringToPrint = "*****";
    if (charsMap.count(character)) {
        stringToPrint = charsMap.at(character).at(row);
    }
    return stringToPrint;
}
