//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_SDLFACTORY_H
#define SPACE_INVADORS_SDLFACTORY_H

#include "../Abstract/AFactory.h"

namespace SDL_SI {
    class SdlFactory : public SI::AFactory {
    public:
        // Constructors
        SdlFactory();

        ~SdlFactory();

        SdlFactory(const SDL_SI::SdlFactory&);

        // Methods
        SI::PlayerShip* createPlayerShip(float, float, float, float, float, float);

        SI::ReusableEntity* createBullet(float, float, float, float, float, float);

        SI::EnemyShip* createEnemyShip(float, float, float, float, float, float);

        SI::ReusableEntity* createProjectile(float, float, float, float, float, float);

        SI::BonusEntity* createPBonus(float, float, float, float, float, float);

        SI::BonusEntity* createNBonus(float, float, float, float, float, float);

        SI::Event* createEvent();

        SI::Timer* createTimer();

        SI::Window* createWindow();

        SI::Sound* createSound();

        // Operators
        SDL_SI::SdlFactory& operator=(const SDL_SI::SdlFactory&);
    };
}

#endif //SPACE_INVADORS_SDLFACTORY_H
