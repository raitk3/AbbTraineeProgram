#include "file_read.h"

#include <fstream>

std::vector<char> getLetters () {
    char ch;
    std::string myFileName;
    std::cout << "Insert the full destination of the file you'd like to insert \n(e.g. 'C:\\Folder1\\Folder2\\file.txt')\n";
    std::cin >> myFileName;
    std::vector<char> letters;
    std::fstream fin(myFileName, std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        letters.push_back(ch);
    }
    return letters;
}
