//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_BULLET_H
#define SPACE_INVADORS_BULLET_H

#include "PlayerEntity.h"
namespace SI {
    class Bullet : public PlayerEntity {
    private:
        bool bulletShot;
    public:
        // Constructors
        Bullet(float, float, float, float, float, float);
        virtual ~Bullet();
        Bullet(const SI::Bullet&);

        // Operators
        SI::Bullet& operator=(const SI::Bullet&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
        void updatePosition();
        void hasCollision();
        bool getBulletShot();
        void setBulletShot(bool);
    };
}

#endif //SPACE_INVADORS_BULLET_H
