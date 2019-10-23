#pragma once

#include <map>
#include <vector>
#include <sstream>
#include "../data.h"
#include "../person/person.h"

//Read
std::map<int, Person> readFromCSV(Data d);

//Write
void writeCSV(Data d);
