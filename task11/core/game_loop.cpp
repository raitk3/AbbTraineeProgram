#include "front_end.h"
#include "back_end.h"
#include "movement.h"
#include "game_loop.h"


BackEndData askInput() {
    BackEndData newBE;
    //Customizability.
    char customize;
    std::cout << "Do you wish to customize the game?(Y/n)\n";
    std::cin >> customize;
    system("cls");
    while (customize != 78 && customize != 89 && customize != 110 && customize != 121) {
        std::cout << "Do you wish to customize the game?(Y/n)\n";
        std::cin >> customize;
        system("cls");
    }
    if (customize == 121 || customize == 89) {
        std::cout << "Select side length!\n";
        std::cin >> newBE.map_size_x;
        system("cls");
        while (newBE.map_size_x < 2) {
            std::cout << "Too small!\n";
            std::cin >> newBE.map_size_x;
            system("cls");
        }

        std::cout << "Select height!\n";
        std::cin >> newBE.map_size_y;
        system("cls");
        while (newBE.map_size_y < 2) {
            std::cout << "Too small!\n";
            std::cin >> newBE.map_size_y;
            system("cls");
        }

        std::cout << "Select number of obstacles! Max: " << newBE.map_size_x * newBE.map_size_y - 2 <<"." << std::endl;
        std::cin >> newBE.number_of_obstacles;
        system("cls");
        while (newBE.number_of_obstacles > newBE.map_size_x * newBE.map_size_y - 2) {
            std::cout << "Too many!\n";
            std::cin >> newBE.number_of_obstacles;
            system("cls");
        }
    } else {
            newBE.map_size_x = MAP_SIZE_X;
            newBE.map_size_y = MAP_SIZE_Y;
            newBE.number_of_obstacles = NUMBER_OF_OBSTACLES;
    }
    std::cout << "Loading..." << std::endl;
    return newBE;
}

bool game_loop(BackEndData& be) {
    movements directionGiven;
    setCursorPosition(be.player_x, be.player_y);

    // Processing input.
    switch (getch()) {
        case 72:
            directionGiven = UP;
            break;
        case 75:
            directionGiven = LEFT;
            break;
        case 80:
            directionGiven = DOWN;
            break;
        case 77:
            directionGiven = RIGHT;
            break;
        default:
            directionGiven = NONE;
    }

    if (!movement(be, directionGiven)) {
        return false;
    }
    return true;
}
