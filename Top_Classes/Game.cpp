//
// Created by Jens on 2/03/2020.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Game.h"
#include <set>
#include <fstream>

//
// ----------------------------------------------------Variables--------------------------------------------------------
//
// This must be set outside the class definition since it is a static variable.
SI::Game* SI::Game::game = nullptr;

//
// ---------------------------------------------------Constructors------------------------------------------------------
//
SI::Game::Game(SI::AFactory* aFactory) {
    std::cout << "Game created." << std::endl;
    SI::Game::aFactory = aFactory;
}

SI::Game::~Game() {
    delete SI::Game::aFactory;
    std::cout << "Game destroyed." << std::endl;
}

SI::Game::Game(const SI::Game& other) {
    // do nothing because this is not allowed to run
}

//
// -----------------------------------------------------Operators-------------------------------------------------------
//
SI::Game& SI::Game::operator=(const SI::Game& other) {
    return *this;
}

//
// ------------------------------------------------------Methods--------------------------------------------------------
//
/**
 * Create a singleton Game object.
 * @param aFactory is an abstract factory pointer. This must actually contain a non abstract type of factory.
 * @return a singleton game object instance.
 */
SI::Game* SI::Game::createGameInstance(SI::AFactory* aFactory) {
    if (SI::Game::game == nullptr)
        SI::Game::game = new SI::Game(aFactory);
    return SI::Game::game;
}

/**
 * delete the signleton Game instance.
 */
void SI::Game::deleteGameInstance() {
    delete SI::Game::game;
    SI::Game::game = nullptr;
}

/**
 * This is a loop that will switch game screens in the order: start screen -> game screen -> end screen -> start screen -> ...
 */
void SI::Game::run() {
    //
    // ----------------------------------------------------Init---------------------------------------------------------
    //
    //Open the score file
    int highScore = 0;
    std::fstream scoreFile;
    scoreFile.open("./Score.txt", std::fstream::in | std::fstream::out);
    if(!scoreFile){ // file doesn't exist yet
        std::cout << "Creating HighScore file..." << std::endl;
        // create a new empty file of length 0 (discard all content if there is content).
        scoreFile.open("./Score.txt", std::fstream::in | std::fstream::out| std::fstream::trunc);
        scoreFile << 0;
        scoreFile.close();
    }
    else{
        std::cout<<"Reading HighScore in..." << std::endl;
        std::string line;
        std::getline(scoreFile, line);
        highScore = std::stoi(line); // string to int.
        printf("High Score is: %d\n", highScore);
        scoreFile.close();
    }

    // Window
    SI::Window* window = SI::Game::aFactory->createWindow();
    int currentScreen = SI::START_SCREEN;

    // Sound
    SI::Sound* sound = SI::Game::aFactory->createSound();

    // events
    SI::Event* event = SI::Game::aFactory->createEvent();

    // boolean quit
    bool quit = false;
    bool won = false;
    int score = 0;

    //
    // ------------------------------------------------Game Loop--------------------------------------------------------
    //
    while (!quit) {
        //
        // ----------------------------------------Switch Game modes----------------------------------------------------
        //
        if (currentScreen == SI::START_SCREEN) {
            SI::Game::startScreen(&currentScreen, &quit, event, window, highScore);
        } else if (currentScreen == SI::GAME_SCREEN) {
            SI::Game::gameScreen(&currentScreen, &quit, event, window, sound, &score,
                                 &won, &highScore); // This will be ran at least 1 time before startedGame will be set to true ==> we have everything initialised for sure.
        } else {
            SI::Game::endScreen(&currentScreen, &quit, event, window, score, won, highScore);
        }
    }

    std::cout << "writing high score to file..." << std::endl;
    scoreFile.open("./Score.txt", std::fstream::out);
    if(scoreFile.is_open()) {
        std::cout << "High score file updated." << std::endl;
        scoreFile << highScore;
        std::cout << highScore << std::endl;
    }
    else{
        std::cout << "Unable to update the file." << std::endl;
    }
    scoreFile.close();

    delete event;
    delete sound;
    delete window;
}

/**
 * This method will visualise tha startScreen and will wait till the correct button is pressed to continue to the next screen.
 * @param currentScreen A pointer to the variable that denotes which screen is the current screen (int).
 * @param quit A pointer to a variable that denotes if the player want to quit the game (bool).
 * @param event A pointer to an object that can read the players events (SI::Event).
 * @param window The window where the renderer will render the start screen on (SI::Window).
 */
void SI::Game::startScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window, int highScore) {
    while (!*quit && *currentScreen == SI::START_SCREEN) {
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
        window->visualizeStartScreen(highScore);
        window->update();
    }
}

