//
// Created by Jens on 16/03/2020.
//

#include "Event.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//

SI::Event::Event()
{
    SI::Event::control = IDLE;
    std::cout << "Event created." << std::endl;
}

SI::Event::~Event()
{
    std::cout << "Event Destroyed." << std::endl;
}

SI::Event::Event(const SI::Event& other)
{
    Event::control = other.getControl();
    std::cout << "Event copied." << std::endl;
}

//
// Getters--------------------------------------------------------------------------------------------------------------
//
SI::Control SI::Event::getControl() const
{
    return SI::Event::control;
}

//
// Setters--------------------------------------------------------------------------------------------------------------
//
void SI::Event::setControl(SI::Control control)
{
    SI::Event::control = control;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::Event &SI::Event::operator=(const SI::Event& other) {
    if(this != &other){
        SI::Event::control = other.getControl();
    }
    std::cout << "Event Destroyed." << std::endl;
    return *this;
}

