//
// Created by Jens on 9/03/2020.
//

#include "SdlProjectile.h"
#include <iostream>
#include "../SdlConstants.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlProjectile::SdlProjectile(float xPos, float yPos, float width, float height, float dx, float dy) : SI::ReusableEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlProjectile created" << std::endl;
}

SDL_SI::SdlProjectile::~SdlProjectile()
{
    std::cout << "SdlProjectile destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke ReusableEntity dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlProjectile::SdlProjectile(const SDL_SI::SdlProjectile& other): SI::ReusableEntity(other)
{
    std::cout << "SdlProjectile copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlProjectile& SDL_SI::SdlProjectile::operator=(const SDL_SI::SdlProjectile& other)
{
    if(this != &other){
        SI::ReusableEntity::operator=(other);
    }
    std::cout << "SdlProjectile assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlProjectile::visualize(SI::Window* window)
{
    window->drawSprite(SDL_SI::SdlProjectile::xPos, SDL_SI::SdlProjectile::yPos, SDL_SI::SdlProjectile::width, SDL_SI::SdlProjectile::height , SDL_SI::PROJECTILE_SPRITE);
}
