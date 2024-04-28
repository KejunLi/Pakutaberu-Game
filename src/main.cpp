#include "Game.h"
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

int main() {
    Game game(30, 20, 3, 2);
    game.Setup();
    while (!game.isGameOver()) {
        game.Draw();
        game.Input();
        game.Logic();
        if (game.getScore() <= 100)
            usleep(100000); // Sleep for 0.1 seconds
        else if (game.getScore() > 100 && game.getScore() < 200)
            usleep(10000); // Increase the speed by sleeping for 0.01 seconds
        else
            usleep(2000);
    }
    printw("Press any key to exit...");
    refresh();
    timeout(-1);
    getch();
    
    endwin(); // End ncurses mode
    return 0;
}

