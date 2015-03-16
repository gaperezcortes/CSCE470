#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

//! Observable Superclass for subject/observable objects
class Observable
{
public:
    Observable();
    //! Add and Observer object to the vector
    void addObserver(class Observer*); //! Observer to be added
    //! Notify all the Observers
    void notifyObserver();
    //! Contains the Observer objects
    std::vector<class Observer*> observers;
};

#endif // SUBJECT_H
