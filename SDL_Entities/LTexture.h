//
// Created by Jens on 20/03/2020.
//

#ifndef SPACE_INVADORS_LTEXTURE_H
#define SPACE_INVADORS_LTEXTURE_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include "SDL2/SDL.h"
#include "../SdlConstants.h"


namespace SDL_SI {
//Texture wrapper class
    class LTexture {
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;
        SDL_Texture* nTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
        //Text dimensions
        int nWidth;
        int nHeight;

        SDL_Renderer* gRenderer;

        //Globally used font
        TTF_Font* gFont;

    public:
        //Initializes variables
        LTexture(SDL_Renderer*, TTF_Font*);

        //Deallocates memory
        ~LTexture();

        // copy constructor
        LTexture(const SDL_SI::LTexture&);

        // operators
        SDL_SI::LTexture& operator=(const SDL_SI::LTexture&);

        //Loads image at specified path
        bool loadImageFromFile(std::string);

        bool loadFromRenderedText(std::string, SDL_Color);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(SDL_SI::TypeOfRender, int, int, int= 0, int= 0, SDL_Rect* clip = nullptr);

        //Gets image dimensions
        int getmWidth();

        int getmHeight();

        // Gets text dimensions
        int getnWidth();

        int getnHeight();
    };
}

#endif //SPACE_INVADORS_LTEXTURE_H
