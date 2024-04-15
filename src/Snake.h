#ifndef SNAKE_H
#define SNAKE_H

#include "drawable.h"

class Snake : public drawable {
private:
    int x, y;
public:
    Snake(int startX, int startY);
    int getX() const;
    int getY() const;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void draw() const override;
};

#endif

