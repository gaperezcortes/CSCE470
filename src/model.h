#ifndef MODEL_H
#define MODEL_H
#include "subject.h"
#include "rfmodule.h"

class RFModule;

//! Model is in charge of the Alarm System's logic. With the use of the boolean, this class will decide whether to trip the alarm or not, and send remote messages to subscribed clients
class Model: public Observable
{
public:
    Model();
    virtual ~Model(){}
    //! Locks the system
    void lock();
    //! Unlocks the system
    void unlock();
    void fire_alarm();
    void stop_alarm_and_continue();
    void set_RFModule(RFModule*);
    //! Boolean responsible for keeping track of system status
    bool locked;
private:
    RFModule *rf;


    bool tripped;
};

#endif // MODEL_H
