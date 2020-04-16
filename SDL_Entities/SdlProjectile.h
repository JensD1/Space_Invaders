//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_SDLPROJECTILE_H
#define SPACE_INVADORS_SDLPROJECTILE_H

#include "../Entities/Projectile.h"
#include "SdlWindow.h"

namespace SDL_SI {
    class SdlProjectile : public SI::Projectile {
    private:
        // Variables
        SdlWindow* sdlWindow;

    public:
        // Constructors
        SdlProjectile(float, float, float, float, float, float, SdlWindow*);
        ~SdlProjectile();
        SdlProjectile(const SdlProjectile&);

        // Operators
        SdlProjectile& operator=(const SdlProjectile&);

        // Methods
        void visualize();
    };
}

#endif //SPACE_INVADORS_SDLPROJECTILE_H
