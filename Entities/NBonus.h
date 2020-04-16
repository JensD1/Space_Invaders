//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_NBONUS_H
#define SPACE_INVADORS_NBONUS_H

#include "BonusEntity.h"

namespace SI {
    class NBonus : public SI::BonusEntity {
    public:
        // Constructors
        NBonus(float, float, float, float, float, float);
        virtual ~NBonus();
        NBonus(const NBonus&);

        // Operators
        NBonus& operator=(const NBonus&);

        // Methods
        virtual void visualize() = 0;
    };
}

#endif //SPACE_INVADORS_NBONUS_H
