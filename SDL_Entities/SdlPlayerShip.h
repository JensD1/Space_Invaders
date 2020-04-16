//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPLAYERSHIP_H
#define SPACE_INVADORS_SDLPLAYERSHIP_H

#include "../Entities/PlayerShip.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlPlayerShip : public SI::PlayerShip {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlPlayerShip(float, float, float, float, float, float, SdlWindow*);
        ~SdlPlayerShip();
        SdlPlayerShip(const SdlPlayerShip&);

        // Operators
        SdlPlayerShip& operator=(const SdlPlayerShip&);

        // Methods
        void visualize();
    };
}

#endif //SPACE_INVADORS_SDLPLAYERSHIP_H
