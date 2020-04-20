//
// Created by Jens on 20/03/2020.
//

#ifndef SPACE_INVADORS_SDLCONSTANTS_H
#define SPACE_INVADORS_SDLCONSTANTS_H

namespace SDL_SI{
    //Screen dimension constants
    const int SCREEN_WIDTH = 750; //640;
    const int SCREEN_HEIGHT = 750; //480;
    enum Type{
        PLAYER_SPRITE,
        BULLET_SPRITE,
        ENEMY_SPRITE,
        PROJECTILE_SPRITE,
        BOSS_SPRITE,
        PBONUS_SPRITE,
        NBONUS_SPRITE
    };
    const int NUMBER_OF_SPRITES     = 7;
}

#endif //SPACE_INVADORS_SDLCONSTANTS_H
