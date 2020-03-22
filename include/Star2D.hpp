#pragma once

#include "Screen.hpp"
#include "Line2D.hpp"

class Star2D {

public:
    Star2D(Screen& screen);
    void drawStar(Screen& screen);
    //We will rotate our star aound the center point as long as we are running
    void rotateStar(Screen& screen);

private:
    int shortestSide();
    int longestSide();
    int xMid;
    int yMid;
    int maxLen;
    int longestLen;
    // Vec2D class excpects radians to rotate a vector. This is 72 degrees in radians.
    // It is 72 degrees because a pentagram has 5 sides so 360/5 = 72
    const float DEG72TORAD = 1.25664;
    const double DEG1TORAD = 0.01745329252;
    // The center of the screen
    Vec2D midPoint;
    // The thinking here is to use two lines and draw all 10 needed
    //? You could acheive the same result with just two lines, but now all the lines belong to the object.
    Line2D topLineL;
    Line2D topLineR;
    Line2D leftLineT;
    Line2D leftLineB;
    Line2D rightLineT;
    Line2D rightLineB;
    Line2D bottomLeftLineT;
    Line2D bottomLeftLineB;
    Line2D bottomRightLineT;
    Line2D bottomRightLineB;
};