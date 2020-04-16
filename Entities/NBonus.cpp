//
// Created by Jens on 2/03/2020.
//

#include "NBonus.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::NBonus::NBonus(float xPos, float yPos, float width, float height, float dx, float dy) : SI::BonusEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "NBonus created" << std::endl;
}

SI::NBonus::~NBonus()
{
    std::cout << "NBonus destroyed" << std::endl;
}

SI::NBonus::NBonus(const SI::NBonus& other): SI::BonusEntity(other)
{
    std::cout << "NBonus copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::NBonus& SI::NBonus::operator=(const SI::NBonus& other)
{
    if(this != &other){
        SI::BonusEntity::operator=(other);
    }
    std::cout << "NBonus assigned" << std::endl;
    return *this;
}


