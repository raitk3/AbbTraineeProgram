#include "space_add.h"
#include <iostream>

std::string spaceAdd(std::string stringToManipulate)
{
    if (stringToManipulate.size() == 1) {
        return stringToManipulate;
    } else {
        return stringToManipulate.substr (0, 1) + "     " + spaceAdd(stringToManipulate.substr(1));
    }
}
