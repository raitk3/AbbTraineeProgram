#include "my_library.h"
#include <iostream>

std::vector<std::vector<char>> mapGenerate() {
    std::vector<std::vector<char>> newRows;
    for (int i = 0; i < MAP_SIZE_Y; i++) {
        std::vector<char> row;
        row.assign(MAP_SIZE_X, EMPTY_CELL);
        newRows.push_back(row);
    }
    return newRows;
}

void print(std::vector<std::vector<char>> map) {
    for (auto row:map) {
        for (auto element:row) {
            std::cout << element;
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<char>> replace(std::vector<std::vector<char>> map, int x, int y) {
    std::vector<char> newRow = map.at(y);
    std::replace(newRow.begin() + x, newRow.begin() + x + 1, EMPTY_CELL, FILLED_CELL);
    std::replace(map.begin() + y, map.begin() + y + 1, map.at(y), newRow);
    return map;
}

std::vector<std::vector<char>> addStars(std::vector<std::vector<char>> map, int numberOfStars) {
    std::vector<std::vector<char>> newMap = map;
    int xToReplace;
    int yToReplace;
    for (int i = 0; i < numberOfStars;) {
        xToReplace = rand() % MAP_SIZE_X;
        yToReplace = rand() % MAP_SIZE_Y;
        if (newMap.at(yToReplace).at(xToReplace) == EMPTY_CELL) {
            newMap = replace(newMap, xToReplace, yToReplace);
            i++;
        }
    }
    return newMap;
}
