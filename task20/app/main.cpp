#include "my_library.h"

int main()
{
    std::string input_string;
    std::string file_name;
    std::cout << "Insert new filename! ('...\\file.csv')\n";
    std::cin >> file_name;
    std::cout << "Insert your data to e converted to csv (',' to separate elements, ';' to separate rows.\n";
    std::cin >> input_string;
    std::string rows = parser(input_string);
    write(file_name, rows);
}
