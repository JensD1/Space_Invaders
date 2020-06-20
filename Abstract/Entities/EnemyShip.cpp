//
// Created by Jens on 2/03/2020.
//

#include "EnemyShip.h"
#include <iostream>
#include <ctime>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SI::EnemyShip::EnemyShip(float xPos, float yPos, float width, float height, float dx, float dy) : SI::Entity(xPos, yPos,
                                                                                                             width,
                                                                                                             height, dx,
                                                                                                             dy) {
    srand(time(nullptr));
    SI::EnemyShip::fireChance = 0;
    std::cout << "EnemyShip created" << std::endl;
}

SI::EnemyShip::~EnemyShip() {
    std::cout << "EnemyShip destroyed" << std::endl;
}

SI::EnemyShip::EnemyShip(const EnemyShip& other) : SI::Entity(other) {
    std::cout << "EnemyShip copied" << std::endl;
}

//
// ---------------------------------------------------Operators---------------------------------------------------------
//
SI::EnemyShip& SI::EnemyShip::operator=(const SI::EnemyShip& other) {
    if (this != &other) {
        SI::Entity::operator=(other);
    }
    std::cout << "EnemyShip assigned" << std::endl;
    return *this;
}

//
// ----------------------------------------------------Methods----------------------------------------------------------
//
/**
 * Calculates the chance of firing a projectile.
 * @return true if a new projectile is fired, false if there's not a projectile fired.
 */
bool SI::EnemyShip::fireProjectile() {
    return (rand() % 10000) < (SI::ENEMY_FIRECHANCE + SI::EnemyShip::fireChance); // The chance is on 10000 and can be adjusted in GameConstants.h
}

/**
 * Increase the chance to fire a projectile.
 */
void SI::EnemyShip::increaseFireChance() {
    SI::EnemyShip::fireChance += 5;
}
