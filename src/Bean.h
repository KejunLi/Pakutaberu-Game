#ifndef FRUIT_H
#define FRUIT_H

#include "abstractDraw.h"

class Bean: public abstractDraw {
private:
    int x, y;
    int width, height;
public:
    Bean(int width, int height);
    void respawn();
    int getX() const;
    int getY() const;
    void draw() const override;
};

#endif

