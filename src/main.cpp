#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2D.hpp"
#include "color.hpp"
#include "Screen.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MAGNIFICATION = 3;

using namespace std;

int main (int argc, const char * argv[])
{
    Screen theScreen;

    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION);
    theScreen.Draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Yellow());
    theScreen.SwapScreens();

    SDL_Event sdlEvent;
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
    }

    return 0;
}