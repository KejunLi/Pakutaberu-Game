#ifndef DRAWABLE_H
#define DRAWABLE_H

class drawable {
public:
    virtual void draw() const = 0;
    virtual ~drawable() {};
};

#endif

