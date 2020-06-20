//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPROJECTILE_H
#define SPACE_INVADORS_SDLPROJECTILE_H

#include "../../Abstract/Entities/ReusableEntity.h"

namespace SDL_SI {
    class SdlProjectile : public SI::ReusableEntity {
    public:
        // Constructors
        SdlProjectile(float, float, float, float, float, float);

        ~SdlProjectile();

        SdlProjectile(const SDL_SI::SdlProjectile&);

        // Operators
        SDL_SI::SdlProjectile& operator=(const SDL_SI::SdlProjectile&);

        // Methods
        void visualize(SI::Window*);
    };
}

#endif //SPACE_INVADORS_SDLPROJECTILE_H
