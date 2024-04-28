#include "Pakuman.h"
#include <ncurses.h>

Pakuman::Pakuman(int startX, int startY) : x(startX), y(startY) {}

int Pakuman::getX() const { return x; }

int Pakuman::getY() const { return y; }

void Pakuman::moveLeft() { x--; }

void Pakuman::moveRight() { x++; }

void Pakuman::moveUp() { y--; }

void Pakuman::moveDown() { y++; }

void Pakuman::draw() const {
    printw("o"); // Draw the snake at its position
}

