//
// Created by Jens on 20/03/2020.
//

#include "SdlWindow.h"
#include "../GameConstants.h"
#include <assert.h>
#include "SDL2/SDL_image.h"
#include <iostream>

//
// --------------------------------------------------Constructors-------------------------------------------------------
//
SDL_SI::SdlWindow::SdlWindow() : SI::Window() {
    assert(SDL_SI::SdlWindow::init()); // zorg dat init correct voltooid kan worden!
    SDL_SI::SdlWindow::gFont = TTF_OpenFont("../Media/aAbsoluteEmpire.ttf", SI::SCORE_SIZE);
    SDL_SI::SdlWindow::gTexture = new SDL_SI::LTexture(SDL_SI::SdlWindow::gRenderer, SDL_SI::SdlWindow::gFont);
    assert(SDL_SI::SdlWindow::loadSpriteMedia()); // zorg ervoor dat de sprite images worden ingeladen.
    assert(SDL_SI::SdlWindow::loadTextMedia()); // zorg ervoor dat de Text wordt ingeladen.
}

SDL_SI::SdlWindow::~SdlWindow() {
    SDL_SI::SdlWindow::close();
    delete SDL_SI::SdlWindow::gTexture;
}

SDL_SI::SdlWindow::SdlWindow(const SDL_SI::SdlWindow& other) : SI::Window(other) {
    SDL_SI::SdlWindow::gTexture = other.gTexture;
    SDL_SI::SdlWindow::gRenderer = other.gRenderer;
    for (int i = 0; i < SDL_SI::NUMBER_OF_SPRITES; i++) {
        SDL_SI::SdlWindow::gSpriteClips[i] = other.gSpriteClips[i];
    }
    SDL_SI::SdlWindow::gWindow = other.gWindow;
}

//
// --------------------------------------------------Operators----------------------------------------------------------
//
SDL_SI::SdlWindow& SDL_SI::SdlWindow::operator=(const SDL_SI::SdlWindow& other) {
    if (this != &other) {
        SDL_SI::SdlWindow::gTexture = other.gTexture;
        SDL_SI::SdlWindow::gRenderer = other.gRenderer;
        for (int i = 0; i < SDL_SI::NUMBER_OF_SPRITES; i++) {
            SI::Window::operator=(other);
            SDL_SI::SdlWindow::gSpriteClips[i] = other.gSpriteClips[i];
        }
        SDL_SI::SdlWindow::gWindow = other.gWindow;
    }
    return *this;
}

//
// ---------------------------------------------------Methods-----------------------------------------------------------
//
/**
 * Initialise the window, the Renderer and SDL.
 * @return True in case everything is initialised correctly (bool).
 */
bool SDL_SI::SdlWindow::init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        SDL_SI::SdlWindow::gWindow = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                                      SDL_SI::SCREEN_WIDTH, SDL_SI::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (SDL_SI::SdlWindow::gWindow == nullptr) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Create renderer for window
            SDL_SI::SdlWindow::gRenderer = SDL_CreateRenderer(SDL_SI::SdlWindow::gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (SDL_SI::SdlWindow::gRenderer == nullptr) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(SDL_SI::SdlWindow::gRenderer, 0x00, 0x00, 0x00, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
                    success = false;
                }
                //Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

/**
 * Free all allocated memory.
 */
void SDL_SI::SdlWindow::close() {
    //Free loaded images
    SDL_SI::SdlWindow::gTexture->free();

    //Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;

    //Destroy window
    SDL_DestroyRenderer(SDL_SI::SdlWindow::gRenderer);
    SDL_DestroyWindow(SDL_SI::SdlWindow::gWindow);
    SDL_SI::SdlWindow::gWindow = NULL;
    SDL_SI::SdlWindow::gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * Load the spritesheet save all used sprite clips in an array.
 * @return True when successful (bool).
 */
bool SDL_SI::SdlWindow::loadSpriteMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!SDL_SI::SdlWindow::gTexture->loadImageFromFile(
            "../Media/sprites.png")) // de R" zorgt ervoor dat we niet \\ moeten plaatsen om een \ teken te krijgen.
    {
        printf("Failed to load sprite sheet texture!\n");
        success = false;
    } else {
        // BOSS
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].x = 3;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].y = 0;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].w = 14;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::BOSS_SPRITE].h = 14;

        // Standard enemy
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].x = 21;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::ENEMY_SPRITE].y = 1;
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
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].x = 152;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].y = 2;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].w = 34;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::PBONUS_SPRITE].h = 36;

        // NBonus
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].x = 154;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].y = 39;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].w = 30;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::NBONUS_SPRITE].h = 32;

        // Title
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::TITLE_SPRITE].x = 0;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::TITLE_SPRITE].y = 544;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::TITLE_SPRITE].w = 1280;
        SDL_SI::SdlWindow::gSpriteClips[SDL_SI::TITLE_SPRITE].h = 700;
    }

    return success;
}

/**
 * Create a texture from a text. The text is "SPACE INVADERS".
 * @return True when successful (bool).
 */
bool SDL_SI::SdlWindow::loadTextMedia() {
    //Loading success flag
    bool success = true;

    //Open the font
    if (gFont == nullptr) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    } else {
        //Render text
        SDL_Color textColor = {255, 255, 255};
        if (!gTexture->loadFromRenderedText("SPACE INVADERS", textColor)) {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }

    return success;
}

/**
 * Update the screen by rendering everything on the renderer.
 */
