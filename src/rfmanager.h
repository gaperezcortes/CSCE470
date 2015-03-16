#ifndef RFMANAGER_H
#define RFMANAGER_H

#include <string>
#include <vector>


class RFManager
{

public:
    struct transmitter
    {
        std::string id;
        timespec timestamp;
        transmitter(std::string id_in)
        {
            id = id_in;
        }
    } ;

    RFManager();
    ~RFManager();
    void update_time(std::string);
    void check();
private:
    std::vector<transmitter> transmitters;
    double MAX_DELAY; // in seconds
int miss_count;
int misses;
};

#endif // RFMANAGER_H
