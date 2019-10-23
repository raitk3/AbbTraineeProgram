#include <iostream>
#include "my_library.h"

int main()
{
    int number;
    std::cout << "Insert a positive integer!" << "\n";
    std::cin >> number;
    printTriangle(StringTriangle(number));
}
