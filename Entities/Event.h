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
        Event(const Event&);

        // Operators
        Event& operator=(const Event&);

        // Setters
        virtual void setControl(Control);

        // Getters
        virtual Control getControl() const;

        // Methods
        virtual std::set<Control> handleEvent() = 0;

    };
}

#endif //SPACE_INVADORS_EVENT_H
