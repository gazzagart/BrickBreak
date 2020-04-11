#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2D.hpp"
#include "color.hpp"
#include "Screen.hpp"
#include "Line2D.hpp"
#include "Star2D.hpp"
#include "Triangle.hpp"
#include "AARectangle.hpp"
#include "Circle.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

bool DrawSpinningLine(Screen& screen);

using namespace std;

// int main (int argc, const char * argv[]) // MAC DEV
int main( int argc, char *argv[] ) // WIN DEV
{
    Screen theScreen;

    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    // Star2D star = Star2D(theScreen);
    //Where the line starts, Where the line ends!!!
    // Draw between those points
    // 0,0 top left of screen
    // Line2D line = {Vec2D(SCREEN_WIDTH/2, 0), Vec2D(SCREEN_WIDTH/2, SCREEN_HEIGHT)};
    // theScreen.Draw(line, Color::White());
    //theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
    // theScreen.SwapScreens();
    // star.drawStar(theScreen);

    // Universal Syntax
    Triangle triangle = {Vec2D(60,10), Vec2D(10,110), Vec2D(110,110)};
    AARectangle rect = {Vec2D(SCREEN_WIDTH/2 -25, SCREEN_HEIGHT/2 -25), 50, 50};
    Circle circle = {Vec2D(SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 + 50), 50};
    theScreen.Draw(triangle, Color::Red(), true, Color::Red());
    theScreen.Draw(rect, Color::Blue(), true, Color::Blue());
    theScreen.Draw(circle, Color(0,255,0,150), true, Color(0,255,0,150));
    theScreen.SwapScreens();

    SDL_Event sdlEvent;
    bool running = true;

    while (running)
    {
        // star.rotateStar(theScreen); //!Uncomment for super fast spinning star.
        while(SDL_PollEvent(&sdlEvent))
        {
            switch(sdlEvent.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        // star.rotateStar(theScreen);//!Uncomment for super Slow spinning star.
        }
    }

    return 0;
}

bool DrawSpinningLine(Screen& screen)
{
    SDL_Event sdlEvent;
    int x = 0, y = 0, xOpp = SCREEN_WIDTH, yOpp = SCREEN_HEIGHT;
    bool running = true;
    while (running)
    {
    while(SDL_PollEvent(&sdlEvent))
        {
            switch(sdlEvent.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        if(y == 0 && x < SCREEN_WIDTH) {
            x++;
            xOpp--;
        } else if(x == SCREEN_WIDTH && y < SCREEN_HEIGHT) {
            y++;
            yOpp--;
        } else if(x > 0 && y == SCREEN_HEIGHT) {
            x--;
            xOpp++;
        } else if(x == 0 && y > 0) {
            y--;
            yOpp++;
        }
        Line2D line = {Vec2D(x,y), Vec2D(xOpp,yOpp)};
        screen.Draw(line, Color::White());
        screen.SwapScreens();
    }
    return false;
}