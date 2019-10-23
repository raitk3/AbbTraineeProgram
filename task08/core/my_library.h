#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_Y 30 // 30
#define MAP_SIZE_X 50 // 50
#define MIN_STARS 50 // 50
#define MAX_STARS 150 // 150
#define DIFF_MIN_MAX_STARS MAX_STARS-MIN_STARS //100
#define EMPTY_CELL 32
#define FILLED_CELL 42

std::vector<std::vector<char>> mapGenerate();

void print(std::vector<std::vector<char>> map);

std::vector<std::vector<char>> replace(std::vector<std::vector<char>> map, int x, int y);

std::vector<std::vector<char>> addStars(std::vector<std::vector<char>> map, int numberOfStars);
