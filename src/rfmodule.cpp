#include "rfmodule.h"

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iostream>

#include "pthread.h"

#include <unistd.h>

#include <ctime>

#include "rfmanager.h"

RFModule::RFModule(RFManager *in)
{
    rfm = in;
}

RFModule::~RFModule()
{

}

void RFModule::init() {
    if(wiringPiSetup() == -1)
        return;
    running = false;
    RFModule::mySwitch = RCSwitch();
    int PIN = 2;
    mySwitch.enableReceive(PIN);  // Receiver on inerrupt 0 => that is pin #2
}

void *RFModule::run() {
    running = true;
	usleep(2000000);
    while(running) {
        if (mySwitch.available()) {
            int value = mySwitch.getReceivedValue();
            //std::string message = std::bitset< 24 >(value).to_string();
            if (value == 0) {
                printf("Unknown encoding");
            } else {
                /*       time_t now = time(0);
                       char* datetime = ctime(&now);
                       std::cout << datetime;
                       std::cout <<": Received "<< message.substr(19,4) <<std::endl;*/
                //rfm->update_time(message.substr(19,4));
                rfm->update_time(value);
            }
            mySwitch.resetAvailable();
        }
        //usleep(750000);
	usleep(10000);
        rfm->check();
    }
    return NULL;
}


void RFModule::stop() {
    running = false;
}

