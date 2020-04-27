//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_AFACTORY_H
#define SPACE_INVADORS_AFACTORY_H

#include "../Entities/PlayerShip.h"
#include "../Entities/ReusableEntity.h"
#include "../Entities/EnemyShip.h"
#include "../Entities/BonusEntity.h"
#include "../Entities/Event.h"
#include "../Entities/Timer.h"
#include "../Entities/Window.h"
#include "../Entities/Sound.h"

namespace SI {
    class AFactory {
    public:
        // methods
        virtual PlayerShip* createPlayerShip(float, float, float, float, float, float) = 0;
        virtual ReusableEntity* createBullet(float, float, float, float, float, float) = 0;
        virtual EnemyShip* createEnemyShip(float, float, float, float, float, float) = 0;
        virtual ReusableEntity* createProjectile(float, float, float, float, float, float) = 0;
        virtual BonusEntity* createPBonus(float, float, float, float, float, float) = 0;
        virtual BonusEntity* createNBonus(float, float, float, float, float, float) = 0;
        virtual Event* createEvent() = 0;
        virtual Timer* createTimer() = 0;
        virtual Window* createWindow() = 0;
        virtual Sound* createSound() = 0;

        //Constructors
        virtual ~AFactory(){};
    };
}
#endif //SPACE_INVADORS_AFACTORY_H
