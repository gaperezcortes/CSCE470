#include "rfmanager.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "model.h"

RFManager::RFManager()
{
    MAX_DELAY = 3.0;
    miss_count = 0;
    misses =0;
// insert read the list of transmitter ID's
    transmitters = std::vector<transmitter*>();
    transmitter *one = new transmitter(17);
    transmitters.push_back(one);
    // start counting time from now
    timespec time_now;
    clock_gettime(CLOCK_REALTIME, &time_now);
    transmitter *t;
    for (unsigned int i = 0; i < transmitters.size(); i++)
    {
        t = transmitters[i];
        clock_gettime(CLOCK_REALTIME, &time_now);
        t->timestamp = time_now;
        t->timestamp.tv_nsec=0;
        t->timestamp.tv_sec=0;
    }
    t= NULL;
    delete t;
}

RFManager::~RFManager()
{

}

void RFManager::update_time(int id) {
    struct timespec time_now;
    clock_gettime(CLOCK_REALTIME, &time_now);
    transmitter *t;
    for (unsigned int i = 0; i < transmitters.size(); i++)
    {
        t = transmitters[i];
        if(t->id == id) {
            t->timestamp = time_now;
            break;
        }
    }
    t=NULL;
    delete t;
}

void RFManager::check() {

    double time_difference;
    struct timespec time_now;
    clock_gettime(CLOCK_REALTIME, &time_now);

    transmitter *t;
    for (unsigned int i = 0; i < transmitters.size(); i++)
    {
        t = transmitters[i];
        int s =t->timestamp.tv_sec, ns=t->timestamp.tv_nsec;

        time_difference = ((time_now.tv_sec - s)) + ((time_now.tv_nsec - ns)*1.0e-9);
        if(time_difference > MAX_DELAY)
        {
            std::cout << t->id << " Threshold "<<  time_difference << " count = "<< misses <<std::endl;
            
            if (time_difference > MAX_DELAY +4.0) {
                std::cout << t->id << " Exceeded "<<  time_difference << " count = "<< misses <<std::endl;
                misses++;
                model->fire_alarm();
            }
        }
        else
        {
            std::cout << t->id << " OK "<<  time_difference << " count = "<< misses<< std::endl;
            // Do nothing. Keep scanning
            miss_count = 0;
        }
    }
}

void RFManager::set_model(Model *model){
    this->model = model;
}
