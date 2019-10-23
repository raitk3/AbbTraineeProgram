#include "back_end.h"
#include "movement.h"


BackEndData mapGenerate(BackEndData m) {
    std::map<std::tuple<int, int>, char> map;
    std::tuple<int, int> coordinates;
    for (int i = 0; i < m.map_size_y; i++) {
        for (int j = 0; j < m.map_size_x; j++) {
            coordinates = std::make_tuple(j, i);
            map.insert(std::pair(coordinates, EMPTY_CELL));
        }
    }
    m.map = map;
    return m;
}

int calculateShortestRoute(BackEndData gbe) {
    int minX = std::min(std::abs(gbe.player_x - gbe.exit_x),(std::abs((gbe.player_x - gbe.exit_x)) - gbe.map_size_x) % gbe.map_size_x);
    int minY = std::min(std::abs(gbe.player_y - gbe.exit_y),(std::abs((gbe.player_y - gbe.exit_y)) - gbe.map_size_y) % gbe.map_size_y);
    return minX + minY + 1;
}


//Generate obstacles, exit and player.
BackEndData initialize(BackEndData m) {
    float percentage = 0.0;
    BackEndData nm = m;
    srand(time(NULL));
    nm = addPlayerOrExit(nm, PLAYER);
    nm = addPlayerOrExit(nm, EXIT);
    if (nm.number_of_obstacles > static_cast<int>(nm.map.size()) - calculateShortestRoute(nm) - 1) {
        nm.number_of_obstacles = static_cast<int>(nm.map.size()) - calculateShortestRoute(nm);
    }
    for (int obstacle = 1; obstacle <= nm.number_of_obstacles;) {
       nm = addObstacle(nm, obstacle);
       percentage = static_cast<float>(obstacle - 1) / static_cast<float>(nm.number_of_obstacles) * 100;
       setCursorPosition(10, 0);
       std::cout << std::round(percentage) << "%";

    }
    return nm;
}

BackEndData addPlayerOrExit(BackEndData be, char PlayerOrExit) {
    BackEndData nbe = be;
    int x = std::rand() % (nbe.map_size_x);
    int y = std::rand() % (nbe.map_size_y);
    std::tuple<int, int> coordinates = std::make_tuple(x, y);
    while (be.map.at(coordinates) != EMPTY_CELL) {
        x = std::rand() % (nbe.map_size_x);
        y = std::rand() % (nbe.map_size_y);
        coordinates = std::make_tuple(x, y);
    }
    nbe = replaceObject(nbe, coordinates, PlayerOrExit);
    if (PlayerOrExit == PLAYER) {
    nbe.player_x = x;
    nbe.player_y = y;
    } else {
        nbe.exit_x = x;
        nbe.exit_y = y;
    }
    return nbe;
}

BackEndData addObstacle(BackEndData be, int& obstacle) {
    BackEndData nbe = be;
    std::vector<std::tuple<int, int>> checkedLocations;
    int x;
    int y;
    std::tuple<int, int> coordinates = std::make_tuple(x, y);
    int cycleCount = 0;
    while (true) {
        nbe = be;
        x = std::rand() % (be.map_size_x);
        y = std::rand() % (be.map_size_y);
        coordinates = std::make_tuple(x, y);
        while (nbe.map.at(std::make_tuple(x, y)) != EMPTY_CELL) {
            x = std::rand() % (be.map_size_x);
            y = std::rand() % (be.map_size_y);
            coordinates = std::make_tuple(x, y);
        }
        nbe = replaceObject(nbe, coordinates, OBSTACLE);
        checkedLocations = {};
        if (hasRoute(nbe, checkedLocations, std::make_tuple(nbe.player_x, nbe.player_y))){
            obstacle++;
            return nbe;
        } else if (cycleCount == 500) {
            obstacle++;
            cycleCount = 0;
            break;
        } else {
            cycleCount++;
        }
    }
    return be;
}

BackEndData replaceObject(BackEndData be, std::tuple<int, int> coordinates, char object) {
    BackEndData nbe = be;
    nbe.map.erase(coordinates);
    nbe.map.insert(std::make_pair(coordinates, object));
    return nbe;
}


bool hasRoute (BackEndData be, std::vector<std::tuple<int, int>>& visitedAlready, std::tuple<int, int> playerLocation) {
    std::vector<std::tuple<int, int>> surroundings {
        coordinatesCheck(be, std::get<0>(playerLocation) + 1, std::get<1>(playerLocation)),
        coordinatesCheck(be, std::get<0>(playerLocation) - 1, std::get<1>(playerLocation)),
        coordinatesCheck(be, std::get<0>(playerLocation), std::get<1>(playerLocation) + 1),
        coordinatesCheck(be, std::get<0>(playerLocation), std::get<1>(playerLocation) - 1)
    };
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    visitedAlready.push_back(playerLocation);
    if (be.map.at(playerLocation) == OBSTACLE) {
        return false;
    }
    for (auto el : surroundings) {
        if (be.map.count(el) && be.map.at(el) == EXIT) {
            return true;
        }
    }
    if (std::find(visitedAlready.begin(), visitedAlready.end(), surroundings.at(0)) == visitedAlready.end()) {
        down = hasRoute(be, visitedAlready, surroundings.at(0));
    }
    if (std::find(visitedAlready.begin(), visitedAlready.end(), surroundings.at(1)) == visitedAlready.end()) {
        up = hasRoute(be, visitedAlready, surroundings.at(1));
    }
    if (std::find(visitedAlready.begin(), visitedAlready.end(), surroundings.at(2)) == visitedAlready.end()) {
        right = hasRoute(be, visitedAlready, surroundings.at(2));
    }
    if (std::find(visitedAlready.begin(), visitedAlready.end(), surroundings.at(3)) == visitedAlready.end()) {
        left = hasRoute(be, visitedAlready, surroundings.at(3));
    }
    return (up || down || left || right);
}
