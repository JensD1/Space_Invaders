//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLNBONUS_H
#define SPACE_INVADORS_SDLNBONUS_H

#include "../Entities/BonusEntity.h"

namespace SDL_SI {
    class SdlNBonus : public SI::BonusEntity {
    public:
        // Constructors
        SdlNBonus(float, float, float, float, float, float);
        ~SdlNBonus();
        SdlNBonus(const SDL_SI::SdlNBonus&);

        // Operators
        SDL_SI::SdlNBonus& operator=(const SDL_SI::SdlNBonus&);

        // Methods
        void visualize(SI::Window*);
    };
}

#endif //SPACE_INVADORS_SDLNBONUS_H
