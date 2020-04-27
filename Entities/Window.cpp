//
// Created by Jens on 14/04/2020.
//

#include "Window.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SI::Window::Window()
{
    std::cout << "Window created" << std::endl;
}

SI::Window::~Window()
{
    std::cout << "Window destroyed" << std::endl;
}

SI::Window::Window(const SI::Window& other)
{
    std::cout << "Window copied" << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::Window& SI::Window::operator=(const SI::Window& other)
{
    if (this != &other){
        std::cout << "Window assigned" << std::endl;
    }
    return *this;
}
