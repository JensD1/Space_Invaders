//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLBULLET_H
#define SPACE_INVADORS_SDLBULLET_H

#include "../Entities/Bullet.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlBullet : public SI::Bullet {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlBullet(float, float, float, float, float, float, SdlWindow*);
        ~SdlBullet();
        SdlBullet(const SdlBullet&);

        // Operators
        SdlBullet& operator=(const SdlBullet&);

        // Methods
        void visualize();
    };
}

#endif //SPACE_INVADORS_SDLBULLET_H
