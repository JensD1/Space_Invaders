//
// Created by Jens on 14/04/2020.
//

#ifndef SPACE_INVADERS_WINDOW_H
#define SPACE_INVADERS_WINDOW_H

namespace SI {
    class Window {
    public:
        // Constructors
        Window();
        virtual ~Window();
        Window(const Window&);

        // Operators
        Window& operator=(const Window&);

        virtual void update() = 0;
        virtual void clear() = 0;
        virtual void drawSprite(float, float, float, float, int) = 0;
    };
}


#endif //SPACE_INVADERS_WINDOW_H
