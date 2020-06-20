//
// Created by Jens on 2/03/2020.
//

#include "SdlFactory.h"
#include <iostream>
#include "SDL_Entities/SdlBullet.h"
#include "SDL_Entities/SdlEnemyShip.h"
#include "SDL_Entities/SdlNBonus.h"
#include "SDL_Entities/SdlPBonus.h"
#include "SDL_Entities/SdlPlayerShip.h"
#include "SDL_Entities/SdlProjectile.h"
#include "../Constants/GameConstants.h"
#include "SdlTimer.h"
#include "SdlEvent.h"
#include "Window/SdlWindow.h"
#include "SdlSound.h"

//
// ------------------------------------------------Constructors---------------------------------------------------------
//
SDL_SI::SdlFactory::SdlFactory() {
    std::cout << "SDL Factory created." << std::endl;
}

SDL_SI::SdlFactory::~SdlFactory() {
    std::cout << "SDL Factory destroyed." << std::endl;
}

SDL_SI::SdlFactory::SdlFactory(const SDL_SI::SdlFactory& other) {
    std::cout << "SDL Factory copied." << std::endl;
}

//
// ---------------------------------------------------Methods-----------------------------------------------------------
//
/**
 * Create an SDL player ship at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the player ship to be created. Must be within the range of 0 and 1.
 * @param height The Height of the player ship to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the player ship.
 * @param dy The vertical speed of the player ship.
 * @return An abstract player ship pointer that actually contains an sdl player ship pointer.
 */
SI::PlayerShip*
SDL_SI::SdlFactory::createPlayerShip(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlPlayerShip(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL bullet at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the bullet to be created. Must be within the range of 0 and 1.
 * @param height The Height of the bullet to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the bullet.
 * @param dy The vertical speed of the bullet.
 * @return An abstract bullet pointer that actually contains an sdl bullet pointer.
 */
SI::ReusableEntity*
SDL_SI::SdlFactory::createBullet(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlBullet(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL enemy ship at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the enemy ship to be created. Must be within the range of 0 and 1.
 * @param height The Height of the enemy ship to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the enemy ship.
 * @param dy The vertical speed of the enemy ship.
 * @return An abstract enemy ship pointer that actually contains an sdl enemy ship pointer.
 */
SI::EnemyShip*
SDL_SI::SdlFactory::createEnemyShip(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlEnemyShip(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL projectile at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the projectile to be created. Must be within the range of 0 and 1.
 * @param height The Height of the projectile to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the projectile.
 * @param dy The vertical speed of the projectile.
 * @return An abstract projectile pointer that actually contains an sdl projectile pointer.
 */
SI::ReusableEntity*
SDL_SI::SdlFactory::createProjectile(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlProjectile(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL negative bonus at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the negative bonus to be created. Must be within the range of 0 and 1.
 * @param height The Height of the negative bonus to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the negative bonus.
 * @param dy The vertical speed of the negative bonus.
 * @return An abstract negative bonus pointer that actually contains an sdl negative bonus pointer.
 */
SI::BonusEntity*
SDL_SI::SdlFactory::createNBonus(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlNBonus(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL positive bonus at a certain location with a specific size and starting speed.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param width The width of the positive bonus to be created. Must be within the range of 0 and 1.
 * @param height The Height of the positive bonus to be created. Must be within the range of 0 and 1.
 * @param dx The horizontal speed of the positive bonus.
 * @param dy The vertical speed of the positive bonus.
 * @return An abstract positive bonus pointer that actually contains an sdl positive bonus pointer.
 */
SI::BonusEntity*
SDL_SI::SdlFactory::createPBonus(float xPos, float yPos, float width, float height, float dx, float dy) {
    return new SdlPBonus(xPos, yPos, width, height, dx, dy);
}

/**
 * Create an SDL event.
 */
SI::Event* SDL_SI::SdlFactory::createEvent() {
    return new SdlEvent();
}

/**
 * Create an SDL timer.
 */
SI::Timer* SDL_SI::SdlFactory::createTimer() {
    return new SdlTimer();
}

/**
 * Create an SDL window.
 */
SI::Window* SDL_SI::SdlFactory::createWindow() {
    return new SdlWindow();
}

/**
 * Create an SDL sound.
 */
SI::Sound* SDL_SI::SdlFactory::createSound() {
    return new SdlSound();
}


//
// ----------------------------------------------Operators--------------------------------------------------------------
//
SDL_SI::SdlFactory& SDL_SI::SdlFactory::operator=(const SDL_SI::SdlFactory& other) {
    if (this != &other) {
        // nothing to do.
    }
    std::cout << "Game assigned." << std::endl;
    return *this;
}


