#include "AARectangle.hpp"
#include "Utils.hpp"
#include <cmath>

AARectangle::AARectangle(): AARectangle(Vec2D::Zero,Vec2D::Zero)
{}

AARectangle::AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height)
{
  mPoints.push_back(topLeft);
  // This will look correct when we draw it and thats what we want to acheieve
  mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}
AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
  mPoints.push_back(topLeft);
  mPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const
{
  // needs to add one to cancel out a pixcel
  return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}
float AARectangle::GetHeight() const
{
  return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D& position)
{
  float width = GetWidth();
  float height = GetHeight();

  SetTopLeftPoint(position);
  SetBottomRightPoint(Vec2D(position.GetX() + width - 1, position.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const
{
  return Vec2D((GetTopLeftPoint().GetX() + GetWidth()) / 2.0f, (GetTopLeftPoint().GetY() + GetHeight()) / 2.0f);
}
/**
 * Checks whether otherRect intersects our current rectangle.
 * @param AARectangle otherRect
 * @return bool Whether the otherRect intersects our rectangle.
 * This functio basically checks all four sides are within our rectangle.
 * Note the negation which means all of these need to be true of the opposite (where you see a > swop for <) for this
 * function to return true.
 * */
bool AARectangle::Intersersects(const AARectangle& otherRect) const
{
  return !(otherRect.GetBottomRightPoint().GetX() < GetTopLeftPoint().GetX() ||
          otherRect.GetTopLeftPoint().GetX() > GetBottomRightPoint().GetX() ||
          otherRect.GetBottomRightPoint().GetY() < GetTopLeftPoint().GetY() ||
          otherRect.GetTopLeftPoint().GetY() > GetBottomRightPoint().GetY());
}
/**
 * Checks whether a given point is within our rectangle.
 * @param Vec2D point to check.
 * @return bool Whether the point is inside the rectangle or not.
 * This is quite straight forward: We just check the points' x and y positin is between our rectangles width and height.
 * If this is true, then the point is inside our rectangle.
*/
bool AARectangle::ContainsPoint(const Vec2D& point) const
{
  // Check that our points' x value being passed is inseide the width of our rectangle
  bool withinX = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBottomRightPoint().GetX();
  // Check that our points' y value being passed is inseide the height of our rectangle
  bool withinY = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBottomRightPoint().GetY();
  return withinX && withinY;
}
// Given the rectangle being passed, we make a smaller rectangle within it, based on the insetes being passed.
AARectangle AARectangle::Inset(const AARectangle& rect, Vec2D& insets)
{
  return AARectangle(rect.GetTopLeftPoint() + insets, rect.GetWidth() - (2*insets.GetX()), rect.GetHeight() - (2*insets.GetY()) );
}

// We need to pass four points back here because this is a rectangle.
// This function goes around our rectangle in a clock wise fashion collection all the points to send back.
std::vector<Vec2D> AARectangle::GetPoints() const
{
  std::vector<Vec2D> points;
  points.push_back(mPoints[0]);
  points.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY()));
  points.push_back(mPoints[1]);
  points.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY()));
  return points;
}