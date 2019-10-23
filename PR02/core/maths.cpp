#include "maths.h"
#include <iostream>
#include <cmath>

bool isPrime(int number) {
    /*
     * Check if number is prime.
     */
    if (number < 2) return false;
    else if (number < 4) return true;
    else {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
}
