#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2D.hpp"
#include "color.hpp"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

using namespace std;
//* Puts a pixel with this colour, at the location on the surface.
void SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y);
//* gets index at row and col
size_t GetIndex(SDL_Surface * noptrSurface, int r, int c);

int main (int argc, const char * argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Error SDL_INIT Failed" << std::endl;
        return 1;
    }

    SDL_Window* optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(optrWindow == nullptr)
    {
        std::cout << "Could not create window, got error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);

    SDL_PixelFormat * pixelFormat = noptrWindowSurface->format;
    //* Have to do this before we do anything else with colours
    Color::InitColorFormat(pixelFormat);
    Color c(255,255,0,255);
    std::cout << "The window pixel format is: " << SDL_GetPixelFormatName(pixelFormat->format) << std::endl;

    uint32_t color = 0xFF0000;

    SetPixel(noptrWindowSurface, c.GetPixelColor(), SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    SDL_UpdateWindowSurface(optrWindow);

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

    SDL_DestroyWindow(optrWindow);
    SDL_Quit();

    return 0;
}
void SetPixel(SDL_Surface * noptrWindowSurface, uint32_t color, int x, int y)
{
    //* What lock and unloack does is to say that nothing outside of it can access the surface.
    SDL_LockSurface(noptrWindowSurface);

    //* directly getting the pixels of the surface
    //* this is a 1D array of all the pixels on the screen
    //* its actually one giant buffer instead of a 2D plane we see
    uint32_t * pixels = (uint32_t*)noptrWindowSurface->pixels;

    //* we transfer the pixels into an index that the buffer can use
    size_t index = GetIndex(noptrWindowSurface, y, x);
    //* put the color at this pixel
    pixels[index] = color;

    SDL_UnlockSurface(noptrWindowSurface);
}
size_t GetIndex(SDL_Surface * noptrSurface, int r, int c)
{
    //* row * width of surface + col
    return r * noptrSurface->w + c;
}