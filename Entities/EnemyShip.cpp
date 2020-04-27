//
// Created by Jens on 2/03/2020.
//

#include "EnemyShip.h"
#include <iostream>
#include <ctime>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::EnemyShip::EnemyShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos, width, height, dx, dy)
{
    srand( time(nullptr) );
    std::cout << "EnemyShip created" << std::endl;
}

SI::EnemyShip::~EnemyShip()
{
    std::cout << "EnemyShip destroyed" << std::endl;
}

SI::EnemyShip::EnemyShip(const EnemyShip& other): SI::Entity(other)
{
    std::cout << "EnemyShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::EnemyShip& SI::EnemyShip::operator=(const SI::EnemyShip& other)
{
    if(this != &other){
        SI::Entity::operator=(other);
    }
    std::cout << "EnemyShip assigned" << std::endl;
    return *this;
}

//
// Methods------------------------------------------------------------------------------------------------------------
//
bool SI::EnemyShip::fireProjectile() {
    return (rand() % 10000) < SI::ENEMY_FIRECHANCE;
}
