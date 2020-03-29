#pragma once

#include "Vec2D.hpp"
#include <vector>

class Shape {

public:
    virtual Vec2D GetCenterPoint() const = 0;
    // We won't really need this but this is for the compiler.
    virtual ~Shape(){}
    inline virtual std::vector<Vec2D> GetPoints() const {return mPoints;}
    // This allows us to move the shape by some delta
    void MoveBy(const Vec2D& deltaOffset);

//Anyone that inherits from this class will need access to the data.
protected:
    std::vector<Vec2D> mPoints;
};