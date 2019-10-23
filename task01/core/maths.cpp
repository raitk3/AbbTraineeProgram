#include "maths.h"
#include <iostream>
#include <cmath>

int findMin(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int findMax(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}

long long int findSum(int a, int b, int c) {
    long long int answer = static_cast<long long int>(a) + static_cast<long long int>(b) + static_cast<long long int>(c);
    return answer;
}

long double findProduct(int a, int b, int c) {
    long double answer = static_cast<long double>(a) * static_cast<long double>(b) * static_cast<long double>(c);
    return std::round(answer);
}

std::string calculateValues(int a, int b, int c) {
    int maxInt = findMax(a, b, c);
    int minInt = findMin(a, b, c);
    long long int sum = findSum(a, b, c);
    long double product = findProduct(a, b, c);
    return "Sum: " + std::to_string(sum) + " Product: " + std::to_string(product) + " Minimum: " + std::to_string(minInt) + " Maximum: " + std::to_string(maxInt);
}
