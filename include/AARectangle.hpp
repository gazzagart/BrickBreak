#pragma once

#include "Shape.hpp"

// Axis Aligned Rectangle

class AARectangle: public Shape {

public:
    AARectangle();
    AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height);
    AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight);

    inline void SetTopLeftPoint(const Vec2D& topLeft) {mPoints[0] = topLeft;}
    inline void SetBottomRightPoint (const Vec2D& bottomRight) {mPoints[1] = bottomRight;}

    Vec2D GetTopLeftPoint() const {return mPoints[0];}
    Vec2D GetBottomRightPoint() const {return mPoints[1];}

    float GetWidth() const;
    float GetHeight() const;

    void MoveTo(const Vec2D& position);

    virtual Vec2D GetCenterPoint() const override;

    bool Intersersects(const AARectangle& otherRect) const;
    bool ContainsPoint(const Vec2D& point) const;
    // Given the rectangle being passed, we make a smaller rectangle within it, based on the insetes being passed.
    static AARectangle Inset(const AARectangle& rect, Vec2D& insets);

    // We need to pass four points back here because this is a rectangle.
    virtual std::vector<Vec2D> GetPoints() const override;
};