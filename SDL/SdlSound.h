//
// Created by Jens on 24/04/2020.
//

#ifndef SPACE_INVADERS_SDLSdlSound_H
#define SPACE_INVADERS_SDLSdlSound_H

#include "../Abstract/Sound.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

namespace SDL_SI {
    class SdlSound : public SI::Sound {
    private:
        //The music that will be played
        Mix_Music* gMusic = nullptr;

        //The sound effects that will be used
        Mix_Chunk* gExplosion = nullptr;
        Mix_Chunk* gBonus = nullptr;
        Mix_Chunk* gBullet = nullptr;
        Mix_Chunk* gProjectile = nullptr;

    public:
        // Constructors
        SdlSound();

        virtual ~SdlSound();

        SdlSound(const SDL_SI::SdlSound&);

        SDL_SI::SdlSound& operator=(const SDL_SI::SdlSound&);

        // Methods
        //Starts up SDL and creates window
        bool init();

        void close();

        bool loadMedia();

        void pauseMusic();

        void resumeMusic();

        void playExplosion();

        void playBulletShot();

        void playBonus();

        void playProjectileShot();
    };
}

#endif //SPACE_INVADERS_SDLSdlSound_H
