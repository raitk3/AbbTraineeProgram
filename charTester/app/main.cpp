#include <iostream>
#include <conio.h>

int main()
{
    while(true) {
        int character = getch();
    std::cout << static_cast<char>(character) << " : " << character << "\n";
    }
}
