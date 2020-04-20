//
// Created by Jens on 9/03/2020.
//

#include "SdlPBonus.h"
#include <iostream>
#include "../SdlConstants.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPBonus::SdlPBonus(float xPos, float yPos, float width, float height, float dx, float dy) : SI::PBonus(xPos, yPos, width, height, dx, dy)
{
    std::cout << "SdlPBonus created" << std::endl;
}

SDL_SI::SdlPBonus::~SdlPBonus()
{
    std::cout << "SdlPBonus destroyed" << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke PBonus dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlPBonus::SdlPBonus(const SDL_SI::SdlPBonus& other): SI::PBonus(other)
{
    std::cout << "SdlPBonus copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlPBonus& SDL_SI::SdlPBonus::operator=(const SDL_SI::SdlPBonus& other)
{
    if(this != &other){
        SI::PBonus::operator=(other);
    }
    std::cout << "SdlPBonus assigned" << std::endl;
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
void SDL_SI::SdlPBonus::visualize(SI::Window* window)
{
    window->drawSprite(SDL_SI::SdlPBonus::xPos, SDL_SI::SdlPBonus::yPos, SDL_SI::SdlPBonus::width, SDL_SI::SdlPBonus::height , SDL_SI::PBONUS_SPRITE);
}
