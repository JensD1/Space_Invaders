//
// Created by Jens on 9/03/2020.
//

#include "BonusEntity.h"
#include <iostream>
#include <ctime>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::BonusEntity::BonusEntity(float xPos, float yPos, float width, float height, float dx, float dy) : SI::ReusableEntity(xPos, yPos, width, height, dx, dy)
{
    srand( time(nullptr) );
    std::cout << "BonusEntity created" << std::endl;
}

SI::BonusEntity::~BonusEntity()
{
    std::cout << "BonusEntity destroyed" << std::endl;
}

SI::BonusEntity::BonusEntity(const SI::BonusEntity& other): SI::ReusableEntity(other)
{
    std::cout << "BonusEntity copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::BonusEntity& SI::BonusEntity::operator=(const SI::BonusEntity& other)
{
    if(this != &other){
        SI::ReusableEntity::operator=(other);
    }
    std::cout << "BonusEntity assigned" << std::endl;
    return *this;
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

bool SI::BonusEntity::getActive()
{
    return SI::BonusEntity::active;
}

void SI::BonusEntity::setActive(bool active)
{
    SI::BonusEntity::active = active;
}
