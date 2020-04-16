//
// Created by Jens on 9/03/2020.
//

#include "BonusEntity.h"
#include <iostream>
#include <ctime>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::BonusEntity::BonusEntity(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos, width, height, dx, dy)
{
    srand( time(nullptr) );
    SI::BonusEntity::inField = false;
    std::cout << "BonusEntity created" << std::endl;
}

SI::BonusEntity::~BonusEntity()
{
    std::cout << "BonusEntity destroyed" << std::endl;
}

SI::BonusEntity::BonusEntity(const SI::BonusEntity& other): SI::Entity(other)
{
    std::cout << "BonusEntity copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::BonusEntity& SI::BonusEntity::operator=(const SI::BonusEntity& other)
{
    if(this != &other){
        SI::Entity::operator=(other);
    }
    std::cout << "BonusEntity assigned" << std::endl;
    return *this;
}

void SI::BonusEntity::updatePosition()
{
    float temp = SI::BonusEntity::getYPos() + SI::BonusEntity::getDy();
    if(temp > 1){ // als je uit het scherm gaat.
        SI::BonusEntity::resetPosition();
    }
    else{
        SI::BonusEntity::setYPos(temp);
    }
}

bool SI::BonusEntity::getInField()
{
    return SI::BonusEntity::inField;
}

void SI::BonusEntity::setInField(bool active)
{
    SI::BonusEntity::inField = active;
}

void SI::BonusEntity::spawn()
{
    if((rand() % 10000) < SI::BONUS_SWAWN_CHANCE) {
        SI::BonusEntity::setYPos(SI::BONUS_SPAWN_HEIGHT);
        float randomX = static_cast<float>((rand()+ rand())/2 % 10000)/10000;
        if(randomX > 1 - SI::BONUS_WIDTH){
            randomX = 1 - SI::BONUS_WIDTH;
        }
        SI::BonusEntity::setXPos(randomX);
        SI::BonusEntity::setDy(SI::BONUSSPEED);
        SI::BonusEntity::setInField(true);
    }
}

void SI::BonusEntity::resetPosition()
{
    SI::BonusEntity::setYPos(SI::OUT_OF_SCREEN);
    SI::BonusEntity::setXPos(SI::OUT_OF_SCREEN);
    SI::BonusEntity::setDy(0);
    SI::BonusEntity::setInField(false);
}

void SI::BonusEntity::hasCollision()
{
    SI::BonusEntity::resetPosition();
    SI::BonusEntity::setActive(true);
}

bool SI::BonusEntity::getActive()
{
    return SI::BonusEntity::active;
}

void SI::BonusEntity::setActive(bool active)
{
    SI::BonusEntity::active = active;
}
