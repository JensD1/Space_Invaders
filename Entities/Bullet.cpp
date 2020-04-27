//
// Created by Jens on 2/03/2020.
//

#include <iostream>
#include "Bullet.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::Bullet::Bullet(float xPos, float yPos, float width, float height, float dx, float dy) : SI::ReusableEntity(xPos, yPos, width, height, dx, dy)
{
    std::cout << "Bullet created" << std::endl;
}

SI::Bullet::~Bullet()
{
    std::cout << "Bullet destroyed" << std::endl;
}

SI::Bullet::Bullet(const Bullet& other): SI::ReusableEntity(other)
{
    std::cout << "Bullet copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::Bullet& SI::Bullet::operator=(const SI::Bullet& other)
{
    if(this != &other){
        SI::ReusableEntity::operator=(other);
    }
    std::cout << "Bullet assigned" << std::endl;
    return *this;
}