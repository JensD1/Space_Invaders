//
// Created by Jens on 23/03/2020.
//

#include "Timer.h"
#include <iostream>

SI::Timer::Timer()
{
    std::cout << "Timer created." << std::endl;
}

SI::Timer::~Timer()
{
    std::cout << "Timer destroyed." << std::endl;
}

SI::Timer::Timer(const SI::Timer& other)
{
    std::cout << "Timer copied." << std::endl;
}

SI::Timer& SI::Timer::operator=(const SI::Timer& other)
{
    if(this != &other)
    {
        // at the moment nothing to do.
    }
    std::cout << "Timer assigned." << std::endl;
    return *this;
}
