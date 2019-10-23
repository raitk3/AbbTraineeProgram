#include "my_library.h"
#include <iostream>

//Parse the text.
std::string parser(std::string input_string) {
    std::string parsedText;
    bool quotationMarks = false;
    for ( char ch : input_string) {
        if (!quotationMarks && ch == SEMICOLON) {
            parsedText += "\n";
        } else if (ch == QUOTATION_MARKS) {
            parsedText += ch;
            quotationMarks = !quotationMarks;
        } else {
            parsedText += ch;
        }
    }
    return parsedText.substr(0, parsedText.size() - 1);
}

//Write the file
void write(std::string filename, std::string text) {
    std::ofstream newFile (filename);
    newFile << text;
    newFile.close();
}
