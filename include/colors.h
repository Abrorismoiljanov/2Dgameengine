#pragma once
 
#include <SDL_pixels.h>
#include <SDL_stdinc.h>
#include <bits/std_thread.h>
#include <numeric>
struct Color{
    Uint8 r, g, b, a;
    operator SDL_Color() const{
    return SDL_Color{r,g,b,a};
    }

};

namespace Colors {
    const Color transparent   = {0,0,0,0};
    const Color Black         = {0, 0, 0, 255};
    const Color White         = {255, 255, 255, 255};
    const Color Gray          = {128, 128, 128, 255};
    const Color LightGray     = {192, 192, 192, 255};
    const Color Red           = {255, 0, 0, 255};
    const Color LightRed      = {255, 128, 128, 255};
    const Color Green         = {0, 255, 0, 255};
    const Color LightGreen    = {128, 255, 128, 255};
    const Color Blue          = {0, 0, 255, 255};
    const Color LightBlue     = {128, 128, 255, 255};
    const Color Cyan          = {0, 255, 255, 255};
    const Color LightCyan     = {128, 255, 255, 255};
    const Color Magenta       = {255, 0, 255, 255};
    const Color LightMagenta  = {255, 128, 255, 255};
    const Color Yellow        = {255, 255, 0, 255};
    const Color Brown         = {128, 64, 0, 255};
}