/**
 * This method will visualise tha endScreen and will wait till the correct button is pressed to continue to the next screen.
 * @param currentScreen A pointer to the variable that denotes which screen is the current screen (int).
 * @param quit A pointer to a variable that denotes if the player want to quit the game (bool).
 * @param event A pointer to an object that can read the players events (SI::Event).
 * @param window The window where the renderer will render the start screen on (SI::Window).
 * @param score An variable that contains the player's score (int).
 * @param won A variable that denotes if the player has won the game (bool). When this variable is True the player has won.
 */
void SI::Game::endScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window, int score, bool won, int highScore) {
    event->handleEvent(); // clear the events from in game.
    while (!*quit && *currentScreen == SI::END_SCREEN) {
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
        window->visualizeEndScreen(score, won, highScore);
        window->update();
    }
}

/**
 * In this method all game objects and timers will be initialized. Than the main game loop will be run and the player
 * will be able to move and shoot to enemies and projectiles. These enemies shoot their projectiles back and will move
 * left and right and slowly downward. Collision detection will be handled and the correct sound fragment will be
 * played with every collision. There are also bonusses that the player can collect. The positive bonus will make it
 * able to shoot trough an entire line of enemies, the negative bonus blocks the gun of the player, so it can't shoot
 * for an amount of time.
 * @param currentScreen A pointer to the variable that denotes which screen is the current screen (int).
 * @param quit A pointer to a variable that denotes if the player want to quit the game (bool).
 * @param event A pointer to an object that can read the players events (SI::Event).
 * @param window The window where the renderer will render the start screen on (SI::Window).
 * @param sound A pointer to an object that can play the in game sounds (SI::Sound).
 * @param score An variable that contains the player's score (int).
 * @param won A variable that denotes if the player has won the game (bool). When this variable is True the player has won.
 */
