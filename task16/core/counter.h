#pragma once

#include <tuple>
#include <vector>

#define UPPER_LOW 65
#define UPPER_HIGH 90
#define LOWER_LOW 97
#define LOWER_HIGH 122
#define NUM_LOW 48
#define NUM_HIGH 57

std::tuple<int, int, int, int> getCount(std::vector<char> chars);
