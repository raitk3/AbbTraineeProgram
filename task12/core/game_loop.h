#pragma once
#include "backend/game_backend.h"
#include "frontend/game_frontend.h"
#include <windows.h>


bool gameLoop(GameBackEnd& gbe, GameFrontEnd& gfe, HANDLE& hConsole);

std::tuple<int, int, int, char, WORD, char, WORD> askInput(HANDLE& hConsole);

void printHint(HANDLE& hConsole);
