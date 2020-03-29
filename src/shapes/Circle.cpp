#include "Circle.hpp"
#include "Utils.hpp"

Circle::Circle(): Circle(Vec2D::Zero,0)
{}


Circle::Circle(const Vec2D& center, float radius):mRadius(radius)
{
  mPoints.push_back(center);
}

/**
 * Checks whether our circle and otherCircle intersects.
 * @param Circle otherCircle
 * @return bool: whether the otherCircle intersects ours.
 * The logic behind this is if the distance between the two centre points is less than the two circles'
 * radii added together, then the two circles must intersect.
*/
bool Circle::Intersects(const Circle& otherCircle) const
{
  return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (mRadius + otherCircle.mRadius);
}
/**
 * Checks whether a passed point is inside our circle.
 * @param Vec2D point: Point to check if inside our circle.
 * @return bool: Whether the point is inside our circle or not.
 * We check if the distance between our center point and the point passed in is less than or equal the radius.
 * If that distance is less than or equal to our radius it is inside or on the boundry of the circle.
 * Note: Since a circle contains all of its' boundry points, if the point is on the boundry it is considered
 * to be inside the circle.
*/
bool Circle::ContainsPoint(const Vec2D& point) const
{
  return IsLessThanOrEqual(GetCenterPoint().Distance(point), mRadius);
}
