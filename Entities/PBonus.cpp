//
// Created by Jens on 2/03/2020.
//

#include "PBonus.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::PBonus::PBonus(float xPos, float yPos, float width, float height, float dx, float dy) : SI::BonusEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "PBonus created" << std::endl;
}

SI::PBonus::~PBonus()
{
    std::cout << "PBonus destroyed" << std::endl;
}

SI::PBonus::PBonus(const SI::PBonus& other): SI::BonusEntity(other)
{
    std::cout << "PBonus copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::PBonus& SI::PBonus::operator=(const SI::PBonus& other)
{
    if(this != &other){
        SI::BonusEntity::operator=(other);
    }
    std::cout << "PBonus assigned" << std::endl;
    return *this;
}

