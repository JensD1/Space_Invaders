//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPBONUS_H
#define SPACE_INVADORS_SDLPBONUS_H

#include "../Entities/PBonus.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlPBonus : public SI::PBonus {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlPBonus(float, float, float, float, float, float, SdlWindow*);
        ~SdlPBonus();
        SdlPBonus(const SdlPBonus&);

        // Operators
        SdlPBonus& operator=(const SdlPBonus&);

        // Methods
        void visualize();
    };
}
#endif //SPACE_INVADORS_SDLPBONUS_H
