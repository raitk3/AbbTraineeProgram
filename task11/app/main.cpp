#include <iostream>

#include "front_end.h"
#include "back_end.h"
#include "game_loop.h"
#include "movement.h"

int main() {

    ShowConsoleCursor(false);
    BackEndData backEnd = askInput();
    backEnd = mapGenerate(backEnd);
    backEnd = initialize(backEnd);
    print(backEnd);

    // Game-loop.
    while (game_loop(backEnd));
}