void SDL_SI::SdlWindow::update() {
    //Update screen
    SDL_RenderPresent(SDL_SI::SdlWindow::gRenderer);
}

/**
 * clear the renderer and set the renderer to black.
 */
void SDL_SI::SdlWindow::clear() {
    //Clear screen
    SDL_SetRenderDrawColor(SDL_SI::SdlWindow::gRenderer, 0x00, 0x00, 0x00,
                           0xFF); // Dit zorgt ervoor dat bij RenderClear alles in het zwart wordt gezet.
    SDL_RenderClear(SDL_SI::SdlWindow::gRenderer);
}

/***
 * Draw a requested sprite on a specific location with a specific width and height on the renderer.
 * Once update() is called, this will be rendered on the window.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param tempWidth The width of the sprite to be rendered. Must be within the range of 0 and 1.
 * @param tempHeight The Height of the sprite to be rendered. Must be within the range of 0 and 1.
 * @param type The requested sprite clip to be rendered (SDL_SI::Type).
 */
void SDL_SI::SdlWindow::drawSprite(float xPos, float yPos, float tempWidth, float tempHeight, int type) {
    //Render top left sprite
    int x = xPos * SDL_SI::SCREEN_WIDTH;
    int y = yPos * SDL_SI::SCREEN_HEIGHT;
    int width = tempWidth * SDL_SI::SCREEN_WIDTH;
    int height = tempHeight * SDL_SI::SCREEN_HEIGHT;
    SDL_SI::SdlWindow::gTexture->render(SDL_SI::SPRITE, x, y, width, height, &SDL_SI::SdlWindow::gSpriteClips[type]);
}

/**
 * Draw a requested text on a specific location on the renderer.
 * Once update() is called, this will be rendered on the window.
 * @param xPos The x position of the upper left corner (float). Must be within the range of 0 and 1 (respectively left and right).
 * @param yPos The y position of the upper left corner (float). Must be within the range of 0 and 1 (respectively up and down).
 * @param string The text to be rendered (std::string).
 */
void SDL_SI::SdlWindow::drawText(float xPos, float yPos, std::string string) {
    //Render top left sprite
    int x = xPos * SDL_SI::SCREEN_WIDTH;
    int y = yPos * SDL_SI::SCREEN_HEIGHT;
    SDL_Color textColor = {255, 255, 255};
    SDL_SI::SdlWindow::gTexture->loadFromRenderedText(string, textColor);
    SDL_SI::SdlWindow::gTexture->render(SDL_SI::TEXT, x, y);
}

/**
 * Visualize the start screen. The update method must be ran afterwards to see the effect.
 */
void SDL_SI::SdlWindow::visualizeStartScreen() {
    SDL_SI::SdlWindow::drawSprite(SDL_SI::TITLE_X, SDL_SI::TITLE_Y, TITLE_WIDTH, SDL_SI::TITLE_HEIGHT,
                                  SDL_SI::TITLE_SPRITE);
    SDL_SI::SdlWindow::drawText(SDL_SI::START_TEXT_X_POS, SDL_SI::START_TEXT_Y_POS, "PRESS SPACE TO START");
    SDL_SI::SdlWindow::drawSprite(SDL_SI::START_SCREEN_SPRITE_1_X_POS, SDL_SI::START_SCREEN_SPRITE_1_Y_POS,
                                  SI::ENEMY_WIDTH, SI::ENEMY_HEIGHT, SDL_SI::ENEMY_SPRITE);
    SDL_SI::SdlWindow::drawSprite(SI::PLAYER_START_POS_X, SI::PLAYER_START_POS_Y, SDL_SI::START_SCREEN_SPRITE_2_WIDTH,
                                  SDL_SI::START_SCREEN_SPRITE_2_HEIGHT, SDL_SI::PLAYER_SPRITE);
    SDL_SI::SdlWindow::drawSprite(SDL_SI::START_SCREEN_SPRITE_3_X_POS, SDL_SI::START_SCREEN_SPRITE_3_Y_POS,
                                  SI::BULLET_WIDTH, SI::BULLET_HEIGHT, SDL_SI::BULLET_SPRITE);
}

/**
 * Visualize the end screen. The update method must be ran afterwards to see the effect.
 * @param score The score to be printed (int).
 * @param won has the player won the game (bool).
 */
void SDL_SI::SdlWindow::visualizeEndScreen(int score, bool won) {
    std::string string;
    if (won) {
        string = "YOU WON!";
    } else {
        string = "YOU LOSE";
    }
    SDL_SI::SdlWindow::drawText(SDL_SI::END_SCREEN_TEXT_1_X_POS, SDL_SI::END_SCREEN_TEXT_1_Y_POS, string);
    SDL_SI::SdlWindow::drawText(SDL_SI::END_SCREEN_TEXT_2_X_POS, SDL_SI::END_SCREEN_TEXT_2_Y_POS,
                                "SCORE:" + std::to_string(score));
    SDL_SI::SdlWindow::drawText(SDL_SI::END_SCREEN_TEXT_3_X_POS, SDL_SI::END_SCREEN_TEXT_3_Y_POS,
                                "PRESS SPACE TO START");
}

/**
 * Visualise the score.
 * @param score The score to be printed (int).
 */
void SDL_SI::SdlWindow::visualizeScore(int score) {
    SDL_SI::SdlWindow::drawText(SI::SCORE_START_POS_X, SI::SCORE_START_POS_Y, "Score: " + std::to_string(score));
}
