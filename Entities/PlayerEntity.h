//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_PLAYERENTITY_H
#define SPACE_INVADORS_PLAYERENTITY_H

#include "Entity.h"

namespace SI {
    class PlayerEntity : public SI::Entity {
    public:
        // Constructors
        PlayerEntity(float, float, float, float, float, float);
        virtual ~PlayerEntity();
        PlayerEntity(const SI::PlayerEntity&);

        // Operators
        SI::PlayerEntity& operator=(const SI::PlayerEntity&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
        virtual void updatePosition() = 0;
        virtual void hasCollision() = 0;
    };
}

#endif //SPACE_INVADORS_PLAYERENTITY_H
