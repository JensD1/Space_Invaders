//
// Created by Jens on 20/03/2020.
//

#ifndef SPACE_INVADORS_SDLWINDOW_H
#define SPACE_INVADORS_SDLWINDOW_H

#include "SDL2/SDL.h"
#include "LTexture.h"
#include "../GameConstants.h"
#include "../SdlConstants.h"
#include "../Entities/Window.h"

namespace SDL_SI {
class SdlWindow: public SI::Window{
    private:
        //The window we'll be rendering to
        SDL_Window* gWindow = NULL;

        //The window renderer
        SDL_Renderer* gRenderer = NULL;

        //Scene sprites
        SDL_Rect gSpriteClips[SDL_SI::NUMBER_OF_SPRITES];
        LTexture* gSpriteSheetTexture;

    public:
        // Constructors
        SdlWindow();
        ~SdlWindow();
        SdlWindow(const SdlWindow&);

        // Operators
        SdlWindow& operator=(const SdlWindow&);

        //Starts up SDL and creates window
        bool init();

        //Loads media
        bool loadMedia();

        //Frees media and shuts down SDL
        void close();

        void update();
        void clear();
        void drawSprite(float, float, float, float, int);
    };
}

#endif //SPACE_INVADORS_SDLWINDOW_H
