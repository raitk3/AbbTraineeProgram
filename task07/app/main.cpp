// Number guessing
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "numbers.h"

int main()
{
    Values values = initialize();
    std::cout << "Guess the number!" << std::endl;
    gameLoop(values);
}
