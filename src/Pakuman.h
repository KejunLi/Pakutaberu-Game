#ifndef SNAKE_H
#define SNAKE_H

#include "abstractDraw.h"

class Pakuman : public abstractDraw {
private:
    int x, y;
public:
    Pakuman(int startX, int startY);
    int getX() const override;
    int getY() const override;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void draw() const override;
};

#endif

