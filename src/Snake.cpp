#include "Snake.h"
#include <ncurses.h>

Snake::Snake(int startX, int startY) : x(startX), y(startY) {}

int Snake::getX() const { return x; }

int Snake::getY() const { return y; }

void Snake::moveLeft() { x--; }

void Snake::moveRight() { x++; }

void Snake::moveUp() { y--; }

void Snake::moveDown() { y++; }

void Snake::draw() const {
    mvprintw(y, x, "o"); // Draw the snake at its position
}

