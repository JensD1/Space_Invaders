//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLENEMYSHIP_H
#define SPACE_INVADORS_SDLENEMYSHIP_H

#include "../Entities/EnemyShip.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlEnemyShip : public SI::EnemyShip {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlEnemyShip(float, float, float, float, float, float, SdlWindow*);
        ~SdlEnemyShip();
        SdlEnemyShip(const SdlEnemyShip&);

        // Operators
        SdlEnemyShip& operator=(const SdlEnemyShip&);

        // Methods
        void visualize();
    };
}


#endif //SPACE_INVADORS_SDLENEMYSHIP_H
