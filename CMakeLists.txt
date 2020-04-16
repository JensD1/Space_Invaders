cmake_minimum_required(VERSION 3.15)
project(Space_Invaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

SET(SRC
        Top_Classes/Game.cpp
        Top_Classes/Game.h
        Top_Classes/AFactory.h
        Top_Classes/SdlFactory.cpp
        Top_Classes/SdlFactory.h
        Entities/PlayerShip.cpp
        Entities/PlayerShip.h
        Entities/Bullet.cpp
        Entities/Bullet.h
        Entities/EnemyShip.cpp
        Entities/EnemyShip.h
        Entities/Projectile.cpp
        Entities/Projectile.h
        Entities/PBonus.cpp
        Entities/PBonus.h
        Entities/NBonus.cpp
        Entities/NBonus.h
        Entities/Entity.cpp
        Entities/Entity.h
        Entities/PlayerEntity.cpp
        Entities/PlayerEntity.h
        Entities/EnemyEntity.cpp
        Entities/EnemyEntity.h
        Entities/BonusEntity.cpp
        Entities/BonusEntity.h
        SDL_Entities/SdlPlayerShip.cpp
        SDL_Entities/SdlPlayerShip.h
        SDL_Entities/SdlBullet.cpp
        SDL_Entities/SdlBullet.h
        SDL_Entities/SdlEnemyShip.cpp
        SDL_Entities/SdlEnemyShip.h
        SDL_Entities/SdlProjectile.cpp
        SDL_Entities/SdlProjectile.h
        SDL_Entities/SdlPBonus.cpp
        SDL_Entities/SdlPBonus.h
        SDL_Entities/SdlNBonus.cpp
        SDL_Entities/SdlNBonus.h
        Entities/Event.cpp
        Entities/Event.h
        GameConstants.h
        SDL_Entities/SdlEvent.cpp
        SDL_Entities/SdlEvent.h
        SDL_Entities/SdlWindow.cpp
        SDL_Entities/SdlWindow.h
        SDL_Entities/LTexture.cpp
        SDL_Entities/LTexture.h
        SdlConstants.h SDL_Entities/SdlTimer.cpp SDL_Entities/SdlTimer.h Entities/Timer.cpp Entities/Timer.h Entities/Window.cpp Entities/Window.h)
add_executable(Space_Invaders ${SRC} Top_Classes/main.cpp)
target_link_libraries(Space_Invaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)