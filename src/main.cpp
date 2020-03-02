#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2D.hpp"
#include "color.hpp"
#include "Screen.hpp"
#include "Line2D.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

/*
1. Create a program that will continually spin a line segment counter clock-wise
2. Create a class that represents a star shape that can be drawn to the screen
3. Have your star rotate around its center point continually counter clock-wise
*/

bool DrawSpinningLine(Screen& screen);

using namespace std;

// int main (int argc, const char * argv[]) // MAC DEV
int main( int argc, char *argv[] ) // WIN DEV
{
    Screen theScreen;

    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    //Where the line starts, Where the line ends!!!
    // Draw between those points
    // 0,0 top left of screen
    // Line2D line = {Vec2D(SCREEN_WIDTH/2, 0), Vec2D(SCREEN_WIDTH/2, SCREEN_HEIGHT)};
    // theScreen.Draw(line, Color::White());
    //theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
    // theScreen.SwapScreens();

    SDL_Event sdlEvent;
    bool running = true;

    while (running)
    {
        running = DrawSpinningLine(theScreen);
        // while(SDL_PollEvent(&sdlEvent))
        // {
        //     switch(sdlEvent.type)
        //     {
        //         case SDL_QUIT:
        //             running = false;
        //             break;
        //     }
        // }
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
        //theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
        screen.SwapScreens();
    }
    return false;
}