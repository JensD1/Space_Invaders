//
// Created by Jens on 27/04/2020.
//

#ifndef SPACE_INVADERS_REUSABLEENTITY_H
#define SPACE_INVADERS_REUSABLEENTITY_H

#include "Entity.h"
namespace SI {
    class ReusableEntity : public Entity {
    protected:
        bool inField;
    public:
        // Constructors
        ReusableEntity(float, float, float, float, float, float);
        virtual ~ReusableEntity();
        ReusableEntity(const SI::ReusableEntity&);

        // Operators
        SI::ReusableEntity& operator=(const SI::ReusableEntity&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
        virtual void updatePosition() = 0;
        void resetPosition();
        virtual void hasCollision() = 0;
        bool getInField();
        void setInField(bool);
    };
}

#endif //SPACE_INVADERS_REUSABLEENTITY_H
