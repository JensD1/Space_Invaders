//
// Created by Jens on 16/03/2020.
//

#include "Event.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//

SI::Event::Event()
{
    std::cout << "Event created." << std::endl;
}

SI::Event::~Event()
{
    std::cout << "Event Destroyed." << std::endl;
}

SI::Event::Event(const SI::Event& other)
{
    std::cout << "Event copied." << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::Event &SI::Event::operator=(const SI::Event& other) {
    if(this != &other){
        // nothing to do
    }
    std::cout << "Event Destroyed." << std::endl;
    return *this;
}

