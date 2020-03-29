#include "Shape.hpp"

void Shape::MoveBy(const Vec2D& deltaOffset)
{
  // This takes mPoints container and each element in the container it will set
  // the Vec2D ref point (Vec2D& point)
  for (Vec2D& point : mPoints)
  {
    point = point + deltaOffset;
  }
}