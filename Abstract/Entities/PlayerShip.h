//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_PLAYERSHIP_H
#define SPACE_INVADORS_PLAYERSHIP_H

#include "Entity.h"
#include "../Window.h"

namespace SI {
    class PlayerShip : public Entity {
    protected:
        int lives;
    public:
        // Constructors
        PlayerShip(float, float, float, float, float, float);

        virtual ~PlayerShip();

        PlayerShip(const SI::PlayerShip&);

        // Operators
        SI::PlayerShip& operator=(const SI::PlayerShip&);

        // Methods
        void setLives(int);

        int getLives();

        virtual void visualize(SI::Window*) = 0;
    };
}

#endif //SPACE_INVADORS_PLAYERSHIP_H
