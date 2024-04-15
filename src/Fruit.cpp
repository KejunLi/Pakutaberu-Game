#include "Fruit.h"
#include <ncurses.h>
#include <cstdlib>

Fruit::Fruit(const int w, const int h) : x(0), y(0), width(w), height(h) {}

void Fruit::respawn() { x = rand() % width; y = rand() % height; }

int Fruit::getX() const { return x; }

int Fruit::getY() const { return y; }

void Fruit::draw() const {
    mvprintw(y, x, "F"); // Draw the fruit at its position
}

