//
// Created by Jens on 20/03/2020.
//

#include "SdlWindow.h"
#include "../GameConstants.h"
#include <assert.h>
#include "SDL2/SDL_image.h"

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SDL_SI::SdlWindow::SdlWindow()
{
    assert(SDL_SI::SdlWindow::init()); // zorg dat init correct voltooid kan worden!
    SDL_SI::SdlWindow::gSpriteSheetTexture = new SDL_SI::LTexture(SDL_SI::SdlWindow::gRenderer);
    assert(SDL_SI::SdlWindow::loadMedia()); // zorg ervoor dat de sprite images worden ingeladen.
}

SDL_SI::SdlWindow::~SdlWindow()
{
    SDL_SI::SdlWindow::close();
    delete SDL_SI::SdlWindow::gSpriteSheetTexture;
}

SDL_SI::SdlWindow::SdlWindow(const SDL_SI::SdlWindow& other)
{
    SDL_SI::SdlWindow::gSpriteSheetTexture = other.gSpriteSheetTexture;
    SDL_SI::SdlWindow::gRenderer = other.gRenderer;
    for(int i = 0; i < SDL_SI::NUMBER_OF_SPRITES; i++){
        SDL_SI::SdlWindow::gSpriteClips[i] = other.gSpriteClips[i];
    }
    SDL_SI::SdlWindow::gWindow = other.gWindow;
}

SDL_SI::SdlWindow& SDL_SI::SdlWindow::operator=(const SDL_SI::SdlWindow& other)
{
    if (this != &other){
        SDL_SI::SdlWindow::gSpriteSheetTexture = other.gSpriteSheetTexture;
        SDL_SI::SdlWindow::gRenderer = other.gRenderer;
        for(int i = 0; i < SDL_SI::NUMBER_OF_SPRITES; i++){
            SDL_SI::SdlWindow::gSpriteClips[i] = other.gSpriteClips[i];
        }
        SDL_SI::SdlWindow::gWindow = other.gWindow;
    }
    return *this;
}

bool SDL_SI::SdlWindow::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        SDL_SI::SdlWindow::gWindow = SDL_CreateWindow( "Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_SI::SCREEN_WIDTH, SDL_SI::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( SDL_SI::SdlWindow::gWindow == nullptr )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            SDL_SI::SdlWindow::gRenderer = SDL_CreateRenderer( SDL_SI::SdlWindow::gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( SDL_SI::SdlWindow::gRenderer == nullptr )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( SDL_SI::SdlWindow::gRenderer, 0x00, 0x00, 0x00, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

void SDL_SI::SdlWindow::close()
{
    //Free loaded images
    SDL_SI::SdlWindow::gSpriteSheetTexture->free();

    //Destroy window
    SDL_DestroyRenderer( SDL_SI::SdlWindow::gRenderer );
    SDL_DestroyWindow( SDL_SI::SdlWindow::gWindow );
    SDL_SI::SdlWindow::gWindow = NULL;
    SDL_SI::SdlWindow::gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

bool SDL_SI::SdlWindow::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !SDL_SI::SdlWindow::gSpriteSheetTexture->loadFromFile( "../Media/sprites.png" ) ) // de R" zorgt ervoor dat we niet \\ moeten plaatsen om een \ teken te krijgen.
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    else
    {
        // BOSS
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].x =  3;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].y =  0;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].w = 14;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].h = 14;

        // Standard enemy
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].x = 21;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].y =  1;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].w = 12;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].h = 12;

        // Player
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PLAYER_SPRITE].x = 36;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PLAYER_SPRITE].y = 15;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PLAYER_SPRITE].w = 13;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PLAYER_SPRITE].h = 13;

        // Bullet
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BULLET_SPRITE].x = 31;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BULLET_SPRITE].y = 21;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BULLET_SPRITE].w = 1;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BULLET_SPRITE].h = 4;

        // Projectile
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PROJECTILE_SPRITE].x = 100;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PROJECTILE_SPRITE].y = 19;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PROJECTILE_SPRITE].w = 3;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PROJECTILE_SPRITE].h = 7;

        // PBonus
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].x = 118;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].y = 4;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].w = 5;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].h = 7;

        // NBonus
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].x = 118;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].y = 19;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].w = 5;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].h = 7;
    }

    return success;
}

void SDL_SI::SdlWindow::update()
{
    //Update screen
    SDL_RenderPresent(SDL_SI::SdlWindow::gRenderer);
}

void SDL_SI::SdlWindow::clear()
{
    //Clear screen
    SDL_SetRenderDrawColor( SDL_SI::SdlWindow::gRenderer, 0x00, 0x00, 0x00, 0xFF ); // Dit zorgt ervoor dat bij RenderClear alles in het zwart wordt gezet.
    SDL_RenderClear(SDL_SI::SdlWindow::gRenderer);
}

void SDL_SI::SdlWindow::drawSprite(float xPos, float yPos, float tempWidth, float tempHeight, int type)
{

    //Render top left sprite
    int x = xPos * SDL_SI::SCREEN_WIDTH;
    int y = yPos * SDL_SI::SCREEN_HEIGHT;
    int width = tempWidth * SDL_SI::SCREEN_WIDTH;
    int height = tempHeight * SDL_SI::SCREEN_HEIGHT;
    SDL_SI::SdlWindow::gSpriteSheetTexture->render(x, y, width, height, &SDL_SI::SdlWindow::gSpriteClips[type]);
}
