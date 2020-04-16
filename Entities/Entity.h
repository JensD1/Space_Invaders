//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_ENTITY_H
#define SPACE_INVADORS_ENTITY_H

#include "../GameConstants.h"

namespace SI {
    class Entity {
    protected:
        // Variables
        float xPos;
        float yPos;
        float width;
        float height;
        float dx;
        float dy;

    public:
        // Constructors
        Entity();
        Entity(float, float, float, float, float, float);
        virtual ~Entity();
        Entity(const Entity&);

        // Methods
        bool detectCollision(Entity*);
        virtual void visualize() = 0;
        virtual void updatePosition() = 0;
        virtual void hasCollision() = 0;

        // Getters
        float getXPos() const;
        float getYPos() const;
        float getWidth() const;
        float getHeight() const;
        float getDx() const;
        float getDy() const;

        // Setters
        void setXPos(float xPos);
        void setYPos(float yPos);
        void setWidth(float width);
        void setHeight(float height);
        void setDx(float dx);
        void setDy(float dy);

        // Operators
        Entity& operator=(const Entity&);
    };
}

#endif //SPACE_INVADORS_ENTITY_H
