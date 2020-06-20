//
// Created by Jens on 9/03/2020.
//

#include "SdlNBonus.h"
#include <iostream>
#include "../SdlConstants.h"

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SDL_SI::SdlNBonus::SdlNBonus(float xPos, float yPos, float width, float height, float dx, float dy) : SI::BonusEntity(
        xPos, yPos, width, height, dx, dy) {
    std::cout << "SdlNBonus created" << std::endl;
}

SDL_SI::SdlNBonus::~SdlNBonus() {
    std::cout << "SdlNBonus destroyed"
              << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke BonusEntity dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlNBonus::SdlNBonus(const SDL_SI::SdlNBonus& other) : SI::BonusEntity(other) {
    std::cout << "SdlNBonus copied" << std::endl;
}

//
// -----------------------------------------------------Operators-------------------------------------------------------
//
SDL_SI::SdlNBonus& SDL_SI::SdlNBonus::operator=(const SDL_SI::SdlNBonus& other) {
    if (this != &other) {
        SI::BonusEntity::operator=(other);
    }
    std::cout << "SdlNBonus assigned" << std::endl;
    return *this;
}

//
// ------------------------------------------------------Methods--------------------------------------------------------
//
/**
 * This method will visualize the negative bonus.
 * @param window This is the window where the sprite will be drawn on (SI::Window*). This pointer will actually contain an
 *                  SDL_SI::Window*.
 */
void SDL_SI::SdlNBonus::visualize(SI::Window* window) {
    window->drawSprite(SDL_SI::SdlNBonus::xPos, SDL_SI::SdlNBonus::yPos, SDL_SI::SdlNBonus::width,
                       SDL_SI::SdlNBonus::height, SDL_SI::NBONUS_SPRITE);
}
