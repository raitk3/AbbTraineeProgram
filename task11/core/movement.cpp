#include "front_end.h"
#include "back_end.h"
#include "movement.h"

std::tuple<int, int> coordinatesCheck(BackEndData be, int x, int y) {
    if (x < 0) {
        x = be.map_size_x - 1;
    } else if (y < 0) {
        y = be.map_size_y - 1;
    } else if (x >= be.map_size_x) {
        x = 0;
    } else if (y >= be.map_size_y) {
        y = 0;
    }
    return std::make_tuple(x, y);
}

// Move the player. Return if can make next move
bool movement(BackEndData& be, movements movement) {
    int nextX = be.player_x;
    int nextY = be.player_y;
    std::tuple<int, int> oldCoordinates = std::make_tuple(be.player_x, be.player_y);
    std::tuple<int, int> newCoordinates;
    switch (movement) {
        case UP:
            nextY -= 1;
            break;
        case DOWN:
            nextY += 1;
            break;
        case LEFT:
            nextX -= 1;
            break;
        case RIGHT:
            nextX += 1;
            break;
        default:
            break;
    }
    auto [realNextX, realNextY] = coordinatesCheck(be, nextX, nextY);
    newCoordinates = std::make_tuple(realNextX, realNextY);
    //Won't let go out of bounds.
    if (be.map.at(newCoordinates) == static_cast<char>(OBSTACLE)) {
        // Obstacle killed the player.
        std::cout << static_cast<char>(EMPTY_CELL);
        setCursorPosition(0, be.map_size_y);
        std::cout << "You lost!\n";
        return false;
    } else if (be.map.at(newCoordinates) == EXIT) {
        // VICTORY!
        std::cout << static_cast<char>(EMPTY_CELL);
        setCursorPosition(0, be.map_size_y);
        std::cout << "You won!\n";
        return false;
    } else {
        // Everything is normal.
        be.map.erase(oldCoordinates);
        be.map.insert(std::make_pair(oldCoordinates, EMPTY_CELL));
        setCursorPosition(be.player_x, be.player_y);
        std::cout << static_cast<char>(EMPTY_CELL);
        be.map.erase(newCoordinates);
        be.map.insert(std::make_pair(newCoordinates, PLAYER));
        setCursorPosition(realNextX, realNextY);
        std::cout << static_cast<char>(PLAYER);
        be.player_x = realNextX;
        be.player_y = realNextY;
        return true;
    }
}
