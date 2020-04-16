//
// Created by Jens on 16/03/2020.
//

#ifndef SPACE_INVADORS_GAMECONSTANTS_H
#define SPACE_INVADORS_GAMECONSTANTS_H
namespace SI {
    // Global constants
    enum Control {
        IDLE, SPACE, LEFT, RIGHT, QUIT
    };

    // Player constants
    const float PLAYERSPEED         = 0.01;
    const float PLAYER_WIDTH        = 0.05;
    const float PLAYER_HEIGHT       = 0.05;
    const float PLAYER_START_POS_X  = 0.5 - PLAYER_WIDTH / 2;
    const float PLAYER_START_POS_Y  = 0.9 - PLAYER_HEIGHT / 2;

    // Enemy constants
    const float ENEMYSPEED_H        = 0.001;
    const float ENEMYSPEED_V        = 0.01;
    const float ENEMY_WIDTH         = 0.05;
    const float ENEMY_HEIGHT        = 0.05;
    const int   ENEMY_ROWS          = 3;
    const int   ENEMY_COLUMS        = 10;
    const float ENEMY_SPACING       = ENEMY_WIDTH + 0.02;   // Momenteel heb ik het gekozen dat het vanaf de origin van
                                                            // de vorige sprite is ==> ik wil minimaal de ENEMY_WIDTH
                                                            // hebben zodat deze niet in elkaar zitten.
    const float ENEMY_START_POS_X   = (1 - ((ENEMY_COLUMS - 1) * ENEMY_SPACING + ENEMY_WIDTH))/2;
    const float ENEMY_START_POS_Y   = 0.05;
    const float ENEMY_OFFSET_BOARDERS_L = 0.5 * ENEMY_WIDTH;
    const float ENEMY_OFFSET_BOARDERS_R = ENEMY_OFFSET_BOARDERS_L + ENEMY_WIDTH;
    const int ENEMY_FIRECHANCE        = 3;

    // Bullet constants
    const float BULLET_DISTANCE_PLAYER =    -0.01;
    const float BULLET_HEIGHT = 0.02;
    const float BULLET_WIDTH = 0.01;
    const float BULLETSPEED = -0.01;

    // Projectile constants
    const float PROJECTILE_DISTANCE_ENEMIE = 0.01;
    const float PROJECTILE_HEIGHT = 0.02;
    const float PROJECTILE_WIDTH = 0.01;
    const float PROJECTILESPEED = 0.005;
    const int MAXPROJECTILES = 5;

    const float BONUS_HEIGHT = 0.025;
    const float BONUS_WIDTH = 0.025;
    const float BONUSSPEED = 0.001;
    const int BONUS_SWAWN_CHANCE = 5; // This change is per 10000 ==> 10000 equals 100% and 0 equals 0%
    const float BONUS_SPAWN_HEIGHT = 0;

    const float OUT_OF_SCREEN = -1;

    const float POSITIONAL_ERROR_MARGIN = 0.001;

    // timing
    const unsigned long fpsMs = 8; // Frames Per Second formula: (1/ SDL_SI::FPP) * 1000  // momenteel +-120 fps (133)
    const unsigned long TIME_BETWEEN_SHOOTING_MS = 300;
    const unsigned long BONUS_WORKING_TIME_MS = 5000;
}

#endif //SPACE_INVADORS_GAMECONSTANTS_H
