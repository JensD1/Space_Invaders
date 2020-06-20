#include <iostream>
#include "AFactory.h"
#include "SdlFactory.h"
#include "Game.h"

/**
 * The main method. Here we will create an abstract factory that will actually contain an SDL factory.
 */
int main(int argc, char* args[]) {
    std::cout << "Begin" << std::endl;
    SI::AFactory* aFactory = new SDL_SI::SdlFactory();
    SI::Game* game = SI::Game::createGameInstance(aFactory);
    game->run();
    SI::Game::deleteGameInstance(); // game will delete afactory in it's destructor.
    return 0;
}
