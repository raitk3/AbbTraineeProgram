#pragma once

#include <string>
#include <windows.h>
#include <map>

#include "person/person.h"

struct Data {
    std::string database_location;

    HANDLE  hConsole;

    int x = 1;
    int y = 1;

    std::map<int, Person> people;
};
