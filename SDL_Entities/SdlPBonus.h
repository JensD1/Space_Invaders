//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPBONUS_H
#define SPACE_INVADORS_SDLPBONUS_H

#include "../Entities/BonusEntity.h"

namespace SDL_SI {
    class SdlPBonus : public SI::BonusEntity {
    public:
        // Constructors
        SdlPBonus(float, float, float, float, float, float);
        ~SdlPBonus();
        SdlPBonus(const SDL_SI::SdlPBonus&);

        // Operators
        SDL_SI::SdlPBonus& operator=(const SDL_SI::SdlPBonus&);

        // Methods
        void visualize(SI::Window*);
    };
}
#endif //SPACE_INVADORS_SDLPBONUS_H
