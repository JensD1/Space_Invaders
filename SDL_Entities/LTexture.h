//
// Created by Jens on 20/03/2020.
//

#ifndef SPACE_INVADORS_LTEXTURE_H
#define SPACE_INVADORS_LTEXTURE_H

#include <string>
#include "SDL2/SDL.h"

namespace SDL_SI {
//Texture wrapper class
    class LTexture {
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;

        SDL_Renderer* gRenderer;

    public:
        //Initializes variables
        LTexture(SDL_Renderer*);

        //Deallocates memory
        ~LTexture();

        // copy constructor
        LTexture(const SDL_SI::LTexture&);

        // operators
        SDL_SI::LTexture& operator=(const SDL_SI::LTexture&);

        //Loads image at specified path
        bool loadFromFile(std::string path);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int, int, int, int, SDL_Rect *clip = nullptr);

        //Gets image dimensions
        int getWidth();
        int getHeight();
    };
}

#endif //SPACE_INVADORS_LTEXTURE_H
