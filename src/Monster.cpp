#include "Monster.h"
#include <ncurses.h>
#include <cstdlib> // for random number generation

Monster::Monster(int w, int h) : x(rand() % width), y(rand() % height), width(w), height(h) {}

void Monster::move() {
    // Randomly change the monster's position
    int direction = rand() % 4;
    switch (direction) {
        case 0: // Move left
            if (x > 0) x--;
            break;
        case 1: // Move right
            if (x < width - 1) x++;
            break;
        case 2: // Move up
            if (y > 0) y--;
            break;
        case 3: // Move down
            if (y < height - 1) y++;
            break;
    }
}

int Monster::getX() const { return x; }

int Monster::getY() const { return y; }

void Monster::draw() const { printw("@"); }

void Monster::showoff() { x = rand() % width; y = rand() % height; }


