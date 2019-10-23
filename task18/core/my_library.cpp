#include "my_library.h"
#include <iostream>

std::string readFile() {
    char ch;
    std::string myFileName;
    std::string source_text;
    std::cout << "Insert the full destination of the file you'd like to insert \n(e.g. 'C:\\\\Folder1\\\\Folder2\\\\file.txt')\n";
    std::cin >> myFileName;
    std::fstream fin(myFileName, std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        source_text += ch;
    }
    if (source_text.size()== 0) {
        std::cout << "No text!\n";
        return "";
    }
    return source_text;
}

std::tuple<char, int, char> getBeginEnd() {
    char index;
    int length;
    char end;
    std::cout << "Insert first char, length and destination char!" << std::endl;
    std::cin >> index;
    std::cin >> length;
    std::cin >> end;
    return std::make_tuple(index, length, end);
}

std::string get_text(std::string source_text, char index, int length, char end) {
    std::string printableText;
    bool print = false;
    int print_index = 0;
    for (char character : source_text) {
        if ((print && character == end) || print_index == length - 1) {
            printableText += character;
            break;
        } else if (character == index) {
            print = true;
            print_index++;
            printableText += character;
        } else if (print) {
            print_index++;
            printableText += character;
        }

    }
    return printableText;
}

void printText(std::string text) {
    if (text.length() == 0) {
        std::cout << "Nothing to print!" << std::endl;
    } else {
        std::cout << text << std::endl;
    }
}
