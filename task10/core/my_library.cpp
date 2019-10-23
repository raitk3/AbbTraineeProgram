#include "my_library.h"
#include <iostream>

std::string printCircle(int radius) {
    std::string circle;
    radius -= 1;
    for (int i = 0; i <= 2*radius; i++) {
        for (int j = 0; j <= 2*radius; j++) {
            if (pow(i - radius, 2) + pow(j - radius, 2) < pow(radius + 0.49, 2)) {
                circle += "*";
            } else {
                circle += " ";
            }

            if (j == 2*radius) {
                circle += "\n";
            }
        }
    }
    return circle;
}
