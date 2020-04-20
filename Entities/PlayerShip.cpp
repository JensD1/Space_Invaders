//
// Created by Jens on 2/03/2020.
//

#include "PlayerShip.h"
#include <iostream>

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::PlayerShip::PlayerShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::PlayerEntity(xPos, yPos, width, height, dx, dy)
{
    SI::PlayerShip::lives = 3;
    std::cout << "PlayerShip created" << std::endl;
}

SI::PlayerShip::~PlayerShip()
{
    std::cout << "PlayerShip destroyed" << std::endl;
}

SI::PlayerShip::PlayerShip(const SI::PlayerShip& other): SI::PlayerEntity(other)
{
    SI::PlayerShip::lives = other.lives;
    std::cout << "PlayerShip copied" << std::endl;
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::PlayerShip& SI::PlayerShip::operator=(const SI::PlayerShip& other)
{
    if(this != &other){
        SI::PlayerShip::lives = other.lives;
        SI::PlayerEntity::operator=(other);
    }
    std::cout << "PlayerShip assigned" << std::endl;
    return *this;
}

//
// Methods------------------------------------------------------------------------------------------------------------
//
void SI::PlayerShip::updatePosition()
{
    float temp = SI::PlayerShip::getXPos() + SI::PlayerShip::getDx();
    if (temp>=0 && (temp <= 1 - SI::PLAYER_WIDTH)){
        SI::PlayerShip::setXPos(temp);
    }
    else if (temp < 0){
        SI::PlayerShip::setXPos(0);
    }
    else{
        SI::PlayerShip::setXPos(1 - SI::PLAYER_WIDTH);
    }
}

void SI::PlayerShip::hasCollision()
{
    SI::PlayerShip::setLives(SI::PlayerShip::getLives() - 1);
    SI::PlayerShip::setYPos(SI::PLAYER_START_POS_Y);
    SI::PlayerShip::setXPos(SI::PLAYER_START_POS_X);
}

int SI::PlayerShip::getLives()
{
    return SI::PlayerShip::lives;
}

void SI::PlayerShip::setLives(int lives)
{
    SI::PlayerShip::lives = lives;
}
