//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLBULLET_H
#define SPACE_INVADORS_SDLBULLET_H

#include "../Entities/ReusableEntity.h"

namespace SDL_SI {
    class SdlBullet : public SI::ReusableEntity {
    public:
        // Constructors
        SdlBullet(float, float, float, float, float, float);

        ~SdlBullet();

        SdlBullet(const SDL_SI::SdlBullet&);

        // Operators
        SDL_SI::SdlBullet& operator=(const SDL_SI::SdlBullet&);

        // Methods
        void visualize(SI::Window*);
    };
}

#endif //SPACE_INVADORS_SDLBULLET_H
