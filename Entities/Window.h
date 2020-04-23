//
// Created by Jens on 14/04/2020.
//

#ifndef SPACE_INVADERS_WINDOW_H
#define SPACE_INVADERS_WINDOW_H

#include <string>

namespace SI {
    class Window {
    public:
        // Constructors
        Window();
        virtual ~Window();
        Window(const SI::Window&);

        // Operators
        SI::Window& operator=(const SI::Window&);

        virtual void update() = 0;
        virtual void clear() = 0;
        virtual void drawSprite(float, float, float, float, int) = 0;
        virtual void drawText(float, float, std::string) = 0;
        virtual void visualizeStartScreen() = 0;
        virtual void visualizeEndScreen(int, bool) = 0;
    };
}


#endif //SPACE_INVADERS_WINDOW_H
