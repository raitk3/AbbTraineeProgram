#include "my_library.h"


long long SumOdd(int input) {
    if (input % 2 == 1) {
        return static_cast<long long>(std::pow((1 + input) / 2, 2));
    }
    return SumOdd(input - 1);
}
