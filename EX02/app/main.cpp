#include <algorithm>
#include <iostream>
#include "maths.h"

int main()
{
    int shape, side;
    double area;
    while(true) {
        std::cout << "What's the shape?" << std::endl;
        shape = askInput();
        if (shape > 0) {
            if (shape == 2) {
                std::cout << "What's the radius?" << std::endl;
            } else {
                std::cout << "What's the length of the side?" << std::endl;
            }
            std::cin >> side;
            area = calculateArea(shape, side);
            std::cout << "The area is " << area << std::endl;
        } else {
        std::cout << "Insert correct shape!" << std::endl;
        }
    }
}
