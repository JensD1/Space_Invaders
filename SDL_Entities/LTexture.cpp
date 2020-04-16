//
// Created by Jens on 20/03/2020.
//

#include "LTexture.h"
#include "SDL2/SDL_image.h"
#include <iostream>

SDL_SI::LTexture::LTexture(SDL_Renderer* gRenderer)
{
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
    SDL_SI::LTexture::gRenderer = gRenderer;
}

SDL_SI::LTexture::~LTexture()
{
    //Deallocate
    free();
}

SDL_SI::LTexture::LTexture(const SDL_SI::LTexture& other)
{
    SDL_SI::LTexture::mTexture = other.mTexture;
    SDL_SI::LTexture::mWidth = other.mWidth;
    SDL_SI::LTexture::mHeight = other.mHeight;
    SDL_SI::LTexture::gRenderer = other.gRenderer;
}

SDL_SI::LTexture& SDL_SI::LTexture::operator=(const SDL_SI::LTexture& other)
{
    if(this != & other){
        SDL_SI::LTexture::mTexture = other.mTexture;
        SDL_SI::LTexture::mWidth = other.mWidth;
        SDL_SI::LTexture::mHeight = other.mHeight;
        SDL_SI::LTexture::gRenderer = other.gRenderer;
    }
    return *this;
}

bool SDL_SI::LTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0x80, 0xFF ) );

        //Create texture from surface pixels

        newTexture = SDL_CreateTextureFromSurface(SDL_SI::LTexture::gRenderer, loadedSurface);
        std::cout << SDL_GetError() << std::endl;
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            SDL_SI::LTexture::mWidth = loadedSurface->w;
            SDL_SI::LTexture::mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    SDL_SI::LTexture::mTexture = newTexture;
    return SDL_SI::LTexture::mTexture != nullptr;
}

void SDL_SI::LTexture::free()
{
    //Free texture if it exists
    if( SDL_SI::LTexture::mTexture != nullptr )
    {
        SDL_DestroyTexture( SDL_SI::LTexture::mTexture );
        SDL_SI::LTexture::mTexture = nullptr;
        SDL_SI::LTexture::mWidth = 0;
        SDL_SI::LTexture::mHeight = 0;
    }
}

void SDL_SI::LTexture::render( int x, int y, int width, int height, SDL_Rect* clip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, SDL_SI::LTexture::mWidth, SDL_SI::LTexture::mHeight};

    //Set clip rendering dimensions
    if( clip != nullptr )
    {
        renderQuad.w = width;
        renderQuad.h = height;
    }

    //Render to screen
    SDL_RenderCopy( SDL_SI::LTexture::gRenderer, SDL_SI::LTexture::mTexture, clip, &renderQuad );
}

int SDL_SI::LTexture::getWidth()
{
    return SDL_SI::LTexture::mWidth;
}

int SDL_SI::LTexture::getHeight()
{
    return SDL_SI::LTexture::mHeight;
}


