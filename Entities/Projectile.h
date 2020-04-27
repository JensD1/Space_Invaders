//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_PROJECTILE_H
#define SPACE_INVADORS_PROJECTILE_H

#include "ReusableEntity.h"

namespace SI {
    class Projectile : public SI::ReusableEntity {
    public:
        // Constructors
        Projectile(float, float, float, float, float, float);
        virtual ~Projectile();
        Projectile(const SI::Projectile&);

        // Operators
        SI::Projectile& operator=(const SI::Projectile&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
        void updatePosition();
        void hasCollision();
    };
}

#endif //SPACE_INVADORS_PROJECTILE_H
