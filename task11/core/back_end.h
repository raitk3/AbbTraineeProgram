#pragma once
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include <tgmath.h>

#define EMPTY_CELL 46
#define OBSTACLE 84
#define PLAYER 71
#define EXIT 88

struct BackEndData {
        int map_size_x;
        int map_size_y;
        int player_x;
        int player_y;
        int exit_x;
        int exit_y;
        int number_of_obstacles;
        std::map<std::tuple<int, int>, char> map;
};

enum movements {UP, DOWN, LEFT, RIGHT, NONE};

BackEndData mapGenerate(BackEndData m);

BackEndData initialize(BackEndData m);

BackEndData addPlayerOrExit(BackEndData be, char PlayerOrExit);

BackEndData addObstacle(BackEndData be, int& obstacle);

BackEndData replaceObject(BackEndData be, std::tuple<int, int> coordinates, char object);

bool hasRoute (BackEndData be, std::vector<std::tuple<int, int>>& visitedAlready, std::tuple<int, int> playerLocation);
