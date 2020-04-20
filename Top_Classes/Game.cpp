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

void SI::Game::run() //todo correct the inherritance aka remove the playerEntity etc and make new ones.
{
    //----------------------------------------------------Init--------------------------------------------------------\\

    // Window
    SI::Window* window = SI::Game::aFactory->createWindow();

    // events
    SI::Event* event = SI::Game::aFactory->createEvent();

    // timers
    SI::Timer* fpsTimer = SI::Game::aFactory->createTimer();
    SI::Timer* enemyTimer = SI::Game::aFactory->createTimer();
    SI::Timer* pbonusTimer = SI::Game::aFactory->createTimer();
    SI::Timer* nbonusTimer = SI::Game::aFactory->createTimer();

    // entities aanpaken
    SI::PlayerShip* player = SI::Game::aFactory->createPlayerShip(SI::PLAYER_START_POS_X,
            SI::PLAYER_START_POS_Y, SI::PLAYER_WIDTH, SI::PLAYER_HEIGHT, 0, 0);
    SI::Bullet* bullet = SI::Game::aFactory->createBullet(SI::OUT_OF_SCREEN,
            SI::OUT_OF_SCREEN, SI::BULLET_WIDTH, SI::BULLET_HEIGHT, 0, 0);
    std::vector<SI::EnemyShip*> enemies;
    for(int i = 0; i < SI::ENEMY_COLUMS; i++){
        for(int j = 0; j < SI::ENEMY_ROWS; j++){
            enemies.push_back(SI::Game::aFactory->createEnemyShip(SI::ENEMY_START_POS_X + (float)i * SI::ENEMY_SPACING,
                    SI::ENEMY_START_POS_Y + (float)j * SI::ENEMY_SPACING, SI::ENEMY_WIDTH, SI::ENEMY_HEIGHT, 0, 0));
        }
    }
    std::vector<SI::Projectile*> projectiles;
    projectiles.reserve(SI::MAXPROJECTILES);
    for(int i = 0; i < SI::MAXPROJECTILES; i++){
        projectiles.push_back(SI::Game::aFactory->createProjectile(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::PROJECTILE_WIDTH, SI::PROJECTILE_HEIGHT, 0, 0));
    }
    SI::PBonus* pbonus = SI::Game::aFactory->createPBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH, SI::BONUS_HEIGHT, 0, 0);
    SI::NBonus* nbonus = SI::Game::aFactory->createNBonus(SI::OUT_OF_SCREEN, SI::OUT_OF_SCREEN, SI::BONUS_WIDTH, SI::BONUS_HEIGHT, 0, 0);

    // variabelen.
    int projectilesFired = 0;
    char directionEnemies = 'R';
    bool quit = false;

