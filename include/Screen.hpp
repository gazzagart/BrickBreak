#pragma once

#include <stdint.h>
#include "ScreenBuffer.hpp"
#include "color.hpp"

class Vec2D; //Forward declaration
class Line2D; //Forward declaration
class Triangle; //Forward declaration
class AARectangle; //Forward declaration
class Circle; //Forward declaration
struct SDL_Window; //Forward declaration
struct SDL_Surface; //Forward declaration

class Screen {
public:
    Screen();
    ~Screen();

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreens();

    inline void SetClearColor(const Color& clearColor) {mClearColor = clearColor;}
    inline uint32_t Width() const {return mWidth;}
    inline uint32_t Height() const {return mHeight;}

    //Draw methods go here
    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    void Draw(const Line2D& line, const Color& color);
    void Draw(const Triangle& triangle, const Color& color);
    void Draw(const AARectangle& rect, const Color& color);
    void Draw(const Circle& circle, const Color& color);
private:

    Screen(const Screen& screen);//* No one can do copy constructor!
    Screen& operator=(const Screen& screen);//*Can't copy the screen around
    void ClearScreen();

    uint32_t mWidth;
    uint32_t mHeight;

    Color mClearColor;
    ScreenBuffer mBackBuffer;

    SDL_Window* moptrWindow;
    SDL_Surface* mnoptrWindowSurface;
};