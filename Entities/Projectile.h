//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_PROJECTILE_H
#define SPACE_INVADORS_PROJECTILE_H

#include "EnemyEntity.h"

namespace SI {
    class Projectile : public SI::EnemyEntity {
    private:
        bool isFired;
    public:
        // Constructors
        Projectile(float, float, float, float, float, float);
        virtual ~Projectile();
        Projectile(const Projectile&);

        // Operators
        Projectile& operator=(const Projectile&);

        // Methods
        virtual void visualize() = 0;
        void updatePosition();
        void hasCollision();
        bool getIsFired();
        void setIsFired(bool);
    };
}

#endif //SPACE_INVADORS_PROJECTILE_H
