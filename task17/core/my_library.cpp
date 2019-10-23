#include "my_library.h"
#include <iostream>

std::string askName() {
    std::string file;
    std::cout << "Insert the full destination of the file you'd like to insert \n(e.g. 'C:\\Folder1\\Folder2\\file.txt')\n";
    std::cin >> file;
    return file;
}

std::vector<std::string> readLines(std::string filename) {
    std::string input_line;
    std::vector<std::string> lines;
    std::ifstream myFile (filename);
    if (myFile.is_open()) {
        while (std::getline(myFile, input_line)) {
            lines.push_back(input_line);
        }
        myFile.close();
    }
    return lines;
}

std::vector<std::string> switchLines (std::vector<std::string> lines) {
    std::vector<std::string> newLines;
    for (int i = 0; 2 * i < static_cast<int>(lines.size()); i++) {
        if (2*i + 1 < static_cast<int>(lines.size())) {
            newLines.push_back(lines.at(static_cast<unsigned long>(2 * i) + 1));
        }
        newLines.push_back(lines.at(static_cast<unsigned long>(2 * i)));
    }
    return newLines;
}

void writeFile(std::vector<std::string> lines, std::string filename) {
    std::ofstream newFile (filename);
    for (std::string line : lines) {
        newFile << line << std::endl;
    }
    newFile.close();
}
