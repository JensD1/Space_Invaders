//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPLAYERSHIP_H
#define SPACE_INVADORS_SDLPLAYERSHIP_H

#include "../Entities/PlayerShip.h"

namespace SDL_SI {
    class SdlPlayerShip : public SI::PlayerShip {
    private:
        int j;
    public:
        // Constructors
        SdlPlayerShip(float, float, float, float, float, float);
        ~SdlPlayerShip();
        SdlPlayerShip(const SDL_SI::SdlPlayerShip&);

        // Operators
        SDL_SI::SdlPlayerShip& operator=(const SDL_SI::SdlPlayerShip&);

        // Methods
        void visualize(SI::Window*);
    };
}

#endif //SPACE_INVADORS_SDLPLAYERSHIP_H
