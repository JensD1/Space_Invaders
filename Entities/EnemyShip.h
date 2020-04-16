//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_ENEMYSHIP_H
#define SPACE_INVADORS_ENEMYSHIP_H

#include "EnemyEntity.h"
#include <random>

namespace SI {
    class EnemyShip : public EnemyEntity {
    public:
        // Constructors
        EnemyShip(float, float, float, float, float, float);
        virtual ~EnemyShip();
        EnemyShip(const EnemyShip&);

        // Operators
        EnemyShip& operator=(const EnemyShip&);

        // Methods
        virtual void visualize() = 0;
        void updatePosition();
        void hasCollision();
        bool fireProjectile();
    };
}

#endif //SPACE_INVADORS_ENEMYSHIP_H
