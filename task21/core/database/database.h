#pragma once

#include <iostream>
#include <map>
#include <algorithm>

#include "../colors/colors.h"
#include "move/move.h"
#include "get_set/get_set.h"
#include "../person/person.h"
#include "../table/table.h"
#include "../csv/csv.h"
#include "../useful_vectors/useful_vectors.h"

void selectStuff(Data& d, int genPosOrDep);

void addPerson(Data& d);

void addPersonNextLine(Data& d);

void changeData(Data& d);

void nullData(Data& d);

void removePerson(Data& d);
