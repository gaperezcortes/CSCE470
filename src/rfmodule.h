#ifndef RFMODULE_H
#define RFMODULE_H

#include "thread.h"
#include "RCSwitch.h"
#include "rfmanager.h"

class RFModule : public Thread
{

public:
    RFModule(RFManager);
    ~RFModule();
    void enable();
    void stop();
    void *run();

private:
    bool running;
    RCSwitch mySwitch;
    RFManager rfm;
};

#endif // RFMODULE_H
