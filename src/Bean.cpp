#include "Bean.h"
#include <ncurses.h>
#include <cstdlib> // for random number generation

Bean::Bean(int w, int h) : x(0), y(0), width(w), height(h) {}

void Bean::respawn() { x = rand() % width; y = rand() % height; }

int Bean::getX() const { return x; }

int Bean::getY() const { return y; }

void Bean::draw() const {
    printw("w"); // Draw the fruit at its position
}


