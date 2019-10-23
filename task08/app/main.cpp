#include "my_library.h"


int main() {
    srand(time(NULL));
    int numberOfStars;
    if (DIFF_MIN_MAX_STARS <= 0) {
        numberOfStars = MIN_STARS;
    } else {    numberOfStars = rand() % DIFF_MIN_MAX_STARS + MIN_STARS;
    }
    std::vector<std::vector<char>> map = mapGenerate();
    if (numberOfStars > MAP_SIZE_X * MAP_SIZE_Y) {
        numberOfStars = MAP_SIZE_X * MAP_SIZE_Y;
    }
    map = addStars(map, numberOfStars);
    print(map);

}
