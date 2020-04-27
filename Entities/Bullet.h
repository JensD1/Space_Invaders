//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_BULLET_H
#define SPACE_INVADORS_BULLET_H

#include "ReusableEntity.h"
namespace SI {
    class Bullet : public ReusableEntity {
    public:
        // Constructors
        Bullet(float, float, float, float, float, float);
        virtual ~Bullet();
        Bullet(const SI::Bullet&);

        // Operators
        SI::Bullet& operator=(const SI::Bullet&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
    };
}

#endif //SPACE_INVADORS_BULLET_H
