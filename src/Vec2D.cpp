#include "Vec2D.hpp"
#include "Utils.hpp"

#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>

const Vec2D Vec2D::Zero;

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec)
{
    std::cout << "X: " << vec.mX << ", Y:" << vec.mY << std::endl;
    return consoleOut;
}

Vec2D operator*(float scaler, const Vec2D& vec)
{
    return vec * scaler; // this uses our implementation of operator*
}

bool Vec2D::operator==(const Vec2D& vec2) const
{
    return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}
bool Vec2D::operator!=(const Vec2D& vec2) const
{
    // This goes and derefences the pointer (this is a pointer)
    // This calls the == function defined above.
    return !(*this == vec2);
}

Vec2D Vec2D::operator-() const
{
    return Vec2D(-mX,-mY);
}

Vec2D Vec2D::operator*(float scale) const
{
    return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
    assert(fabsf(scale) > EPSILON); // This will just crash the programme is it is not found as true.
    return Vec2D(mX/scale, mY/scale);
}

Vec2D& Vec2D::operator*=(float scale)
{
    // We want to return a reference of our Vec2D (Vec2D&)
    // So we need to derefence the this with the *
    *this = *this * scale;
    return *this;
}
Vec2D& Vec2D::operator/=(float scale)
{
    assert(fabsf(scale) > EPSILON);
    *this = *this / scale;
    return *this;
}

Vec2D Vec2D::operator+(const Vec2D& vec) const
{
    return Vec2D(mX + vec.mX, mY + vec.mY);
}
Vec2D Vec2D::operator-(const Vec2D& vec) const
{
    return Vec2D(mX - vec.mX, mY - vec.mY);
}
Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
    *this = *this + vec;
    return *this;
}
Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
    *this = *this - vec;
    return *this;
}

float Vec2D::Mag2() const
{
    // return mX * mX + mY * mY;
    return Dot(*this);
}
float Vec2D::Mag() const
{
    return sqrt(Mag2());
}

Vec2D Vec2D::GetUnitVec() const
{
    float mag = Mag();
    if (mag > EPSILON)
    {
        return *this/mag;
    }
    return Vec2D::Zero;
}

Vec2D& Vec2D::Normilize()
{
    float mag = Mag();
    if (mag > EPSILON)
    {
        *this /= mag;
    }
    return *this;
}

float Vec2D::Distance(const Vec2D& vec) const
{
    //* This is slighty tough to just read:
    //* What is being said here is that the resultant vector between vec and *this we want that Mag.
    //* This gives us the distance between the two
    return (vec - *this).Mag();
}

float Vec2D::Dot(const Vec2D& vec) const
{
    return mX * vec.mX + mY * vec.mY;
}

Vec2D Vec2D::ProjectionOnto(const Vec2D& vec2) const
{

    //*the commented out version will do the same thing as the one written

    // float mag2 = vec2.Mag2();
    // if(IsLessThanOrEqual(mag2, EPSILON))
    // {
    //     return Vec2D::Zero;
    // }

    Vec2D unitVec2 = vec2.GetUnitVec();
    // float dot = Dot(vec2);
    float dot = Dot(unitVec2);
    // return vec2 * (dot / mag2);
    return unitVec2 * dot;
}

float Vec2D::AngleBetween(const Vec2D& vec2) const
{
    //* making both vecs unit vecs, then doing the dot product of the vecs
    //* which gives us cosine of the angle,
    //* finally we take the inverse cosine to get the actual angle
    return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));
}

float Vec2D::AngleBetweenDeg(const Vec2D& vec2) const
{
    float rads = AngleBetween(vec2);
    return rads * 180/M_PI;
}

Vec2D Vec2D::Reflect(const Vec2D& normal) const
{
    //* n is a unit vec
    //* v - 2(v dot n ) * n
    return *this - 2 * ProjectionOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
    float cosine = cosf(angle);//* takes radians
    float sine = sinf(angle);

    Vec2D thisVec(mX,mY);
    //* We have to go to the centre first
    thisVec -= aroundPoint;
    //* Now we rotate
    float xRot = thisVec.mX * cosine - thisVec.mY * sine;
    float yRot = thisVec.mX * sine + thisVec.mY * cosine;

    Vec2D rot = Vec2D(xRot, yRot);

    *this = rot + aroundPoint;
}
Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const
{
    //* Very similar to the function above:
    //? The difference is that we don't return ourselves
    float cosine = cosf(angle);//* takes radians
    float sine = sinf(angle);

    Vec2D thisVec(mX,mY);
    //* We have to go to the centre first
    thisVec -= aroundPoint;
    //* Now we rotate
    float xRot = thisVec.mX * cosine - thisVec.mY * sine;
    float yRot = thisVec.mX * sine + thisVec.mY * cosine;

    Vec2D rot = Vec2D(xRot, yRot);

    return rot + aroundPoint;
}
