#include "Triangle.hpp"

#include <cmath>
#include "Utils.hpp"

Triangle::Triangle():Triangle(Vec2D::Zero, Vec2D::Zero,Vec2D::Zero)
{}

Triangle::Triangle(const Vec2D& p0, const Vec2D p1, const Vec2D& p2)
{
  mPoints.push_back(p0);
  mPoints.push_back(p1);
  mPoints.push_back(p2);
}
Vec2D Triangle::GetCenterPoint() const
{
  // Calculates the centroid of a triangle.
  return Vec2D( (mPoints[0].GetX() + mPoints[1].GetX() + mPoints[2].GetX() ) /3.0f, (mPoints[0].GetY() + mPoints[1].GetY() + mPoints[2].GetY() ) /3.0f);
}

  float Triangle::Area() const
  {
    return Area(GetP0(), GetP1(), GetP2());
  }
  /**
     * Here we are going to see if a point (Vec2D& p) is inside our triangle.
     * We do this by calculating the sum of the areas of triangles drawn with the points of our triangle, and the point p.
     * See lower for how the logic works.
     * @param Vec2D& p
     * @return bool: Whether the point is inside the triangle or not.
     *
     * To see how the logic of how this function works:
     * Get a piece of paper and draw a triangle.
     * Place a ponint inside the triangle.
     * Now draw lines from the point inside your triangle, to each vetex of the triangle (point a,b and c of the triangle).
     * You should have created three smaller triangles inside our triangle.
     * Now if we add the area of all three triangles togther and it equals our main triangle, then the point is inside our triangle.
  */
  bool Triangle::ContainsPoint(const Vec2D& p) const
  {
    float thisArea = Area();
    float a1 = Area(p, GetP1(), GetP2());
    float a2 = Area(GetP0(), p,  GetP2());
    float a3 = Area(GetP0(), GetP1(), p);
    return IsEqual(thisArea, a1 + a2 + a3);
  }


  float Triangle::Area(const Vec2D& p0,const Vec2D& p1,const Vec2D& p2) const
  {
    // Calculates the area of a triangle given three points in 2D space:
    //https://math.stackexchange.com/questions/516219/finding-out-the-area-of-a-triangle-if-the-coordinates-of-the-three-vertices-are
    //https://en.wikipedia.org/wiki/Shoelace_formula
    return fabsf((p0.GetX() * (p1.GetY() - p2.GetY()) + p1.GetX()*(p2.GetY() - p0.GetY()) + p2.GetX()*(p1.GetX() - p0.GetX()) ) /2.0f);
  }