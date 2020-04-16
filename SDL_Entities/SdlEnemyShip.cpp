//
// Created by Jens on 9/03/2020.
//

#include "SdlEnemyShip.h"
#include <iostream>
#include "../SdlConstants.h"
//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlEnemyShip::SdlEnemyShip(float xPos, float yPos, float width, float height, float dx, float dy, SDL_SI::SdlWindow* sdlWindow) : SI::EnemyShip(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlEnemyShip created" << std::endl;
    SDL_SI::SdlEnemyShip::sdlWindow = sdlWindow;
}

SDL_SI::SdlEnemyShip::~SdlEnemyShip()
{
    std::cout << "SdlEnemyShip destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke EnemyShip dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlEnemyShip::SdlEnemyShip(const SDL_SI::SdlEnemyShip& other): SI::EnemyShip(other)
{
    SDL_SI::SdlEnemyShip::sdlWindow = other.sdlWindow;
    std::cout << "SdlEnemyShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlEnemyShip& SDL_SI::SdlEnemyShip::operator=(const SDL_SI::SdlEnemyShip& other)
{
    if(this != &other){
        SI::EnemyShip::operator=(other);
        SDL_SI::SdlEnemyShip::sdlWindow = other.sdlWindow;
    }
    std::cout << "SdlEnemyShip assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlEnemyShip::visualize()
{
    SDL_SI::SdlEnemyShip::sdlWindow->drawSprite(SDL_SI::SdlEnemyShip::xPos, SDL_SI::SdlEnemyShip::yPos, SDL_SI::SdlEnemyShip::width, SDL_SI::SdlEnemyShip::height , SDL_SI::ENEMY_SPRITE);
}
