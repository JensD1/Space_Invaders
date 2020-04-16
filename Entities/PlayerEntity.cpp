//
// Created by Jens on 9/03/2020.
//

#include "PlayerEntity.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::PlayerEntity::PlayerEntity(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "PlayerEntity created" << std::endl;
}

SI::PlayerEntity::~PlayerEntity()
{
    std::cout << "PlayerEntity destroyed" << std::endl;
}

SI::PlayerEntity::PlayerEntity(const SI::PlayerEntity& other): SI::Entity(other)
{
    std::cout << "PlayerEntity copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::PlayerEntity& SI::PlayerEntity::operator=(const SI::PlayerEntity& other)
{
    if(this != &other){
        SI::Entity::operator=(other);
    }
    std::cout << "PlayerEntity assigned" << std::endl;
    return *this;
}

