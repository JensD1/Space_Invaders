//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLNBONUS_H
#define SPACE_INVADORS_SDLNBONUS_H

#include "../Entities/NBonus.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlNBonus : public SI::NBonus {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlNBonus(float, float, float, float, float, float, SdlWindow*);
        ~SdlNBonus();
        SdlNBonus(const SdlNBonus&);

        // Operators
        SdlNBonus& operator=(const SdlNBonus&);

        // Methods
        void visualize();
    };
}

#endif //SPACE_INVADORS_SDLNBONUS_H
