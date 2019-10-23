#include "maths.h"
#include <iostream>
#include <cmath>

int askInput() {
    std::string actualShape;
    std::cin >> actualShape;
    if (actualShape == "square") return 1;
    else if (actualShape == "circle") return 2;
    else if (actualShape == "triangle") return 3;
    return 0;
}


double calculateArea(int shape, int side) {
    if (shape == 1) {
        return pow(side, 2);
    } else if (shape == 2) {
        return M_PI * pow(side, 2);
    } else {
        return (side * (side * sqrt(3) / 2)) / 2;
    }
}