void
SI::Game::gameScreen(int* currentScreen, bool* quit, SI::Event* event, SI::Window* window, SI::Sound* sound, int* score,
                     bool* won, int* highScore) {
    //
    //----------------------------------------------Init------------------------------------------------------------
    //
    // fps timer
    SI::Timer* fpsTimer = SI::Game::aFactory->createTimer();
    fpsTimer->setRequestedTime(SI::fpsMs);
    // In game timers
    SI::Timer* enemyTimer = SI::Game::aFactory->createTimer();
    enemyTimer->setRequestedTime(SI::TIME_BETWEEN_SHOOTING_MS);
    SI::Timer* pbonusTimer = SI::Game::aFactory->createTimer();
    pbonusTimer->setRequestedTime(SI::BONUS_WORKING_TIME_MS);
    SI::Timer* nbonusTimer = SI::Game::aFactory->createTimer();
    nbonusTimer->setRequestedTime(SI::BONUS_WORKING_TIME_MS);
    SI::Timer* debounceTimer = SI::Game::aFactory->createTimer();
    debounceTimer->setRequestedTime(
            SI::DEBOUNCE_TIME_MS); // This timer makes sure that a button is not pressed multiple times.

    // make sure that nothing of the user's input from before the game starting is taken into account.
    debounceTimer->start();

    // entities aanmaken
    SI::PlayerShip* player = SI::Game::aFactory->createPlayerShip(SI::PLAYER_START_POS_X,
                                                                  SI::PLAYER_START_POS_Y, SI::PLAYER_WIDTH,
                                                                  SI::PLAYER_HEIGHT, 0, 0);
    SI::ReusableEntity* bullet = SI::Game::aFactory->createBullet(SI::OUT_OF_SCREEN,
                                                                  SI::OUT_OF_SCREEN, SI::BULLET_WIDTH,
                                                                  SI::BULLET_HEIGHT, 0,
                                                                  0);
    std::vector<SI::EnemyShip*> enemies;
    for (int i = 0; i < SI::ENEMY_COLUMS; i++) {
        for (int j = 0; j < SI::ENEMY_ROWS; j++) {
            enemies.push_back(
                    SI::Game::aFactory->createEnemyShip(SI::ENEMY_START_POS_X + (float) i * SI::ENEMY_SPACING,
                                                        SI::ENEMY_START_POS_Y + (float) j * SI::ENEMY_SPACING,
                                                        SI::ENEMY_WIDTH, SI::ENEMY_HEIGHT, 0, 0));
        }
    }
    std::vector<SI::ReusableEntity*> projectiles;
    projectiles.reserve(SI::MAXPROJECTILES);
    for (int i = 0; i < SI::MAXPROJECTILES; i++) {
        projectiles.push_back(
                SI::Game::aFactory->createProjectile(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::PROJECTILE_WIDTH,
                                                     SI::PROJECTILE_HEIGHT, 0, 0));
    }
    SI::BonusEntity* pbonus = SI::Game::aFactory->createPBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH,
                                                               SI::BONUS_HEIGHT, 0, 0);
    SI::BonusEntity* nbonus = SI::Game::aFactory->createNBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH,
                                                               SI::BONUS_HEIGHT, 0, 0);


    // variabelen.
    int projectilesFired = 0;
    char directionEnemies = 'R';
    float enemyExtraSpeed = 0;
    bool pause = false;
    *score = 0;

    //
    //-------------------------------------------------Game Loop--------------------------------------------------------
    //
    //
    while (!*quit && *currentScreen == SI::GAME_SCREEN) {
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
        if (controls.find(SI::RIGHT) != controls.end() &&
            controls.find(SI::LEFT) != controls.end()) { // left and right are both pressed.
            player->setDx(0);
        }
        if (controls.find(SI::SPACE) != controls.end()) {
            // shoot only if the bullet is not in the field anymore, you are not under effect of the negative bonus anymore
            // and the debounce Timer had passed.
            if (!bullet->getInField() && !nbonus->getActive() && debounceTimer->timePassed()) {
                bullet->setDy(SI::BULLETSPEED);
                bullet->setYPos(player->getYPos() + SI::BULLET_DISTANCE_PLAYER);
                bullet->setXPos(player->getXPos() + SI::PLAYER_WIDTH / 2 - SI::BULLET_WIDTH / 2);
                bullet->setInField(true);
                sound->playBulletShot();
                debounceTimer->start();
            }
        }
        if (controls.find(SI::QUIT) != controls.end()) {
            *quit = true;
        }
        if (controls.find(SI::PAUSE) != controls.end()) {
            // This debounce timer will make sure that pause this command below is not executed multiple times by
            // pressing pause once.
            if (debounceTimer->timePassed()) {
                if (pause) {
                    pause = false;
                    sound->resumeMusic();
                } else {
                    pause = true;
                    sound->pauseMusic();
                }
                debounceTimer->start();
            }
        }

        //
        //--------------------------------------------Update Positions--------------------------------------------------
        //
        if (!pause) {
            // Player
            player->updatePosition();
            // put the player back in screen when it got out of it.
            if (player->getXPos() < 0) {
                player->setXPos(0);
            } else if (player->getXPos() > 1 - SI::PLAYER_WIDTH) {
                player->setXPos(1 - SI::PLAYER_WIDTH);
            }

            // Bullet
            if (bullet->getInField()) {
                bullet->updatePosition();
                if (bullet->getYPos() < 0) {
                    // bullet is out of screen, so we can reset the bullet's position and shoot again.
                    bullet->resetPosition();
                }
            }

            // Projectile
            for (ReusableEntity* projectile: projectiles) {
                if (projectile->getInField()) {
                    projectile->updatePosition();
                    if (projectile->getYPos() > 1) {
                        // projectile is out of screen, so we can reset the projectiles's position and the enemies
                        // can fire this projectile again.
                        projectile->resetPosition();
                        projectilesFired--;
                    }
                }
            }

            // Enemies
            for (SI::EnemyShip* enemy: enemies) {
                enemy->updatePosition();
            }
            // Enemies future movement check
            for (SI::EnemyShip* enemy: enemies) {
                // the real change of movement must be made at the bottom so that it is applied everywhere.
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
            // setting the speed for future movement.
            for (SI::EnemyShip* enemy: enemies) {
                if (directionEnemies == 'R') {
                    enemy->setDy(0);
                    enemy->setDx(SI::ENEMYSPEED_H + enemyExtraSpeed);
                } else if (directionEnemies == 'L') {
                    enemy->setDy(0);
                    enemy->setDx(-SI::ENEMYSPEED_H - enemyExtraSpeed);
                } else {
                    enemy->setDy(SI::ENEMYSPEED_V);
                    enemy->setDx(0);
                }
            }

            // Bonuses movement
            if (pbonus->getInField()) {
                pbonus->updatePosition();
                if (pbonus->getYPos() > 1) {
                    pbonus->resetPosition();
                }
            }
            if (nbonus->getInField()) {
                nbonus->updatePosition();
                if (nbonus->getYPos() > 1) {
                    nbonus->resetPosition();
                }
            }

            //
            //----------------------------------------------Spawning----------------------------------------------------
            //

            // projectiles spawning
            for (SI::EnemyShip* enemy: enemies) {
                // if there are projectiles left and the time that the enemy cannot shoot after the last shot is passed
                // this for loop will see if there's an enemy that will shoot.
                if (projectilesFired < SI::MAXPROJECTILES && enemyTimer->timePassed()) {
                    // Check if this enemy of the for loop above is at the lowest location of its column.
                    bool lowest = true;
                    for (SI::EnemyShip* other : enemies) {
                        // If the enemies are of the same column and the other enemy has a lower position, the statement
                        // above is not fullfilled so the enemie is not the lowest.
                        if (std::abs(enemy->getXPos() - other->getXPos()) < SI::POSITIONAL_ERROR_MARGIN &&
                            (enemy->getYPos() < other->getYPos())) {
                            lowest = false;
                        }
                    }
                    // if the enemy is the lowest of it's column, we check if it is going to shoot.
                    if (lowest) {
                        if (enemy->fireProjectile()) {
                            int i = 0;
                            ReusableEntity* tempProjectile;
                            do {    // Make sure you take a projectile that hasn't been fired yet.
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
            //-------------------------------------------colission detection--------------------------------------------
            //

            // Bullet with Enemy
            auto enemyIt = enemies.begin();
            if (bullet->getInField()) {
                while (enemyIt != enemies.end()) {
                    if ((*enemyIt)->detectCollision(bullet)) {
                        delete (*enemyIt); // delete the content of enemyIt, which is the enemy.
                        enemyIt = enemies.erase(enemyIt);
                        *score += SI::SCORE_HIT_ENEMY;
                        sound->playExplosion();
                        enemyExtraSpeed += SI::ENEMY_SPEED_UPDATE; // The speed of the other ones will increase.
                        if (!pbonus->getActive()) {
                            bullet->resetPosition();
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

            // Bullet with projectile
            for (SI::ReusableEntity* projectile: projectiles) {
                if (bullet->getInField()) {
                    if (projectile->detectCollision(bullet)) {
                        projectile->resetPosition();
                        projectilesFired--;
                        *score += SI::SCORE_HIT_PROJECTILE;
                        if (!pbonus->getActive()) {
                            bullet->resetPosition();
                        }
                    }
                }
            }

            // Player with projectile
            bool playerCollision = false;
            for (int i = 0; i < projectiles.size() &&
                            !playerCollision; i++) { // when there's a player collision, this does not need to be completed ==> go out of for loop.
                if (projectiles[i]->detectCollision(
                        player)) { // Set the playercollision to true for the next if statement.
                    playerCollision = true;
                    *score += SI::SCORE_HIT_PLAYER;
                }
            }
            if (playerCollision) // This goes further on the previous
            {
                // reset all projectiles and bonusses, play explosion sounds and lower the number of lives with 1.
                sound->playExplosion();
                player->setLives(player->getLives() - 1);
                player->setYPos(SI::PLAYER_START_POS_Y);
                player->setXPos(SI::PLAYER_START_POS_X);
                projectilesFired = 0;
                for (SI::ReusableEntity* projectile: projectiles) {
                    projectile->resetPosition();
                }
                pbonus->resetPosition();
                nbonus->resetPosition();
            }

            //Player with PBonus
            if (pbonus->detectCollision(player)) {
                pbonus->resetPosition();
                pbonus->setActive(true);
                // start the bonus duration timer
                pbonusTimer->start();
                sound->playBonus();
            }
            //Player with NBonus
            if (nbonus->detectCollision(player)) {
                nbonus->resetPosition();
                nbonus->setActive(true);
                // start the bonus duration timer
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
        window->visualizeScore(*score, *highScore);

        // Player
        player->visualize(window);

        // Enemies
        for (SI::EnemyShip* enemy: enemies) {
            enemy->visualize(window);
        }

        // Bullets
        if (bullet->getInField()) {
            bullet->visualize(window);
        }

        // Projectiles
        for (SI::ReusableEntity* projectile: projectiles) {
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
        if (pause) {
            window->drawText(SI::PAUSE_X_POS, SI::PAUSE_Y_POS, "PAUSE");
        }

        // Update window
        window->update();

        //
        //-------------------------------------------BONUS TIMER--------------------------------------------------------
        //
        if (pause) {
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

    // Check if high score is beat.
    if((*score > * highScore) && !*quit){  // unfinished games are not saved.
        *highScore = *score;
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
    delete pbonus;
    delete nbonus;
    delete debounceTimer;
    delete enemyTimer;
    delete fpsTimer;
    delete nbonusTimer;
    delete pbonusTimer;
}







