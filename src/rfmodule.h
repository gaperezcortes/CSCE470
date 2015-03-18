#ifndef RFMODULE_H
#define RFMODULE_H

#include "thread.h"
#include "RCSwitch.h"
#include "rfmanager.h"

class RFManager;

//! RFModule reads messages sent by RF transmitters and passes them to the RFManager
class RFModule : public Thread
{
public:
    RFModule(RFManager*);
    ~RFModule();
    void init();
    void stop();
    void *run();

private:
    bool running;
    RCSwitch mySwitch;
    RFManager *rfm;
};

#endif // RFMODULE_H
