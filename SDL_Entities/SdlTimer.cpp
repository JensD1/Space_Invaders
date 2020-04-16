//
// Created by Jens on 23/03/2020.
//

#include "SdlTimer.h"
#include <iostream>
#include "../SdlConstants.h"

SDL_SI::SdlTimer::SdlTimer():SI::Timer()
{
    time = SDL_GetTicks();
    std::cout << "SdlTimer created." << std::endl;
}

SDL_SI::SdlTimer::~SdlTimer()
{
    std::cout << "SdlTimer Destroyed." << std::endl;
}

SDL_SI::SdlTimer::SdlTimer(const SDL_SI::SdlTimer& other)
{
    SDL_SI::SdlTimer::time = other.time;
    std::cout << "SdlTimer copied." << std::endl;
}

SDL_SI::SdlTimer& SDL_SI::SdlTimer::operator=(const SDL_SI::SdlTimer& other) {
    if(this != &other)
    {
        SDL_SI::SdlTimer::time = other.time;
    }
    std::cout << "SdlTimer assigned." << std::endl;
    return *this;
}

bool SDL_SI::SdlTimer::timePassed(unsigned long requestedPeriodMs) // unsigned long en Uint32 zijn beiden 32 bits groot.
{
    bool returnValue = false;
    if((SDL_GetTicks() - SDL_SI::SdlTimer::time) >= static_cast<Uint32>(requestedPeriodMs)){
        returnValue = true;
    }
    return returnValue;
}

void SDL_SI::SdlTimer::start()
{
    SDL_SI::SdlTimer::time = SDL_GetTicks();
}
