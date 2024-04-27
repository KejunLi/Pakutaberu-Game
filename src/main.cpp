#include "Game.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    Game game(30, 10, 3);
    game.Setup();
    while (!game.isGameOver()) {
        game.Draw();
        game.Input();
        game.Logic();
        usleep(100000); // Sleep for 0.1 seconds
    }
    endwin(); // End ncurses mode
    return 0;
}

