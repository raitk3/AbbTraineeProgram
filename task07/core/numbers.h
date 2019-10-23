#pragma once

#include <string>
#include <iostream>
#include <random>
#include <time.h>

#include "values.h"

Status loopCheckInput(Values& values);

void gameLoop(Values& values);

Values initialize();
