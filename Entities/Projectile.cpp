//
// Created by Jens on 2/03/2020.
//

#include "Projectile.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::Projectile::Projectile(float xPos, float yPos, float width, float height, float dx, float dy) : SI::ReusableEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "Projectile created" << std::endl;
}

SI::Projectile::~Projectile()
{
    std::cout << "Projectile destroyed" << std::endl;
}

SI::Projectile::Projectile(const SI::Projectile& other): SI::ReusableEntity(other)
{
    std::cout << "Projectile copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::Projectile& SI::Projectile::operator=(const SI::Projectile& other)
{
    if(this != &other){
        SI::ReusableEntity::operator=(other);
    }
    std::cout << "Projectile assigned" << std::endl;
    return *this;
}

//
// Methods------------------------------------------------------------------------------------------------------------
//
