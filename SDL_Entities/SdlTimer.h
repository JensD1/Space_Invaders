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
        SdlTimer(const SdlTimer&);

        // Operators
        SdlTimer& operator=(const SdlTimer&);

        //Methods
        bool timePassed(unsigned long);
        void start();
    };
}

#endif //SPACE_INVADERS_SDLTIMER_H
