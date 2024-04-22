#ifndef DRAWABLE_H
#define DRAWABLE_H

class abstractDrawable {
public:
    virtual void draw() const = 0;
    virtual ~abstractDrawable() {};
};

#endif