//  \\----------------------------------------------------Init--------------------------------------------------------//

    //-------------------------------------------------Game_Loop------------------------------------------------------\\

    //todo Make multiple screens
    while(!quit)
    {
        //
        //-----------------------------------------------Check Updates--------------------------------------------------
        //
        std::set<Control> controls = event->handleEvent();
        player->setDx(0); // set the player speed standard to 0.
        if(controls.find(SI::LEFT) != controls.end()){
            player->setDx(-SI::PLAYERSPEED);
        }
        if(controls.find(SI::RIGHT) != controls.end()){
            player->setDx(SI::PLAYERSPEED);
        }
        if(controls.find(SI::RIGHT) != controls.end() && controls.find(SI::LEFT) != controls.end()){
            player->setDx(0); // Beiden zijn ingedrukt.
        }
        if(controls.find(SI::SPACE) != controls.end()){
            if(!bullet->getBulletShot() && !nbonus->getActive()){
                bullet->setDy(SI::BULLETSPEED);
                bullet->setYPos(player->getYPos() + SI::BULLET_DISTANCE_PLAYER);
                bullet->setXPos(player->getXPos() + SI::PLAYER_WIDTH / 2 - SI::BULLET_WIDTH / 2);
                bullet->setBulletShot(true);
            }
        }
        if(controls.find(SI::QUIT) != controls.end()){
            quit = true;
        }

        //
        //--------------------------------------------Update Positions--------------------------------------------------
        //

        // Player
        player->updatePosition();

        // Bullet
        if(bullet->getBulletShot()){
            bullet->updatePosition();
        }

        // Projectile
        for(Projectile* projectile: projectiles){
            if(projectile->getIsFired()){
                projectile->updatePosition();
                if(projectile->getYPos() > 1){
                    projectile->hasCollision();
                    projectilesFired--;
                }
            }
        }

        // Enemies
        for(SI::EnemyShip* enemy: enemies) {
            enemy->updatePosition();
        }
        // Enemies future movement
        for(SI::EnemyShip* enemy: enemies){ // de echte bewegingsverandering moet onderaan gebeuren zodat dit overal toegepast wordt.
            if(enemy->getDy() == 0){
                if(enemy->getXPos()<SI::ENEMY_OFFSET_BOARDERS_L || enemy->getXPos()>1-SI::ENEMY_OFFSET_BOARDERS_R) {
                    directionEnemies = 'D';
                }
            }
            if(enemy->getDy() != 0){
                if(enemy->getXPos()<SI::ENEMY_OFFSET_BOARDERS_L){
                    directionEnemies = 'R';
                }
                if(enemy->getXPos()>1- SI::ENEMY_OFFSET_BOARDERS_R){
                    directionEnemies = 'L';
                }
            }

        }
        for(SI::EnemyShip* enemy: enemies) {
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
        if(pbonus->getInField()){
            pbonus->updatePosition();
        }
        if(nbonus->getInField()){
            nbonus->updatePosition();
        }

        //
        //------------------------------------------------Spawning------------------------------------------------------
        //

        // projectiles spawning
        for(SI::EnemyShip* enemy: enemies){
            if(projectilesFired < SI::MAXPROJECTILES && enemyTimer->timePassed(SI::TIME_BETWEEN_SHOOTING_MS)){
                bool lowest = true;
                for(SI::EnemyShip* other : enemies){
                    if(std::abs(enemy->getXPos() - other->getXPos()) < SI::POSITIONAL_ERROR_MARGIN && (enemy->getYPos() < other->getYPos())){
                        lowest = false;
                    }
                }
                if(lowest){
                    if (enemy->fireProjectile()) {
                        int i = 0;
                        Projectile *tempProjectile;
                        do {    // zorgen dat je een projectile neemt dat nog niet is afgevuurd.
                            tempProjectile = projectiles[i];
                            i++;
                        } while (tempProjectile->getIsFired() && i < projectiles.size());
                        tempProjectile->setDy(SI::PROJECTILESPEED);
                        tempProjectile->setYPos(enemy->getYPos() + SI::PROJECTILE_DISTANCE_ENEMIE);
                        tempProjectile->setXPos(
                                enemy->getXPos() + SI::ENEMY_WIDTH / 2 - SI::PROJECTILE_WIDTH / 2);
                        tempProjectile->setIsFired(true);
                        enemyTimer->start();
                        projectilesFired++;
                    }
                }
            }
        }

        // Bonuses spawning
        if(!pbonus->getInField() && !pbonus->getActive()){ // They may not respawn while their effect is still working.
            pbonus->spawn();
        }
        if(!nbonus->getInField() && !nbonus->getActive()){
            nbonus->spawn();
        }


        //
        //-------------------------------------------colission detection------------------------------------------------
        //

        // Bullet with Enemy
        auto enemyIt = enemies.begin();
        if(bullet->getBulletShot()) {
            while (enemyIt != enemies.end()) {
                if ((*enemyIt)->detectCollision(bullet)) {
                    delete (*enemyIt);
                    enemyIt = enemies.erase(enemyIt);
                    if(!pbonus->getActive()) {
                        bullet->hasCollision();
                    }
                } else {
                    ++enemyIt;
                }
            }
        }

        // Player with Enemy
        enemyIt = enemies.begin();
        while(enemyIt != enemies.end()) {
            if ((*enemyIt)->detectCollision(player)) {
                quit = true;
            }
            ++enemyIt;
        }

        // Bullet with projectile
        if(bullet->getBulletShot()) {
            for (SI::Projectile *projectile: projectiles) { // when there's a player collision, this does not need to be compleded ==> go out of for loop.
                if (projectile->detectCollision(bullet)) {
                    projectile->hasCollision();
                    projectilesFired--;
                    if(!pbonus->getActive()) {
                        bullet->hasCollision();
                    }
                }
            }
        }

        // Player with projectile
        bool playerCollision = false;
        for(int i=0; i < projectiles.size() && !playerCollision; i++) { // when there's a player collision, this does not need to be compleded ==> go out of for loop.
           if (projectiles[i]->detectCollision(player)) {
                playerCollision = true;
            }
        }
        if(playerCollision) // This goes further on the previous
        {
            player->hasCollision();
            projectilesFired = 0;
            for(SI::Projectile* projectile: projectiles){
                projectile->hasCollision();
            }
            pbonus->resetPosition();
            nbonus->resetPosition();
        }

        //Player with PBonus
        if(pbonus->detectCollision(player)){
            pbonus->hasCollision();
            pbonusTimer->start();
        }
        //Player with NBonus
        if(nbonus->detectCollision(player)){
            nbonus->hasCollision();
            nbonusTimer->start();
        }

        //
        //-------------------------------------------------visualise----------------------------------------------------
        //

        // clear the window
        window->clear();

        // Player
        player->visualize(window);

        // Enemies
        for(SI::EnemyShip* enemy: enemies){
            enemy->visualize(window);
        }

        // Bullets
        if(bullet->getBulletShot()){
            bullet->visualize(window);
        }

        // Projectiles
        for(SI::Projectile* projectile: projectiles){
            if(projectile->getIsFired()){
                projectile->visualize(window);
            }
        }

        // PBonus
        if(pbonus->getInField()){
            pbonus->visualize(window);
        }

        // NBonus
        if(nbonus->getInField()){
            nbonus->visualize(window);
        }

        // Update window
        window->update();

        //
        // -----------------------------------------------Misc----------------------------------------------------------
        //
        if(player->getLives() < 0){
            quit = true;
        }

        //
        //--------------------------------------------timer_control-----------------------------------------------------
        //

        // timer for bonusses
        if(pbonus->getActive() && pbonusTimer->timePassed(SI::BONUS_WORKING_TIME_MS)){
            pbonus->setActive(false);
        }
        if(nbonus->getActive() && nbonusTimer->timePassed(SI::BONUS_WORKING_TIME_MS)){
            nbonus->setActive(false);
        }

        // timer for correct FPS (see GameConstants.h)
        while(!fpsTimer->timePassed(SI::fpsMs)){
            // wait till fpp time passed
        }
        fpsTimer->start();
    }
//  \\-------------------------------------------------Game_Loop------------------------------------------------------//

    //------------------------------------------------Free_Memory-----------------------------------------------------\\
    //free memory
    delete player;
    auto enemyIt = enemies.begin();
    while( enemyIt != enemies.end()){
        delete (*enemyIt);
        enemyIt = enemies.erase(enemyIt);
    }
    delete bullet;
    auto projectileIt = projectiles.begin();
    while( projectileIt != projectiles.end()){
        delete (*projectileIt);
        projectileIt = projectiles.erase(projectileIt);
    }
//  \\------------------------------------------------Free_Memory-----------------------------------------------------//

}