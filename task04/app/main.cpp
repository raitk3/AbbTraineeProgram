// Exercise 4.
#include <iostream>
#include <string>

#include "space_add.h"

int main()
{
  std::string number;
  std::cout << "Enter a multiple digit number!";
  getline (std::cin, number);
  std::cout << spaceAdd(number) << std::endl;
}
