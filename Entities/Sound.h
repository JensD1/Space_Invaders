//
// Created by Jens on 24/04/2020.
//

#ifndef SPACE_INVADERS_SOUND_H
#define SPACE_INVADERS_SOUND_H

namespace SI {
    class Sound {
    public:
        Sound();

        virtual ~Sound();

        Sound(const Sound&);

        Sound& operator=(const Sound&);

        virtual void pauseMusic() = 0;
        virtual void resumeMusic() = 0;
        virtual void playExplosion() = 0;
        virtual void playBulletShot() = 0;
        virtual void playBonus() = 0;
        virtual void playProjectileShot() = 0;
    };
}

#endif //SPACE_INVADERS_SOUND_H
