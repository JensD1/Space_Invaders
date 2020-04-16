//
// Created by Jens on 2/03/2020.
//

#include "SdlFactory.h"
#include <iostream>
#include "../SDL_Entities/SdlBullet.h"
#include "../SDL_Entities/SdlEnemyShip.h"
#include "../SDL_Entities/SdlNBonus.h"
#include "../SDL_Entities/SdlPBonus.h"
#include "../SDL_Entities/SdlPlayerShip.h"
#include "../SDL_Entities/SdlProjectile.h"
#include "../GameConstants.h"
#include "../SDL_Entities/SdlTimer.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlFactory::SdlFactory()
{
    SDL_SI::SdlFactory::sdlWindow = new SDL_SI::SdlWindow();
    std::cout << "SDL Factory created." << std::endl;
}

SDL_SI::SdlFactory::~SdlFactory()
{
    delete SDL_SI::SdlFactory::sdlWindow;
    std::cout << "SDL Factory destroyed." << std::endl;
}

SDL_SI::SdlFactory::SdlFactory(const SDL_SI::SdlFactory& other)
{
    SDL_SI::SdlFactory::sdlWindow = other.sdlWindow;
    std::cout << "SDL Factory copied." << std::endl;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
SI::PlayerShip* SDL_SI::SdlFactory::createPlayerShip(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlPlayerShip(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::Bullet* SDL_SI::SdlFactory::createBullet(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlBullet(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::EnemyShip* SDL_SI::SdlFactory::createEnemyShip(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlEnemyShip(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::Projectile* SDL_SI::SdlFactory::createProjectile(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlProjectile(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::NBonus* SDL_SI::SdlFactory::createNBonus(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlNBonus(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::PBonus* SDL_SI::SdlFactory::createPBonus(float xPos, float yPos, float width, float height, float dx, float dy)
{
    return new SdlPBonus(xPos, yPos, width, height, dx, dy, SDL_SI::SdlFactory::sdlWindow);
}

SI::Event* SDL_SI::SdlFactory::createEvent()
{
    return new SdlEvent();
}

SI::Timer* SDL_SI::SdlFactory::createTimer()
{
    return new SdlTimer();
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlFactory& SDL_SI::SdlFactory::operator=(const SDL_SI::SdlFactory& other)
{
    if(this != &other){
        SDL_SI::SdlFactory::sdlWindow = other.sdlWindow;
    }
    std::cout << "Game assigned." << std::endl;
    return *this;
}

void SDL_SI::SdlFactory::clearWindow()
{
    SDL_SI::SdlFactory::sdlWindow->clear();
}

void SDL_SI::SdlFactory::updateWindow()
{
    SDL_SI::SdlFactory::sdlWindow->update();
}




