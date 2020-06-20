//
// Created by Jens on 9/03/2020.
//

#include "BonusEntity.h"
#include <iostream>
#include <ctime>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SI::BonusEntity::BonusEntity(float xPos, float yPos, float width, float height, float dx, float dy)
        : SI::ReusableEntity(xPos, yPos, width, height, dx, dy) {
    srand(time(nullptr));
    SI::BonusEntity::active = false;
    std::cout << "BonusEntity created" << std::endl;
}

SI::BonusEntity::~BonusEntity() {
    std::cout << "BonusEntity destroyed" << std::endl;
}

SI::BonusEntity::BonusEntity(const SI::BonusEntity& other) : SI::ReusableEntity(other) {
    SI::BonusEntity::active = other.active;
    std::cout << "BonusEntity copied" << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::BonusEntity& SI::BonusEntity::operator=(const SI::BonusEntity& other) {
    if (this != &other) {
        SI::ReusableEntity::operator=(other);
        SI::BonusEntity::active = other.active;
    }
    std::cout << "BonusEntity assigned" << std::endl;
    return *this;
}

//
// ----------------------------------------------------Methods----------------------------------------------------------
//

/**
 * This method will spawn a bonus on a random x position (within a range of 0 and 1) on the top of the screen.
 */
void SI::BonusEntity::spawn() {
    // There's a small chance that a bonus will be spawned, the change (on 10000) can be adjusted in GameConstants.h
    if ((rand() % 10000) < SI::BONUS_SWAWN_CHANCE) {
        SI::BonusEntity::setYPos(SI::BONUS_SPAWN_HEIGHT);
        // I noticed that the same spawning place was used in different runs, so the double rand()
        // will create a more random variable. After doing this, this regular spawning at the same place
        // was not a problem anymore.
        float randomX = static_cast<float>((rand() + rand()) / 2 % 10000) / 10000;
        if (randomX > 1 - SI::BONUS_WIDTH) { // make sure that it's not spawning out of the right side of the field.
            randomX = 1 - SI::BONUS_WIDTH;
        }
        SI::BonusEntity::setXPos(randomX);
        SI::BonusEntity::setDy(SI::BONUSSPEED);
        SI::BonusEntity::setInField(true);
    }
}

/**
 * This method will return the active variable of this object.
 * When active, this bonus will influence a few things in the game
 * which gives the effect of a bonus.
 * @return if the bonus is active.
 */
bool SI::BonusEntity::getActive() {
    return SI::BonusEntity::active;
}

/**
 * This will set the objects variable "active" to a new value.
 * @param active contains the new variable for the objects variable "active".
 */
void SI::BonusEntity::setActive(bool active) {
    SI::BonusEntity::active = active;
}
