//
// Created by Jens on 2/03/2020.
//

#ifndef SPACE_INVADORS_PBONUS_H
#define SPACE_INVADORS_PBONUS_H

#include "BonusEntity.h"
namespace SI {
    class PBonus : public SI::BonusEntity {
    public:
        // Constructors
        PBonus(float, float, float, float, float, float);
        virtual ~PBonus();
        PBonus(const PBonus&);

        // Operators
        PBonus& operator=(const PBonus&);

        // Methods
        virtual void visualize() = 0;
    };
}

#endif //SPACE_INVADORS_PBONUS_H
