//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_GAME_H
#define SPACE_INVADORS_GAME_H

#include "../Abstract/AFactory.h"
#include "../Constants/GameConstants.h"

namespace SI {
    class Game {
    private:
        // Variables
        static SI::Game* game;  // alle objecten delen deze variabele ==> vanaf 1 object wordt gemaakt wordt het al gemaakte
        // object in de deze klassevariabele gezet (= in +-zichzelf), waardoor dat de volgende keer als
        // createGameInstance aangeroepen wordt, deze al ziet dat de klasse variabele niet 0 is.
        SI::AFactory* aFactory;

        // Constructors
        Game(SI::AFactory*);

        Game(const SI::Game&);

        ~Game();

        // Operators
        SI::Game& operator=(const SI::Game&);

    public:
        // Methods
        // Deze createGameInstance method moet static zijn zodat deze methode een klasse methode wordt ==> deze methode kan
        // aangeroepen worden zonder dat er een instantie (object) bestaat van Game.
        static SI::Game* createGameInstance(SI::AFactory*);

        static void deleteGameInstance();

        void run();

        void startScreen(int*, bool*, SI::Event*, SI::Window*, int);

        void endScreen(int*, bool*, SI::Event*, SI::Window*, int, bool, int);

        void gameScreen(int*, bool*, SI::Event*, SI::Window*, SI::Sound*, int*, bool*, int*);
    };
}

#endif //SPACE_INVADORS_GAME_H
