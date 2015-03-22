#ifndef RFMANAGER_H
#define RFMANAGER_H

#include <string>
#include <vector>
#include "model.h"

class Model;
//! RFManager is responsible for monitoring the relayed information from RFModule and firing an appropriate event when a threshold is violated
class RFManager
{

public:
    //! Struct to keep track of transmitter IDs
    struct transmitter
    {
        unsigned int id;
        timespec timestamp;
        transmitter(unsigned int id_in)
        {
            id = id_in;
        }
    } ;

    RFManager();
    ~RFManager();
    //! Update the timestamp for given transmitter ID
    void update_time(int);
    //! Check threshold isn't violated
    void check();
    void set_model(Model *);

private:
    std::vector<transmitter*> transmitters;
    double MAX_DELAY; // in seconds
int miss_count;
int misses;
Model *model;
};

#endif // RFMANAGER_H
