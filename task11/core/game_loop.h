#pragma once
#include "back_end.h"
#include "front_end.h"
#include "movement.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20
#define NUMBER_OF_OBSTACLES 50

BackEndData askInput();

bool game_loop(BackEndData& be);
