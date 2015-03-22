#include "model.h"
#include "iostream"

Model::Model()
{
    armed=true;
    tripped = false;
}

bool Model::isArmed(){
    return armed;
}

void Model::arm() {
    if(rf!=NULL)
        rf->start();
    armed = true;
    notifyObservers();
}

void Model::disarm() {
    if(rf!=NULL)
        rf->stop();
    armed = false;
    notifyObservers();
}

bool Model::isTripped(){
    return tripped;
}

void Model::set_alarm_tripped(bool tripped){
    this->tripped = tripped;
    notifyObservers();
}

void Model::set_RFModule(RFModule* rf){
    this->rf = rf;
    this->rf->init();
    //this->rf->start();
}

void Model::fire_alarm(){
    if(!armed)
        return;
    if(!tripped){
       set_alarm_tripped(true);
       rf->stop();
       std::cout << "Alarm fired" << std::endl;
    }
}

void Model::stop_alarm_and_disable_system(){
    set_alarm_tripped(false);
    disarm();
}
