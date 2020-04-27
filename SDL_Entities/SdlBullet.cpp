//
// Created by Jens on 9/03/2020.
//

#include "SdlBullet.h"
#include <iostream>
#include "../SdlConstants.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlBullet::SdlBullet(float xPos, float yPos, float width, float height, float dx, float dy) : SI::ReusableEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlBullet created" << std::endl;
}

SDL_SI::SdlBullet::~SdlBullet()
{
    std::cout << "SdlBullet destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke ReusableEntity dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlBullet::SdlBullet(const SDL_SI::SdlBullet& other): SI::ReusableEntity(other)
{
    std::cout << "SdlBullet copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlBullet& SDL_SI::SdlBullet::operator=(const SDL_SI::SdlBullet& other)
{
    if(this != &other){
        SI::ReusableEntity::operator=(other);
    }
    std::cout << "SdlBullet assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlBullet::visualize(SI::Window* window)
{
    window->drawSprite(SDL_SI::SdlBullet::xPos, SDL_SI::SdlBullet::yPos, SDL_SI::SdlBullet::width, SDL_SI::SdlBullet::height , SDL_SI::BULLET_SPRITE);
}
