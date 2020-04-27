//
// Created by Jens on 2/03/2020.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Game.h"
#include <set>

//
// Variables------------------------------------------------------------------------------------------------------------
//
SI::Game* SI::Game::game = nullptr;

//
// Constructors---------------------------------------------------------------------------------------------------------
//
SI::Game::Game(SI::AFactory* aFactory)
{
    std::cout << "Game created." << std::endl;
    SI::Game::aFactory = aFactory;
}

SI::Game::~Game()
{
    std::cout << "Game destroyed." << std::endl;
}

SI::Game::Game(const SI::Game& other)
{
    // do nothing because this is not allowed to run
}

//
// Operators------------------------------------------------------------------------------------------------------------
//
SI::Game& SI::Game::operator=(const SI::Game& other)
{
    return *this;
}

//
// Methods--------------------------------------------------------------------------------------------------------------
//
SI::Game* SI::Game::createGameInstance(SI::AFactory* aFactory)
{
    if(SI::Game::game == nullptr)
        SI::Game::game  = new SI::Game(aFactory);
    return SI::Game::game;
}

void SI::Game::deleteGameInstance() {
    delete SI::Game::game;
    SI::Game::game = nullptr;
}


void SI::Game::run() //todo correct the inherritance aka remove the playerEntity etc and make new ones.
{
    //
    // ----------------------------------------------------Init---------------------------------------------------------
    //
    // Window
    SI::Window* window = SI::Game::aFactory->createWindow();
    SI::Sound* sound = SI::Game::aFactory->createSound();
    int currentScreen = SI::START_SCREEN;

    // events
    SI::Event* event = SI::Game::aFactory->createEvent();

    // boolean quit
    bool quit = false;
    bool won = false;
    int score = 0;

    //
    // ------------------------------------------------Game Loop--------------------------------------------------------
    //
    while(!quit) {
        //
        // ----------------------------------------Switch Game modes----------------------------------------------------
        //
        if (currentScreen == SI::START_SCREEN) {
            SI::Game::startScreen(&currentScreen, &quit, event, window);
        } else if (currentScreen == SI::GAME_SCREEN) {
            SI::Game::gameScreen(&currentScreen, &quit, event, window, sound, &score, &won); // This will be ran at least 1 time before startedGame will be set to true ==> we have everything initialised for sure.
        } else {
            SI::Game::endScreen(&currentScreen, &quit, event, window, score, won);
        }
    }
    delete event;
    delete sound;
    delete window;
}

void SI::Game::startScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window)
{
    while(!*quit && *currentScreen == SI::START_SCREEN) {
        //
        // -----------------------------------------Read User Input-----------------------------------------------------
        //
        std::set<Control> controls = event->handleEvent();
        if (controls.find(SI::SPACE) != controls.end()) {
            *currentScreen = SI::GAME_SCREEN;
        }
        if (controls.find(SI::QUIT) != controls.end()) {
            *quit = true;
        }

        //
        //-------------------------------------------------visualise----------------------------------------------------
        //
        window->clear();
        window->visualizeStartScreen();
        window->update();
    }
}

void SI::Game::endScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window, int score, bool won)
{
    event->handleEvent(); // clear the events from in game.
    while(!*quit && *currentScreen == SI::END_SCREEN) {
        //
        // -----------------------------------------Read User Input-----------------------------------------------------
        //
        std::set<Control> controls = event->handleEvent();
        if (controls.find(SI::SPACE) != controls.end()) {
            *currentScreen = SI::GAME_SCREEN;
        }
        if (controls.find(SI::QUIT) != controls.end()) {
            *quit = true;
        }

        //
        //-------------------------------------------------visualise----------------------------------------------------
        //
        window->clear();
        window->visualizeEndScreen(score, won);
        window->update();
    }
}

