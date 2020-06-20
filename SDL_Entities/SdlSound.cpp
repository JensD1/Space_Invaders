//
// Created by Jens on 24/04/2020.
//

#include "SdlSound.h"
#include <iostream>
#include <assert.h>

//
// ------------------------------------------------------Constructors---------------------------------------------------
//
SDL_SI::SdlSound::SdlSound() {
    assert(SDL_SI::SdlSound::init());
    assert(loadMedia());
    //Play the music
    Mix_PlayMusic(gMusic, -1);
}

SDL_SI::SdlSound::~SdlSound() {
    SDL_SI::SdlSound::close();
}

SDL_SI::SdlSound::SdlSound(const SDL_SI::SdlSound& other) {
    gMusic = other.gMusic;
    gExplosion = other.gExplosion;
    gBullet = other.gBullet;
    gBonus = other.gBonus;
    gProjectile = other.gProjectile;
}

//
// -----------------------------------------------------Operators-------------------------------------------------------
//
SDL_SI::SdlSound& SDL_SI::SdlSound::operator=(const SDL_SI::SdlSound& other) {
    if (this != &other) {
        gMusic = other.gMusic;
        gExplosion = other.gExplosion;
        gBullet = other.gBullet;
        gBonus = other.gBonus;
        gProjectile = other.gProjectile;
    }
    return *this;
}

//
// ------------------------------------------------------Methods--------------------------------------------------------
//
/**
 * Free all allocated memory for sound and quit the SDL mixer.
 */
void SDL_SI::SdlSound::close() {
    //Free the sound effects
    Mix_FreeChunk(SDL_SI::SdlSound::gExplosion);
    Mix_FreeChunk(SDL_SI::SdlSound::gBonus);
    Mix_FreeChunk(SDL_SI::SdlSound::gBullet);
    Mix_FreeChunk(SDL_SI::SdlSound::gProjectile);

    SDL_SI::SdlSound::gExplosion = nullptr;
    SDL_SI::SdlSound::gBonus = nullptr;
    SDL_SI::SdlSound::gBullet = nullptr;
    SDL_SI::SdlSound::gProjectile = nullptr;

    //Free the music
    Mix_FreeMusic(SDL_SI::SdlSound::gMusic);
    SDL_SI::SdlSound::gMusic = nullptr;

    //Quit SDL subsystems
    Mix_Quit(); // we will quit SDL in SdlWindow
}

/**
 * initialize the mixer and SDL.
 * @return true when successful (bool)
 */
bool SDL_SI::SdlSound::init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Initialize SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            success = false;
        }
    }

    return success;
}

/**
 * Load all sound fragments as chunks and load the music.
 * @return True when successful (bool)
 */

bool SDL_SI::SdlSound::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load music
    SDL_SI::SdlSound::gMusic = Mix_LoadMUS("../Media/Electronic-Fantasy.wav");
    if (SDL_SI::SdlSound::gMusic == nullptr) {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
    SDL_SI::SdlSound::gExplosion = Mix_LoadWAV("../Media/Explosion.wav");
    if (SDL_SI::SdlSound::gExplosion == nullptr) {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    //Load sound effects
    SDL_SI::SdlSound::gBullet = Mix_LoadWAV("../Media/BulletShot.wav");
    if (SDL_SI::SdlSound::gExplosion == nullptr) {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    //Load sound effects
    SDL_SI::SdlSound::gBonus = Mix_LoadWAV("../Media/bonus.wav");
    if (SDL_SI::SdlSound::gExplosion == nullptr) {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    //Load sound effects
    SDL_SI::SdlSound::gProjectile = Mix_LoadWAV("../Media/projectileShot.wav");
    if (SDL_SI::SdlSound::gExplosion == nullptr) {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    return success;
}

/**
 * Pause the music.
 */
void SDL_SI::SdlSound::pauseMusic() {
    // Pause the music
    Mix_PauseMusic();
}

/**
 * resume the music.
 */
void SDL_SI::SdlSound::resumeMusic() {
    // Resume the music
    Mix_ResumeMusic();
}

/**
 * Play the explosion sound.
 */
void SDL_SI::SdlSound::playExplosion() {
    Mix_PlayChannel(-1, SDL_SI::SdlSound::gExplosion, 0);
}

/**
 * Play the bullet shot sound.
 */
void SDL_SI::SdlSound::playBulletShot() {
    Mix_PlayChannel(-1, SDL_SI::SdlSound::gBullet, 0);
}

/**
 * Play the Bonus aquired sound.
 */
void SDL_SI::SdlSound::playBonus() {
    Mix_PlayChannel(-1, SDL_SI::SdlSound::gBonus, 0);
}

/**
 * Play the projectile shot sound.
 */
void SDL_SI::SdlSound::playProjectileShot() {
    Mix_PlayChannel(-1, SDL_SI::SdlSound::gProjectile, 0);
}
