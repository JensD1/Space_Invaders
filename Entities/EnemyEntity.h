//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_ENEMYENTITY_H
#define SPACE_INVADORS_ENEMYENTITY_H

#include "Entity.h"
namespace SI {
    class EnemyEntity : public Entity {
    public:
        // Constructors
        EnemyEntity(float, float, float, float, float, float);
        virtual ~EnemyEntity();
        EnemyEntity(const EnemyEntity&);

        // Operators
        EnemyEntity& operator=(const EnemyEntity&);

        // Methods
        virtual void visualize() = 0;
        virtual void updatePosition() = 0;
        virtual void hasCollision() = 0;
    };
}

#endif //SPACE_INVADORS_ENEMYENTITY_H