void SI::Game::gameScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window, SI::Sound* sound, int* score, bool* won) {
    //
    //----------------------------------------------Init------------------------------------------------------------
    //
    // fps timer
    SI::Timer* fpsTimer = SI::Game::aFactory->createTimer();
    fpsTimer->setRequestedTime(SI::fpsMs);
    // In game timers
    SI::Timer *enemyTimer = SI::Game::aFactory->createTimer();
    enemyTimer->setRequestedTime(SI::TIME_BETWEEN_SHOOTING_MS);
    SI::Timer *pbonusTimer = SI::Game::aFactory->createTimer();
    pbonusTimer->setRequestedTime(SI::BONUS_WORKING_TIME_MS);
    SI::Timer *nbonusTimer = SI::Game::aFactory->createTimer();
    nbonusTimer->setRequestedTime(SI::BONUS_WORKING_TIME_MS);

    // entities aanmaken
    SI::PlayerShip *player = SI::Game::aFactory->createPlayerShip(SI::PLAYER_START_POS_X,
                                                                  SI::PLAYER_START_POS_Y, SI::PLAYER_WIDTH,
                                                                  SI::PLAYER_HEIGHT, 0, 0);
    SI::Bullet *bullet = SI::Game::aFactory->createBullet(SI::OUT_OF_SCREEN,
                                                          SI::OUT_OF_SCREEN, SI::BULLET_WIDTH, SI::BULLET_HEIGHT, 0,
                                                          0);
    std::vector<SI::EnemyShip *> enemies;
    for (int i = 0; i < SI::ENEMY_COLUMS; i++) {
        for (int j = 0; j < SI::ENEMY_ROWS; j++) {
            enemies.push_back(
                    SI::Game::aFactory->createEnemyShip(SI::ENEMY_START_POS_X + (float) i * SI::ENEMY_SPACING,
                                                        SI::ENEMY_START_POS_Y + (float) j * SI::ENEMY_SPACING,
                                                        SI::ENEMY_WIDTH, SI::ENEMY_HEIGHT, 0, 0));
        }
    }
    std::vector<SI::Projectile *> projectiles;
    projectiles.reserve(SI::MAXPROJECTILES);
    for (int i = 0; i < SI::MAXPROJECTILES; i++) {
        projectiles.push_back(
                SI::Game::aFactory->createProjectile(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::PROJECTILE_WIDTH,
                                                     SI::PROJECTILE_HEIGHT, 0, 0));
    }
    SI::PBonus *pbonus = SI::Game::aFactory->createPBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH,
                                                          SI::BONUS_HEIGHT, 0, 0);
    SI::NBonus *nbonus = SI::Game::aFactory->createNBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH,
                                                          SI::BONUS_HEIGHT, 0, 0);

    // variabelen.
    int projectilesFired = 0;
    char directionEnemies = 'R';
    bool pause = false;
    *score = 0;

    //
    //-------------------------------------------------Game_Loop--------------------------------------------------------
    //
    //
    while(!*quit && *currentScreen == SI::GAME_SCREEN) {
        //
        //-----------------------------------------------Check Updates--------------------------------------------------
        //

        std::set<Control> controls = event->handleEvent();
        player->setDx(0); // set the player speed standard to 0.
        if (controls.find(SI::LEFT) != controls.end()) {
            player->setDx(-SI::PLAYERSPEED);
        }
        if (controls.find(SI::RIGHT) != controls.end()) {
            player->setDx(SI::PLAYERSPEED);
        }
        if (controls.find(SI::RIGHT) != controls.end() && controls.find(SI::LEFT) != controls.end()) {
            player->setDx(0); // Beiden zijn ingedrukt.
        }
        if (controls.find(SI::SPACE) != controls.end()) {
            if (!bullet->getInField() && !nbonus->getActive()) {
                bullet->setDy(SI::BULLETSPEED);
                bullet->setYPos(player->getYPos() + SI::BULLET_DISTANCE_PLAYER);
                bullet->setXPos(player->getXPos() + SI::PLAYER_WIDTH / 2 - SI::BULLET_WIDTH / 2);
                bullet->setInField(true);
                sound->playBulletShot();
            }
        }
        if (controls.find(SI::QUIT) != controls.end()) {
            *quit = true;
        }
        if (controls.find(SI::PAUSE) != controls.end()){
            if(pause){
                pause = false;
                sound->resumeMusic();
            }
            else {
                pause = true;
                sound->pauseMusic();
            }
        }


        //
        //--------------------------------------------Update Positions--------------------------------------------------
        //
        if(!pause) {
            // Player
            player->updatePosition();

            // Bullet
            if (bullet->getInField()) {
                bullet->updatePosition();
            }

            // Projectile
            for (Projectile *projectile: projectiles) {
                if (projectile->getInField()) {
                    projectile->updatePosition();
                    if (projectile->getYPos() > 1) {
                        projectile->hasCollision();
                        projectilesFired--;
                    }
                }
            }

            // Enemies
            for (SI::EnemyShip *enemy: enemies) {
                enemy->updatePosition();
            }
            // Enemies future movement
            for (SI::EnemyShip *enemy: enemies) { // de echte bewegingsverandering moet onderaan gebeuren zodat dit overal toegepast wordt.
                if (enemy->getDy() == 0) {
                    if (enemy->getXPos() < SI::ENEMY_OFFSET_BOARDERS_L ||
                        enemy->getXPos() > 1 - SI::ENEMY_OFFSET_BOARDERS_R) {
                        directionEnemies = 'D';
                    }
                }
                if (enemy->getDy() != 0) {
                    if (enemy->getXPos() < SI::ENEMY_OFFSET_BOARDERS_L) {
                        directionEnemies = 'R';
                    }
                    if (enemy->getXPos() > 1 - SI::ENEMY_OFFSET_BOARDERS_R) {
                        directionEnemies = 'L';
                    }
                }

            }
            for (SI::EnemyShip *enemy: enemies) {
                if (directionEnemies == 'R') {
                    enemy->setDy(0);
                    enemy->setDx(SI::ENEMYSPEED_H);
                } else if (directionEnemies == 'L') {
                    enemy->setDy(0);
                    enemy->setDx(-SI::ENEMYSPEED_H);
                } else {
                    enemy->setDy(SI::ENEMYSPEED_V);
                    enemy->setDx(0);
                }
            }

            // Bonuses movement
            if (pbonus->getInField()) {
                pbonus->updatePosition();
            }
            if (nbonus->getInField()) {
                nbonus->updatePosition();
            }

            //
            //------------------------------------------------Spawning------------------------------------------------------
            //

            // projectiles spawning
            for (SI::EnemyShip *enemy: enemies) {
                if (projectilesFired < SI::MAXPROJECTILES && enemyTimer->timePassed()) {
                    bool lowest = true;
                    for (SI::EnemyShip *other : enemies) {
                        if (std::abs(enemy->getXPos() - other->getXPos()) < SI::POSITIONAL_ERROR_MARGIN &&
                            (enemy->getYPos() < other->getYPos())) {
                            lowest = false;
                        }
                    }
                    if (lowest) {
                        if (enemy->fireProjectile()) {
                            int i = 0;
                            Projectile *tempProjectile;
                            do {    // zorgen dat je een projectile neemt dat nog niet is afgevuurd.
                                tempProjectile = projectiles[i];
                                i++;
                            } while (tempProjectile->getInField() && i < projectiles.size());
                            tempProjectile->setDy(SI::PROJECTILESPEED);
                            tempProjectile->setYPos(enemy->getYPos() + SI::PROJECTILE_DISTANCE_ENEMIE);
                            tempProjectile->setXPos(
                                    enemy->getXPos() + SI::ENEMY_WIDTH / 2 - SI::PROJECTILE_WIDTH / 2);
                            tempProjectile->setInField(true);
                            enemyTimer->start();
                            sound->playProjectileShot();
                            projectilesFired++;
                        }
                    }
                }
            }

            // Bonuses spawning
            if (!pbonus->getInField() &&
                !pbonus->getActive()) { // They may not respawn while their effect is still working.
                pbonus->spawn();
            }
            if (!nbonus->getInField() && !nbonus->getActive()) {
                nbonus->spawn();
            }


            //
            //-------------------------------------------colission detection------------------------------------------------
            //

            // Bullet with Enemy
            auto enemyIt = enemies.begin();
            if (bullet->getInField()) {
                while (enemyIt != enemies.end()) {
                    if ((*enemyIt)->detectCollision(bullet)) {
                        delete (*enemyIt);
                        enemyIt = enemies.erase(enemyIt);
                        *score += SI::SCORE_HIT_ENEMY;
                        sound->playExplosion();
                        if (!pbonus->getActive()) {
                            bullet->hasCollision();
                        }
                    } else {
                        ++enemyIt;
                    }
                }
            }

            // Player with Enemy
            enemyIt = enemies.begin();
            while (enemyIt != enemies.end()) {
                if ((*enemyIt)->detectCollision(player)) {
                    *score += SI::SCORE_END_GAME;
                    *currentScreen = SI::END_SCREEN;
                    *won = false;
                    sound->playExplosion();
                }
                ++enemyIt;
            }

            // Bullet with projectile // todo kijk na waarom het niet andersom werkt
            for (SI::Projectile *projectile: projectiles) { // when there's a player collision, this does not need to be compleded ==> go out of for loop.
                if (bullet->getInField()) {
                    if (projectile->detectCollision(bullet)) {
                        projectile->hasCollision();
                        projectilesFired--;
                        *score += SI::SCORE_HIT_PROJECTILE;
                        if (!pbonus->getActive()) {
                            bullet->hasCollision();
                        }
                    }
                }
            }

            // Player with projectile
            bool playerCollision = false;
            for (int i = 0; i < projectiles.size() &&
                            !playerCollision; i++) { // when there's a player collision, this does not need to be compleded ==> go out of for loop.
                if (projectiles[i]->detectCollision(player)) {
                    playerCollision = true;
                    *score += SI::SCORE_HIT_PLAYER;
                }
            }
            if (playerCollision) // This goes further on the previous
            {
                sound->playExplosion();
                player->hasCollision();
                projectilesFired = 0;
                for (SI::Projectile *projectile: projectiles) {
                    projectile->hasCollision();
                }
                pbonus->resetPosition();
                nbonus->resetPosition();
            }

            //Player with PBonus
            if (pbonus->detectCollision(player)) {
                pbonus->hasCollision();
                pbonusTimer->start();
                sound->playBonus();
            }
            //Player with NBonus
            if (nbonus->detectCollision(player)) {
                nbonus->hasCollision();
                nbonusTimer->start();
                sound->playBonus();
            }

            //
            // -----------------------------------------END GAME--------------------------------------------------------
            //
            if (player->getLives() <= 0) {
                *currentScreen = SI::END_SCREEN;
                *won = false;
            }
            if (enemies.empty()) {
                *currentScreen = SI::END_SCREEN;
                *won = true;
            }
        }
        //
        //-------------------------------------------------visualise----------------------------------------------------
        //

        // clear the window
        window->clear();

        // score
        window->visualizeScore(*score);

        // Player
        player->visualize(window);

        // Enemies
        for (SI::EnemyShip *enemy: enemies) {
            enemy->visualize(window);
        }

        // Bullets
        if (bullet->getInField()) {
            bullet->visualize(window);
        }

        // Projectiles
        for (SI::Projectile *projectile: projectiles) {
            if (projectile->getInField()) {
                projectile->visualize(window);
            }
        }

        // PBonus
        if (pbonus->getInField()) {
            pbonus->visualize(window);
        }

        // NBonus
        if (nbonus->getInField()) {
            nbonus->visualize(window);
        }

        // pause
        if (pause){
            window->drawText(SI::PAUSE_X_POS, SI::PAUSE_Y_POS, "PAUSE");
        }

        // Update window
        window->update();

        //-----------------------------------------BONUS TIMER------------------------------------------------------
        //
        //
        if(pause){
            pbonusTimer->paused();
            nbonusTimer->paused();
            enemyTimer->paused();
        }
        if (pbonus->getActive() && pbonusTimer->timePassed()) {
            pbonus->setActive(false);
        }
        if (nbonus->getActive() && nbonusTimer->timePassed()) {
            nbonus->setActive(false);
        }
        //
        //---------------------------------------------FPS TIMER--------------------------------------------------------
        //
        // timer for correct FPS (see GameConstants.h)
        while (!fpsTimer->timePassed()) {
            // wait till fpp time passed
        }
        fpsTimer->start();

    }

    //
    //------------------------------------------------Free_Memory-----------------------------------------------------\\
    //
    delete player;
    auto enemyIt = enemies.begin();
    while (enemyIt != enemies.end()) {
        delete (*enemyIt);
        enemyIt = enemies.erase(enemyIt);
    }
    delete bullet;
    auto projectileIt = projectiles.begin();
    while (projectileIt != projectiles.end()) {
        delete (*projectileIt);
        projectileIt = projectiles.erase(projectileIt);
    }
}







