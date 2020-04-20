//
// Created by Jens on 23/03/2020.
//

#ifndef SPACE_INVADERS_SDLTIMER_H
#define SPACE_INVADERS_SDLTIMER_H

#include "../Entities/Timer.h"
#include "SDL2/SDL.h"

namespace SDL_SI {
    class SdlTimer: public SI::Timer {
    private:
        // Variables
        Uint32 time = 0;

    public:
        // Constructors
        SdlTimer();
        ~SdlTimer();
        SdlTimer(const SDL_SI::SdlTimer&);

        // Operators
        SDL_SI::SdlTimer& operator=(const SDL_SI::SdlTimer&);

        //Methods
        bool timePassed(unsigned long);
        void start();
    };
}

#endif //SPACE_INVADERS_SDLTIMER_H
