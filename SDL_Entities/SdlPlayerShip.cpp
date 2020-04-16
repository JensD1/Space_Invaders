//
// Created by Jens on 9/03/2020.
//

#include "SdlPlayerShip.h"
#include <iostream>
#include "../SdlConstants.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPlayerShip::SdlPlayerShip(float xPos, float yPos, float width, float height, float dx, float dy, SDL_SI::SdlWindow* sdlWindow) : SI::PlayerShip(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlPlayerShip created" << std::endl;
    SDL_SI::SdlPlayerShip::sdlWindow = sdlWindow;
}

SDL_SI::SdlPlayerShip::~SdlPlayerShip()
{
    std::cout << "SdlPlayerShip destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke PlayerShip dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlPlayerShip::SdlPlayerShip(const SDL_SI::SdlPlayerShip& other): SI::PlayerShip(other)
{
    SDL_SI::SdlPlayerShip::sdlWindow = other.sdlWindow;
    std::cout << "SdlPlayerShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPlayerShip& SDL_SI::SdlPlayerShip::operator=(const SDL_SI::SdlPlayerShip& other)
{
    if(this != &other){
        SI::PlayerShip::operator=(other);
        SDL_SI::SdlPlayerShip::sdlWindow = other.sdlWindow;
    }
    std::cout << "SdlPlayerShip assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlPlayerShip::visualize()
{
    SDL_SI::SdlPlayerShip::sdlWindow->drawSprite(SDL_SI::SdlPlayerShip::xPos, SDL_SI::SdlPlayerShip::yPos, SDL_SI::SdlPlayerShip::width, SDL_SI::SdlPlayerShip::height , SDL_SI::PLAYER_SPRITE);
}
