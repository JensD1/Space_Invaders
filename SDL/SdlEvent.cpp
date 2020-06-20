//
// Created by Jens on 16/03/2020.
//

#include "SdlEvent.h"
#include <iostream>

//
// ------------------------------------------------Constructors---------------------------------------------------------
//
SDL_SI::SdlEvent::SdlEvent() : SI::Event() {
    std::cout << "SdlEvent created." << std::endl;
}

SDL_SI::SdlEvent::~SdlEvent() {
    std::cout << "SdlEvent Destroyed." << std::endl;
}

SDL_SI::SdlEvent::SdlEvent(const SDL_SI::SdlEvent& other) : SI::Event(other) {
    std::cout << "SdlEvent copied." << std::endl;
}

//
// -------------------------------------------------Operators-----------------------------------------------------------
//
SDL_SI::SdlEvent& SDL_SI::SdlEvent::operator=(const SDL_SI::SdlEvent& other) {
    if (this != &other) {
        SI::Event::operator=(other);
    }
    std::cout << "SdlEvent Destroyed." << std::endl;
    return *this;
}

//
// ---------------------------------------------------Methods-----------------------------------------------------------
//
/**
 * When this method is called, All events that happened (keyboard presses and quit) are returned as a set.
 * @return a set of events (SI::Control).
 */
std::set<SI::Control> SDL_SI::SdlEvent::handleEvent() {
    // A set does not contain duplicates.
    std::set<SI::Control> controlArray;
    controlArray.insert(SI::IDLE); // standaard op idle.

    // Event handler
    SDL_Event e;

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
            controlArray.insert(SI::QUIT);
        }
    }

    const Uint8* state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_SPACE]) {
        controlArray.insert(SI::SPACE);
    }
    if (state[SDL_SCANCODE_LEFT]) {
        controlArray.insert(SI::LEFT);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        controlArray.insert(SI::RIGHT);
    }
    if (state[SDL_SCANCODE_P]) {
        controlArray.insert(SI::PAUSE);
    }
    return controlArray;
}
