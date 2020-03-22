#include "Star2D.hpp"

/**
 * Initalises all the variables needed to draw a Star on a screen of variable size.
 * @param Screen screen is the initialised screen that we can pull data from and draw to.
**/
Star2D::Star2D(Screen& screen)
{
  // Mid points are needed to be able to rotate around and for proper length of lines.
  xMid = screen.Width()/2;
  yMid = screen.Height()/2;
  maxLen = shortestSide();
  longestLen = longestSide();
  midPoint = Vec2D(xMid,yMid);
  // Starting vectors to draw the first slice of the pentagram
  Vec2D vec1 = Vec2D(xMid,longestLen-maxLen), vec2 = Vec2D(xMid-15,maxLen+10), vec3 =  Vec2D(xMid+15,maxLen+10);
  topLineL = {vec1, vec2};
  topLineR = {vec1, vec3};
  // Here we rotate our lines around 72 degrees each time to get new line that gives us five slices in total
  rightLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD),midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD),midPoint)};
  rightLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD),midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD),midPoint)};
  bottomLeftLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint)};
  bottomLeftLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint)};
  bottomRightLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint)};
  bottomRightLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint)};
  leftLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint)};
  leftLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint)};
}

void Star2D::drawStar(Screen& screen)
{
  screen.Draw(topLineL, Color::White());
  screen.Draw(topLineR, Color::White());
  screen.Draw(rightLineT, Color::White());
  screen.Draw(rightLineB, Color::White());
  screen.Draw(bottomLeftLineT, Color::White());
  screen.Draw(bottomLeftLineB, Color::White());
  screen.Draw(bottomRightLineB, Color::White());
  screen.Draw(bottomRightLineT, Color::White());
  screen.Draw(leftLineB, Color::White());
  screen.Draw(leftLineT, Color::White());
  screen.SwapScreens();
}

void Star2D::rotateStar(Screen& screen)
{
    Vec2D vec1 = topLineL.GetP0(), vec2 = topLineL.GetP1(), vec3 = topLineR.GetP1();
    topLineL = {vec1.RotationResult(DEG1TORAD,midPoint), vec2.RotationResult(DEG1TORAD,midPoint)};
    topLineR = {vec1.RotationResult(DEG1TORAD,midPoint), vec3.RotationResult(DEG1TORAD,midPoint)};
    rightLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD),midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD),midPoint)};
    rightLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD),midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD),midPoint)};
    bottomLeftLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint)};
    bottomLeftLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*2,midPoint)};
    bottomRightLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint)};
    bottomRightLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*3,midPoint)};
    leftLineB = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint), vec2.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint)};
    leftLineT = {vec1.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint), vec3.RotationResult((DEG72TORAD + DEG1TORAD)*4,midPoint)};
    drawStar(screen);
}

int Star2D::shortestSide()
{
  if (xMid > yMid)
  {
    return yMid;
  }
  return xMid;
}
int Star2D::longestSide()
{
  if (xMid > yMid)
  {
    return xMid;
  }
  return yMid;
}