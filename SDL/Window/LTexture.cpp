//
// Created by Jens on 20/03/2020.
//

#include "LTexture.h"
#include "SDL2/SDL_image.h"
#include <iostream>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SDL_SI::LTexture::LTexture(SDL_Renderer* gRenderer, TTF_Font* gFont) {
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    SDL_SI::LTexture::nTexture = nullptr;
    SDL_SI::LTexture::nWidth = 0;
    SDL_SI::LTexture::nHeight = 0;
    SDL_SI::LTexture::gRenderer = gRenderer;
    SDL_SI::LTexture::gFont = gFont;
}

SDL_SI::LTexture::~LTexture() {
    //Deallocate
    free();
}

SDL_SI::LTexture::LTexture(const SDL_SI::LTexture& other) {
    SDL_SI::LTexture::mTexture = other.mTexture;
    SDL_SI::LTexture::mWidth = other.mWidth;
    SDL_SI::LTexture::mHeight = other.mHeight;
    SDL_SI::LTexture::nTexture = other.nTexture;
    SDL_SI::LTexture::nWidth = other.nWidth;
    SDL_SI::LTexture::nHeight = other.nHeight;
    SDL_SI::LTexture::gRenderer = other.gRenderer;
}

SDL_SI::LTexture& SDL_SI::LTexture::operator=(const SDL_SI::LTexture& other) {
    if (this != &other) {
        SDL_SI::LTexture::mTexture = other.mTexture;
        SDL_SI::LTexture::mWidth = other.mWidth;
        SDL_SI::LTexture::mHeight = other.mHeight;
        SDL_SI::LTexture::nTexture = other.nTexture;
        SDL_SI::LTexture::nWidth = other.nWidth;
        SDL_SI::LTexture::nHeight = other.nHeight;
        SDL_SI::LTexture::gRenderer = other.gRenderer;
    }
    return *this;
}

//
// ------------------------------------------------------Methods--------------------------------------------------------
//
/**
 * Create a texture from a rendered text.
 * @param textureText The text from which you want to create a texture (std::string).
 * @param textColor The color you want the text to be rendered (SDL_Color).
 * @return True when successful (Boolean).
 */
bool SDL_SI::LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor) {
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        //Create texture from surface pixels
        nTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (nTexture == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            //Get image dimensions
            nWidth = textSurface->w;
            nHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return nTexture != nullptr;
}

/**
 * load an image from a file.
 * @param path the path to the file (std::string).
 * @return True when successful (Boolean).
 */
bool SDL_SI::LTexture::loadImageFromFile(std::string path) {
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0x80, 0xFF));

        //Create texture from surface pixels

        newTexture = SDL_CreateTextureFromSurface(SDL_SI::LTexture::gRenderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            //Get image dimensions
            SDL_SI::LTexture::mWidth = loadedSurface->w;
            SDL_SI::LTexture::mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    SDL_SI::LTexture::mTexture = newTexture;
    return SDL_SI::LTexture::mTexture != nullptr;
}

/**
 * Free all allocated memory from LTexture's variables and objects.
 */
void SDL_SI::LTexture::free() {
    //Free texture if it exists
    if (SDL_SI::LTexture::mTexture != nullptr || SDL_SI::LTexture::nTexture != nullptr) {
        SDL_DestroyTexture(SDL_SI::LTexture::mTexture);
        SDL_DestroyTexture(SDL_SI::LTexture::nTexture);
        SDL_SI::LTexture::nTexture = nullptr;
        SDL_SI::LTexture::mTexture = nullptr;
        SDL_SI::LTexture::mWidth = 0;
        SDL_SI::LTexture::mHeight = 0;
        SDL_SI::LTexture::nWidth = 0;
        SDL_SI::LTexture::nHeight = 0;
    }
}

/**
 * render a text/sprite that has been loaded before by respectively loadFromRenderedText or loadImageFromFile. This
 * sprite will be rendered at a specific location and with a specific width and height.
 * @param type either TEXT or SPRITE depending on what you want to render (SDL_SI::TypeOfRender).
 * @param x the x position where you want the sprite to be rendered (int). (This is the x position of the top left
 *                corner)
 * @param y the y position where you want the sprite to be rendered (int). (This is the y position of the top left
 *                corner)
 * @param width This is the width of the sprite to be rendered (int).
 * @param height This is the height of the sprite to be rendered (int).
 * @param clip The rectangle that defines which pixels from the sprite sheet needs to be rendered (SDL_Rect*).
 */
void SDL_SI::LTexture::render(SDL_SI::TypeOfRender type, int x, int y, int width, int height, SDL_Rect* clip) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, SDL_SI::LTexture::nWidth, SDL_SI::LTexture::nHeight}; // standard for text.

    //Set clip rendering dimensions to the correct value for sprites.
    if (clip != nullptr) {
        renderQuad.w = width;
        renderQuad.h = height;
    }

    //Render to screen. This will take the clip and stretch it to fit the new dimensions and renders this.
    if (type == SDL_SI::SPRITE) {
        SDL_RenderCopy(SDL_SI::LTexture::gRenderer, SDL_SI::LTexture::mTexture, clip, &renderQuad);
    } else if (type == SDL_SI::TEXT) {
        // clip is a nullptr so the entire texture will be rendered.
        SDL_RenderCopy(SDL_SI::LTexture::gRenderer, SDL_SI::LTexture::nTexture, clip, &renderQuad);
        // make sure we don't create to many textures.
        SDL_DestroyTexture(SDL_SI::LTexture::nTexture);
        SDL_SI::LTexture::nTexture = nullptr;
        SDL_SI::LTexture::nWidth = 0;
        SDL_SI::LTexture::nHeight = 0;
    }
}


//
// ------------------------------------------------------Getters--------------------------------------------------------
//
int SDL_SI::LTexture::getmWidth() {
    return SDL_SI::LTexture::mWidth;
}

int SDL_SI::LTexture::getmHeight() {
    return SDL_SI::LTexture::mHeight;
}

int SDL_SI::LTexture::getnWidth() {
    return SDL_SI::LTexture::nWidth;
}

int SDL_SI::LTexture::getnHeight() {
    return SDL_SI::LTexture::nHeight;
}


