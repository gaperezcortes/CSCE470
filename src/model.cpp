#include "model.h"
#include "iostream"

Model::Model()
{
    locked=true;
    tripped = false;
}

void Model::lock() {
    locked=true;
    notifyObserver();
}

void Model::unlock() {
    locked=false;
    notifyObserver();
}

void Model::fire_alarm(){
    if(!locked)
        return;
    if(tripped){

    }else{
        tripped = true;
        std::cout << "Alarm fired" << std::endl;
    }

}

void Model::stop_alarm_and_continue(){
    if(!locked)
        return;
    tripped = false;
    lock();
}

void Model::set_RFModule(RFModule*rf){
    this->rf = rf;
    this->rf->init();
    this->rf->start();
}
