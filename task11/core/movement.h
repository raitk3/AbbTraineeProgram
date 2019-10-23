#pragma once

#include <iostream>

#include "front_end.h"
#include "back_end.h"

std::tuple<int, int> coordinatesCheck(BackEndData be, int x, int y);

bool movement(BackEndData& be, movements movement);
