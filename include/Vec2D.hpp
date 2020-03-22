#ifndef VEC2D_H_
#define VEC2D_H_

#include <iostream>
#include <string>

class Vec2D
{
public:

    static const Vec2D Zero;

    Vec2D(): Vec2D(0,0){}
    Vec2D(float x, float y): mX(x), mY(y){}

    inline void SetX(float x) {mX = x;}
    inline void SetY(float y) {mY = y;}
    inline float GetX() const {return mX;}
    inline float GetY() const {return mY;}

    friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);

    bool operator==(const Vec2D& vec2) const;
    bool operator!=(const Vec2D& vec2) const;

    Vec2D operator-() const;
    Vec2D operator*(float scale) const;
    Vec2D operator/(float scale) const;
    Vec2D& operator*=(float scale); // These are references
    Vec2D& operator/=(float scale);
    // This takes the scaler first then multiply the vector to allow one to:
    // 3 * Vec2D
    friend Vec2D operator*(float scaler, const Vec2D& vec); //? Why is this a friend function and not a member? -> https://www.learncpp.com/cpp-tutorial/94-overloading-operators-using-member-functions/
    //? Similarly, although we can overload operator+(Cents, int) as a member function (as we did above), we can’t overload operator+(int, Cents) as a member function, because int isn’t a class we can add members to.
    //? Typically, we won’t be able to use a member overload if the left operand is either not a class (e.g. int), or it is a class that we can’t modify (e.g. std::ostream).
    //? This post also has good advice when to use different methods of overloading

    Vec2D operator+(const Vec2D& vec) const;
    Vec2D operator-(const Vec2D& vec) const;
    Vec2D& operator+=(const Vec2D& vec);
    Vec2D& operator-=(const Vec2D& vec);

    float Mag2() const;
    float Mag() const;

    Vec2D GetUnitVec() const;
    Vec2D& Normilize();

    float Distance(const Vec2D& vec) const;
    float Dot(const Vec2D& vec) const;

    Vec2D ProjectionOnto(const Vec2D& vec2) const;

    float AngleBetween(const Vec2D& vec2) const;
    float AngleBetweenDeg(const Vec2D& vec2) const;
    Vec2D Reflect(const Vec2D& normal) const;

    void Rotate(float angle, const Vec2D& aroundPoint);
    Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;//* Gives a new vector as if we rotated aroung that point

private:
    float mX, mY;
};

#endif /*UTILS_VEC2D_H_*/
