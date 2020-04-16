//
// Created by Jens on 9/03/2020.
//

#include "EnemyEntity.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::EnemyEntity::EnemyEntity(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "EnemyEntity created" << std::endl;
}

SI::EnemyEntity::~EnemyEntity()
{
    std::cout << "EnemyEntity destroyed" << std::endl;
}

SI::EnemyEntity::EnemyEntity(const SI::EnemyEntity& other): SI::Entity(other)
{
    std::cout << "EnemyEntity copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::EnemyEntity& SI::EnemyEntity::operator=(const SI::EnemyEntity& other)
{
    if(this != &other){
        SI::Entity::operator=(other);
    }
    std::cout << "EnemyEntity assigned" << std::endl;
    return *this;
}
