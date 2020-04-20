//
// Created by Jens on 9/03/2020.
//

#include "SdlPlayerShip.h"
#include <iostream>
#include "../SdlConstants.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPlayerShip::SdlPlayerShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::PlayerShip(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlPlayerShip created" << std::endl;

}

SDL_SI::SdlPlayerShip::~SdlPlayerShip()
{
    std::cout << "SdlPlayerShip destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke PlayerShip dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlPlayerShip::SdlPlayerShip(const SDL_SI::SdlPlayerShip& other): SI::PlayerShip(other)
{
    std::cout << "SdlPlayerShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPlayerShip& SDL_SI::SdlPlayerShip::operator=(const SDL_SI::SdlPlayerShip& other)
{
    if(this != &other){
        SI::PlayerShip::operator=(other);
    }
    std::cout << "SdlPlayerShip assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlPlayerShip::visualize(SI::Window* window)
{
    window->drawSprite(SDL_SI::SdlPlayerShip::xPos, SDL_SI::SdlPlayerShip::yPos, SDL_SI::SdlPlayerShip::width, SDL_SI::SdlPlayerShip::height , SDL_SI::PLAYER_SPRITE);
    for(int i = 0; i < SI::PlayerShip::getLives(); i++){
        window->drawSprite(SI::LIVES_START_POS_X + i * (SI::LIVES_WIDTH + SI::LIVES_SPACING), SI::LIVES_START_POS_Y,
                SI::LIVES_WIDTH, SI::LIVES_HEIGHT, SDL_SI::PLAYER_SPRITE);
    }
}