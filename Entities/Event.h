//
// Created by Jens on 16/03/2020.
//

#ifndef SPACE_INVADORS_EVENT_H
#define SPACE_INVADORS_EVENT_H

#include "../GameConstants.h"
#include <set>

namespace SI {
    class Event {
    private:
        // Variables
        Control control;

    public:
        // Constructors
        Event();
        virtual ~Event();
        Event(const SI::Event&);

        // Operators
        SI::Event& operator=(const SI::Event&);

        // Setters
        virtual void setControl(SI::Control);

        // Getters
        virtual SI::Control getControl() const;

        // Methods
        virtual std::set<SI::Control> handleEvent() = 0;

    };
}

#endif //SPACE_INVADORS_EVENT_H
