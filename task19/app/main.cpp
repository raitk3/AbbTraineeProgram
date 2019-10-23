#include "my_library.h"

int main()
{
    int max_length = 0;
    int row_index = 1;
    std::string myFileName;
    std::string input;
    std::cout << "Insert the full destination of the file you'd like to insert \n(e.g. 'C:\\\\Folder1\\\\Folder2\\\\file.txt')\n";
    std::cin >> myFileName;
    std::string text = getTextFromCsv(myFileName);
    std::map<int, std::vector<std::string>> rows = parser(text, row_index, max_length);
    print_Table(rows, max_length, row_index);

}
