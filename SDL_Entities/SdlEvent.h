//
// Created by Jens on 16/03/2020.
//

#ifndef SPACE_INVADORS_SDLEVENT_H
#define SPACE_INVADORS_SDLEVENT_H

#include "../Entities/Event.h"
#include "SDL2/SDL.h"

namespace SDL_SI {
    class SdlEvent : public SI::Event {
    public:
        // Constructors
        SdlEvent();
        virtual ~SdlEvent();
        SdlEvent(const SdlEvent &);

        // Operators
        SdlEvent &operator=(const SdlEvent &);

        // Method
        std::set<SI::Control> handleEvent();
    };
}

#endif //SPACE_INVADORS_SDLEVENT_H
