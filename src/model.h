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
    void arm();
    //! Unlocks the system
    void disarm();
    void fire_alarm();
    void stop_alarm_and_disable_system();
    void set_alarm_tripped(bool);
    void set_RFModule(RFModule*);
    //! Boolean responsible for keeping track of system status
    bool isTripped();
    bool isArmed();
private:

    RFModule *rf;
    bool armed;
    bool tripped;
};

#endif // MODEL_H
