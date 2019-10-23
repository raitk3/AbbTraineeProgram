#include <algorithm>
#include <iostream>
#include "maths.h"

int main()
{
    int number;
    while(1) {
        std::cout << "Insert a number!" << std::endl;
        std::cin >> number;
        std::cout << isPrime(number) << std::endl;
    }
}
