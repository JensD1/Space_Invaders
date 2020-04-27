//
// Created by Jens on 2/03/2020.
//

#include "PlayerShip.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SI::PlayerShip::PlayerShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos, width, height, dx, dy)
{
    SI::PlayerShip::lives = 3;
    std::cout << "PlayerShip created" << std::endl;
}

SI::PlayerShip::~PlayerShip()
{
    std::cout << "PlayerShip destroyed" << std::endl;
}

SI::PlayerShip::PlayerShip(const SI::PlayerShip& other): SI::Entity(other)
{
    SI::PlayerShip::lives = other.lives;
    std::cout << "PlayerShip copied" << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::PlayerShip& SI::PlayerShip::operator=(const SI::PlayerShip& other)
{
    if(this != &other){
        SI::PlayerShip::lives = other.lives;
        SI::Entity::operator=(other);
    }
    std::cout << "PlayerShip assigned" << std::endl;
    return *this;
}

//
// ----------------------------------------------------Methods----------------------------------------------------------
//
/**
 * This method will return the remaining number of lives of the player.
 * @return the number of lives
 */
int SI::PlayerShip::getLives()
{
    return SI::PlayerShip::lives;
}

/**
 * Set the lives of the player to a new value.
 * @param lives
 */
void SI::PlayerShip::setLives(int lives)
{
    SI::PlayerShip::lives = lives;
}