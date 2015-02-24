#ifndef MODEL_H
#define MODEL_H
#include "subject.h"

//! Model is in charge of the Alarm System's logic. With the use of the boolean, this class will decide whether to trip the alarm or not, and send remote messages to subscribed clients

class Model: public Observable
{
public:
    Model();
    //! Locks the system
    void lock();
    //! Unlocks the system
    void unlock();
    //! Destructor
    virtual ~Model(){}
    //! Boolean responsible for keeping track of system status
    bool locked = true;
private:

};

#endif // MODEL_H
