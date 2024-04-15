#ifndef FRUIT_H
#define FRUIT_H

#include "drawable.h"

class Fruit: public drawable {
private:
    int x, y;
    const int width, height;
public:
    Fruit(const int width, const int height);
    void respawn();
    int getX() const;
    int getY() const;
    void draw() const override;
};

#endif

