//
// Created by Jens on 20/03/2020.
//

#ifndef SPACE_INVADORS_SDLCONSTANTS_H
#define SPACE_INVADORS_SDLCONSTANTS_H

#include "GameConstants.h"

namespace SDL_SI {
    //Screen dimension constants
    const int SCREEN_WIDTH = 800; //750; //640;
    const int SCREEN_HEIGHT = 750; //750; //480;

    // Start screen constants
    const float TITLE_WIDTH = 0.7;
    const float TITLE_HEIGHT = 0.5;
    const float TITLE_X = 0.5 - TITLE_WIDTH / 2;
    const float TITLE_Y = 0.02;
    const float START_TEXT_X_POS = 0.17;
    const float START_TEXT_Y_POS = 0.8;
    const float START_SCREEN_SPRITE_1_X_POS = 0.475;
    const float START_SCREEN_SPRITE_1_Y_POS = 0.55;
    const float START_SCREEN_SPRITE_2_WIDTH = 0.05;
    const float START_SCREEN_SPRITE_2_HEIGHT = 0.05;
    const float START_SCREEN_SPRITE_3_X_POS = SI::PLAYER_START_POS_X + (SI::PLAYER_WIDTH - SI::BULLET_WIDTH) / 2;
    const float START_SCREEN_SPRITE_3_Y_POS = 0.7;

    // End screen constants
    const float END_SCREEN_TEXT_1_X_POS = 0.375;
    const float END_SCREEN_TEXT_1_Y_POS = 0.2;
    const float END_SCREEN_TEXT_2_X_POS = 0.35;
    const float END_SCREEN_TEXT_2_Y_POS = 0.4;
    const float END_SCREEN_TEXT_3_X_POS = 0.17;
    const float END_SCREEN_TEXT_3_Y_POS = 0.8;

    enum Type {
        PLAYER_SPRITE,
        BULLET_SPRITE,
        ENEMY_SPRITE,
        PROJECTILE_SPRITE,
        BOSS_SPRITE,
        PBONUS_SPRITE,
        NBONUS_SPRITE,
        TITLE_SPRITE
    };
    enum TypeOfRender {
        SPRITE,
        TEXT
    };
    const int NUMBER_OF_SPRITES = 8;
}

#endif //SPACE_INVADORS_SDLCONSTANTS_H
