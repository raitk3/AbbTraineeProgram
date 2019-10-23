#pragma once
#include <string>
#include <sstream>
#include "../../data.h"
#include "../../person/person.h"

std::string getData(Data d, Person personToChange);

Person setData(Data& d, Person personToChange, std::string newData);
