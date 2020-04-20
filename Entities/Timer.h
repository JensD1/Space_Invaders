//
// Created by Jens on 23/03/2020.
//

#ifndef SPACE_INVADERS_TIMER_H
#define SPACE_INVADERS_TIMER_H

namespace SI {
    class Timer {
    public:
        // Constructors
        Timer();
        virtual ~Timer();
        Timer(const SI::Timer&);

        // Operators
        SI::Timer& operator=(const SI::Timer&);

        virtual bool timePassed(unsigned long) = 0;
        virtual void start() = 0;
    };
}

#endif //SPACE_INVADERS_TIMER_H
