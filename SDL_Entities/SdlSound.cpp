//
// Created by Jens on 24/04/2020.
//

#include "SdlSound.h"
#include <iostream>
#include <assert.h>


SDL_SI::SdlSound::SdlSound()
{
    assert(SDL_SI::SdlSound::init());
    assert(loadMedia());
    //Play the music
    Mix_PlayMusic( gMusic, -1 );
}

SDL_SI::SdlSound::~SdlSound()
{
    SDL_SI::SdlSound::close();
}

SDL_SI::SdlSound::SdlSound(const SDL_SI::SdlSound& other)
{
    gMusic = other.gMusic;
    gExplosion = other.gExplosion;
    gBullet = other.gBullet;
    gBonus = other.gBonus;
    gProjectile = other.gProjectile;
}

SDL_SI::SdlSound& SDL_SI::SdlSound::operator=(const SDL_SI::SdlSound& other) {
    if (this != &other){
        gMusic = other.gMusic;
        gExplosion = other.gExplosion;
        gBullet = other.gBullet;
        gBonus = other.gBonus;
        gProjectile = other.gProjectile;
    }
    return *this;
}

void SDL_SI::SdlSound::close() // todo zet overal SDL_SI!!!!!!!!!
{
    //Free the sound effects
    Mix_FreeChunk( gExplosion );
    Mix_FreeChunk( gBonus );
    Mix_FreeChunk( gBullet );
    Mix_FreeChunk( gProjectile );

    gExplosion = nullptr;
    gBonus = nullptr;
    gBullet = nullptr;
    gProjectile = nullptr;

    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = nullptr;

    //Quit SDL subsystems
    Mix_Quit(); // we will quit SDL in SdlWindow
}

bool SDL_SI::SdlSound::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
    }

    return success;
}

bool SDL_SI::SdlSound::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load music
    gMusic = Mix_LoadMUS( "../Media/Electronic-Fantasy.wav" );
    if( gMusic == nullptr )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    //Load sound effects
    gExplosion = Mix_LoadWAV( "../Media/Explosion.wav" );
    if( gExplosion == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    //Load sound effects
    gBullet = Mix_LoadWAV( "../Media/BulletShot.wav" );
    if( gExplosion == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    //Load sound effects
    gBonus = Mix_LoadWAV( "../Media/bonus.wav" );
    if( gExplosion == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    //Load sound effects
    gProjectile = Mix_LoadWAV( "../Media/projectileShot.wav" );
    if( gExplosion == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}

void SDL_SI::SdlSound::pauseMusic()
{
    // Pause the music
    Mix_PauseMusic();
}

void SDL_SI::SdlSound::resumeMusic()
{
    // Resume the music
    Mix_ResumeMusic();
}

void SDL_SI::SdlSound::playExplosion()
{
    Mix_PlayChannel( -1, gExplosion, 0 );
}

void SDL_SI::SdlSound::playBulletShot()
{
    Mix_PlayChannel( -1, gBullet, 0 );
}

void SDL_SI::SdlSound::playBonus()
{
    Mix_PlayChannel( -1, gBonus, 0 );
}

void SDL_SI::SdlSound::playProjectileShot()
{
    Mix_PlayChannel( -1, gProjectile, 0 );
}
