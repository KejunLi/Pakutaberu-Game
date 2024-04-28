#ifndef MONSTER_H
#define MONSTER_H

#include "abstractDraw.h"

class Monster: public abstractDraw {
private:
    int x, y;
    int width, height;
public:
    Monster(int width, int height);
    int getX() const;
    int getY() const;
    void move();
    void showoff();
    void draw() const override;
};

#endif

