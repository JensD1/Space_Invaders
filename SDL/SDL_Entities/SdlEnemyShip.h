//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLENEMYSHIP_H
#define SPACE_INVADORS_SDLENEMYSHIP_H

#include "../../Abstract/Entities/EnemyShip.h"

namespace SDL_SI {
    class SdlEnemyShip : public SI::EnemyShip {
    public:
        // Constructors
        SdlEnemyShip(float, float, float, float, float, float);

        ~SdlEnemyShip();

        SdlEnemyShip(const SDL_SI::SdlEnemyShip&);

        // Operators
        SDL_SI::SdlEnemyShip& operator=(const SDL_SI::SdlEnemyShip&);

        // Methods
        void visualize(SI::Window*);
    };
}


#endif //SPACE_INVADORS_SDLENEMYSHIP_H
