//
// Created by Jens on 9/03/2020.
//

#ifndef SPACE_INVADORS_BONUSENTITY_H
#define SPACE_INVADORS_BONUSENTITY_H

#include "ReusableEntity.h"
namespace SI {
    class BonusEntity : public ReusableEntity {
    protected:
        bool active;
    public:
        // Constructors
        BonusEntity(float, float, float, float, float, float);
        virtual ~BonusEntity();
        BonusEntity(const SI::BonusEntity&);

        // Operators
        SI::BonusEntity& operator=(const SI::BonusEntity&);

        // Methods
        virtual void visualize(SI::Window*) = 0;
        void hasCollision();
        bool getActive();
        void setActive(bool);
        void spawn();
    };
}

#endif //SPACE_INVADORS_BONUSENTITY_H
