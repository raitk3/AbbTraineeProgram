#include <iostream>
#include "my_library.h"

int main()
{
  int number;
  std::cout << "Enter a positive integer: ";
  std::cin >> number;
  std::cout << "Sum: " << std::to_string(SumOdd(number)) << "\n";
}
