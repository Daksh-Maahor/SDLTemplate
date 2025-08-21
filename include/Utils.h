#ifndef UTILS_H_
#define UTILS_H_

#include <SDL2/SDL.h>

namespace Utils
{
    inline float HireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}

#endif
