cmake_minimum_required(VERSION 3.15)
project(Space_Invaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

SET(SRC
        Main_Classes/Game.cpp
        Main_Classes/Game.h
        Abstract/AFactory.h
        SDL/SdlFactory.cpp
        SDL/SdlFactory.h
        Abstract/Entities/PlayerShip.cpp
        Abstract/Entities/PlayerShip.h
        Abstract/Entities/EnemyShip.cpp
        Abstract/Entities/EnemyShip.h
        Abstract/Entities/Entity.cpp
        Abstract/Entities/Entity.h
        Abstract/Entities/BonusEntity.cpp
        Abstract/Entities/BonusEntity.h
        SDL/SDL_Entities/SdlPlayerShip.cpp
        SDL/SDL_Entities/SdlPlayerShip.h
        SDL/SDL_Entities/SdlBullet.cpp
        SDL/SDL_Entities/SdlBullet.h
        SDL/SDL_Entities/SdlEnemyShip.cpp
        SDL/SDL_Entities/SdlEnemyShip.h
        SDL/SDL_Entities/SdlProjectile.cpp
        SDL/SDL_Entities/SdlProjectile.h
        SDL/SDL_Entities/SdlPBonus.cpp
        SDL/SDL_Entities/SdlPBonus.h
        SDL/SDL_Entities/SdlNBonus.cpp
        SDL/SDL_Entities/SdlNBonus.h
        Abstract/Event.cpp
        Abstract/Event.h
        Constants/GameConstants.h
        SDL/SdlEvent.cpp
        SDL/SdlEvent.h
        SDL/Window/SdlWindow.cpp
        SDL/Window/SdlWindow.h
        SDL/Window/LTexture.cpp
        SDL/Window/LTexture.h
        Constants/SdlConstants.h
        SDL/SdlTimer.cpp
        SDL/SdlTimer.h
        Abstract/Timer.cpp
        Abstract/Timer.h
        Abstract/Window.cpp
        Abstract/Window.h Abstract/Sound.cpp Abstract/Sound.h SDL/SdlSound.cpp SDL/SdlSound.h Abstract/Entities/ReusableEntity.cpp Abstract/Entities/ReusableEntity.h)
add_executable(Space_Invaders ${SRC} Main_Classes/main.cpp)
target_link_libraries(Space_Invaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)