#ifndef DRAWABLE_H
#define DRAWABLE_H

class abstractDraw {
public:
    virtual void draw() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual ~abstractDraw() {};
};

#endif

