//
// Created by Jens on 2/03/2020.
//

#include "EnemyShip.h"
#include <iostream>
#include <ctime>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::EnemyShip::EnemyShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::EnemyEntity(xPos, yPos, width, height, dx, dy)
{
    srand( time(nullptr) );
    std::cout << "EnemyShip created" << std::endl;
}

SI::EnemyShip::~EnemyShip()
{
    std::cout << "EnemyShip destroyed" << std::endl;
}

SI::EnemyShip::EnemyShip(const EnemyShip& other): SI::EnemyEntity(other)
{
    std::cout << "EnemyShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::EnemyShip& SI::EnemyShip::operator=(const SI::EnemyShip& other)
{
    if(this != &other){
        SI::EnemyEntity::operator=(other);
    }
    std::cout << "EnemyShip assigned" << std::endl;
    return *this;
}

//
// Methods------------------------------------------------------------------------------------------------------------
//
void SI::EnemyShip::updatePosition()
{
    SI::EnemyShip::setXPos(SI::EnemyShip::getXPos() + SI::EnemyShip::getDx());
    SI::EnemyShip::setYPos(SI::EnemyShip::getYPos() + SI::EnemyShip::getDy());
}

void SI::EnemyShip::hasCollision()
{

}

bool SI::EnemyShip::fireProjectile() {
    return (rand() % 100) < SI::ENEMY_FIRECHANCE;
}
