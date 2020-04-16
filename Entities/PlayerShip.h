//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_PLAYERSHIP_H
#define SPACE_INVADORS_PLAYERSHIP_H

#include "PlayerEntity.h"

namespace SI {
    class PlayerShip : public PlayerEntity {
    public:
        // Constructors
        PlayerShip(float, float, float, float, float, float);
        virtual ~PlayerShip();
        PlayerShip(const PlayerShip&);

        // Operators
        PlayerShip& operator=(const PlayerShip&);

        // Methods
        virtual void visualize() = 0;
        void updatePosition();
        void hasCollision();
    };
}

#endif //SPACE_INVADORS_PLAYERSHIP_H
