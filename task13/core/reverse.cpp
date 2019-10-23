#include "reverse.h"
#include <iostream>

std::string reverse(std::string word) {
    if (word.size() == 1) {
        return word;
    } else {
        return reverse(word.substr(1)) + word.substr(0, 1);
    }
}
