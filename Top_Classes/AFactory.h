//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_AFACTORY_H
#define SPACE_INVADORS_AFACTORY_H

#include "../Entities/PlayerShip.h"
#include "../Entities/Bullet.h"
#include "../Entities/EnemyShip.h"
#include "../Entities/Projectile.h"
#include "../Entities/PBonus.h"
#include "../Entities/NBonus.h"
#include "../Entities/Event.h"
#include "../Entities/Timer.h"

namespace SI {
    class AFactory {
    public:
        // methods
        virtual PlayerShip* createPlayerShip(float, float, float, float, float, float) = 0;
        virtual Bullet* createBullet(float, float, float, float, float, float) = 0;
        virtual EnemyShip* createEnemyShip(float, float, float, float, float, float) = 0;
        virtual Projectile* createProjectile(float, float, float, float, float, float) = 0;
        virtual PBonus* createPBonus(float, float, float, float, float, float) = 0;
        virtual NBonus* createNBonus(float, float, float, float, float, float) = 0;
        virtual Event* createEvent() = 0;
        virtual Timer* createTimer() = 0;

        //Constructors
        virtual ~AFactory(){};

        // Methods
        virtual void clearWindow() = 0;
        virtual void updateWindow() = 0;
    };
}
#endif //SPACE_INVADORS_AFACTORY_H
