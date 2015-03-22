#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

//! Observer Superclass for implementing the Observer design pattern.
class Observer
{
public:
    Observer();
    //! Abstract update method for when observers are notified.
    virtual void update(class Observable*); //! Pass the subject/observable object for handling
};

#endif // OBSERVER_H
