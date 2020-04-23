//
// Created by Jens on 23/03/2020.
//

#include "SdlTimer.h"
#include <iostream>
#include "../SdlConstants.h"

SDL_SI::SdlTimer::SdlTimer():SI::Timer()
{
    SDL_SI::SdlTimer::requestedPeriodMs = static_cast<Uint32>(requestedPeriodMs);
    SDL_SI::SdlTimer::time = SDL_GetTicks();
    SDL_SI::SdlTimer::remaining = requestedPeriodMs;
    std::cout << "SdlTimer created." << std::endl;
}

SDL_SI::SdlTimer::~SdlTimer()
{
    std::cout << "SdlTimer Destroyed." << std::endl;
}

SDL_SI::SdlTimer::SdlTimer(const SDL_SI::SdlTimer& other)
{
    SDL_SI::SdlTimer::time = other.time;
    SDL_SI::SdlTimer::remaining = other.remaining;
    SDL_SI::SdlTimer::requestedPeriodMs = other.requestedPeriodMs;
    std::cout << "SdlTimer copied." << std::endl;
}

SDL_SI::SdlTimer& SDL_SI::SdlTimer::operator=(const SDL_SI::SdlTimer& other) {
    if(this != &other)
    {
        SDL_SI::SdlTimer::time = other.time;
        SDL_SI::SdlTimer::remaining = other.remaining;
        SDL_SI::SdlTimer::requestedPeriodMs = other.requestedPeriodMs;
    }
    std::cout << "SdlTimer assigned." << std::endl;
    return *this;
}

bool SDL_SI::SdlTimer::timePassed() // unsigned long en Uint32 zijn beiden 32 bits groot.
{
    bool returnValue = false;
    Uint32 currentTime = SDL_GetTicks();
    if(currentTime - SDL_SI::SdlTimer::time >= SDL_SI::SdlTimer::remaining){ // als het tijdsverschil groter/ gelijk is aan de overgebleven tijd, dan is de gevraagde tijd gepasseerd
        returnValue = true;
    }
    else{ // anders updaten we hoeveel tijd er nog over blijft.
        SDL_SI::SdlTimer::remaining -= (currentTime -SDL_SI::SdlTimer::time);
        SDL_SI::SdlTimer::time = currentTime;
    }
    return returnValue;
}

void SDL_SI::SdlTimer::start()
{
    SDL_SI::SdlTimer::time = SDL_GetTicks();
    SDL_SI::SdlTimer::remaining = SDL_SI::SdlTimer::requestedPeriodMs;
}

void SDL_SI::SdlTimer::paused() {
    SDL_SI::SdlTimer::time = SDL_GetTicks();
}

void SDL_SI::SdlTimer::setRequestedTime(unsigned long requestedPeriodMs)
{
    SDL_SI::SdlTimer::requestedPeriodMs = requestedPeriodMs;
}
