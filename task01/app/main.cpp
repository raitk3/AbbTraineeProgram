#include <algorithm>
#include <iostream>
#include "maths.h"

int main()
{
  int integer1, integer2, integer3;

  std::cout << "Enter 3 integers! ";
  std::cin >> integer1;
  std::cin >> integer2;
  std::cin >> integer3;
  std::cout << calculateValues(integer1, integer2, integer3) << "\n";
}
