#include <iostream>
#include "AFactory.h"
#include "SdlFactory.h"
#include "Game.h"

int main(int argc, char* args[]) {
    std::cout << "Begin" << std::endl;
    SI::AFactory* aFactory = new SDL_SI::SdlFactory();
    SI::Game* game = SI::Game::createGameInstance(aFactory);
    game->run();
    delete game; // game zal afactory ook deleten in destructor.
    delete aFactory;
    return 0;
}
