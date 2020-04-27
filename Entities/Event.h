//
// Created by Jens on 16/03/2020.
//

#ifndef SPACE_INVADORS_EVENT_H
#define SPACE_INVADORS_EVENT_H

#include "../GameConstants.h"
#include <set>

namespace SI {
    class Event {
    public:
        // Constructors
        Event();
        virtual ~Event();
        Event(const SI::Event&);

        // Operators
        SI::Event& operator=(const SI::Event&);

        // Methods
        virtual std::set<SI::Control> handleEvent() = 0;

    };
}

#endif //SPACE_INVADORS_EVENT_H
