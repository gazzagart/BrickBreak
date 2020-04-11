#include "ScreenBuffer.hpp"
#include<SDL2/SDL.h>
#include <cassert>


ScreenBuffer::ScreenBuffer(): mSurface(nullptr)
{

}
ScreenBuffer::ScreenBuffer(const ScreenBuffer& screenBuffer)
{
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);
    //* This copies all the pixeles from the first parameter to the 3rd parameter surface
    SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
}
ScreenBuffer::~ScreenBuffer()
{
    if(mSurface)
    {
        SDL_FreeSurface(mSurface);
    }
}

ScreenBuffer& ScreenBuffer::operator=(const ScreenBuffer& screenBuffer)
{
    if(this == &screenBuffer)
    {
        return *this;
    }

    if(mSurface)
    {
        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }

    if(screenBuffer.mSurface != nullptr)
    {
        mSurface = SDL_CreateRGBSurfaceWithFormat(0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);

        SDL_BlitSurface(screenBuffer.mSurface, nullptr, mSurface, nullptr);
    }

    return *this;
}

void ScreenBuffer::Init(uint32_t format, uint32_t width, uint32_t height)
{
    mSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 0, format);
    Clear();
}


void ScreenBuffer::Clear(const Color& c)
{
    assert(mSurface);
    if(mSurface)
    {
        SDL_FillRect(mSurface, nullptr, c.GetPixelColor());
    }
}

void ScreenBuffer::SetPixel(const Color& color, int x, int y)
{
    assert(mSurface);
    if(mSurface && (y < mSurface->h && y > 0 && x >= 0 && x < mSurface->w))
    {
        //* What lock and unloack does is to say that nothing outside of it can access the surface.
        SDL_LockSurface(mSurface);

        //* directly getting the pixels of the surface
        //* this is a 1D array of all the pixels on the screen
        //* its actually one giant buffer instead of a 2D plane we see
        uint32_t * pixels = (uint32_t*)mSurface->pixels;

        //* we transfer the pixels into an index that the buffer can use
        size_t index = GetIndex(y, x);
        //* put the color at this pixel
        // pixels[index] = color.GetPixelColor();
        Color surfaceColor = Color(pixels[index]); //destinationColor
			pixels[index] = Color::Evaluate1MinusSourceAlpha(color, surfaceColor).GetPixelColor();

        SDL_UnlockSurface(mSurface);
    }
}
uint32_t ScreenBuffer::GetIndex(int r, int c)
{
    assert(mSurface);
    if(mSurface)
    {
         //* row * width of surface + col
        return r * mSurface->w + c;
    }
    return 0;
}
