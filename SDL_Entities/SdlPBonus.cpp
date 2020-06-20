//
// Created by Jens on 9/03/2020.
//

#include "SdlPBonus.h"
#include <iostream>
#include "../SdlConstants.h"

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SDL_SI::SdlPBonus::SdlPBonus(float xPos, float yPos, float width, float height, float dx, float dy) : SI::BonusEntity(
        xPos, yPos, width, height, dx, dy) {
    std::cout << "SdlPBonus created" << std::endl;
}

SDL_SI::SdlPBonus::~SdlPBonus() {
    std::cout << "SdlPBonus destroyed"
              << std::endl; // Let op window moet nog niet vernietigd worden! Anders is bij elke BonusEntity dat gedestruct wordt heel het scherm weg!
}

SDL_SI::SdlPBonus::SdlPBonus(const SDL_SI::SdlPBonus& other) : SI::BonusEntity(other) {
    std::cout << "SdlPBonus copied" << std::endl;
}

//
// -----------------------------------------------------Operators-------------------------------------------------------
//
SDL_SI::SdlPBonus& SDL_SI::SdlPBonus::operator=(const SDL_SI::SdlPBonus& other) {
    if (this != &other) {
        SI::BonusEntity::operator=(other);
    }
    std::cout << "SdlPBonus assigned" << std::endl;
    return *this;
}

//
// ------------------------------------------------------Methods--------------------------------------------------------
//

/**
 * This method will visualize the positive bonus.
 * @param window This is the window where the sprite will be drawn on (SI::Window*). This pointer will actually contain an
 *                  SDL_SI::Window*.
 */
void SDL_SI::SdlPBonus::visualize(SI::Window* window) {
    window->drawSprite(SDL_SI::SdlPBonus::xPos, SDL_SI::SdlPBonus::yPos, SDL_SI::SdlPBonus::width,
                       SDL_SI::SdlPBonus::height, SDL_SI::PBONUS_SPRITE);
}
