//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_GAME_H
#define SPACE_INVADORS_GAME_H

#include "AFactory.h"
#include "../GameConstants.h"

namespace SI {
    class Game {
    private:
        // Variables
        static Game* game;  // alle objecten delen deze variabele ==> vanaf 1 object wordt gemaakt wordt het al gemaakte
        // object in de deze klassevariabele gezet (= in +-zichzelf), waardoor dat de volgende keer als
        // createGameInstance aangeroepen wordt, deze al ziet dat de klasse variabele niet 0 is.
        AFactory* aFactory;

        // Constructors
        Game(AFactory*);
        Game(const Game&);

        // Operators
        Game& operator=(const Game&);

    public:
        // Constructors
        ~Game();

        // Methods
        // Deze createGameInstance method moet static zijn zodat deze methode een klasse methode wordt ==> deze methode kan
        // aangeroepen worden zonder dat er een instantie (object) bestaat van Game.
        static Game* createGameInstance(AFactory*);
        void run();
    };
}

#endif //SPACE_INVADORS_GAME_H
