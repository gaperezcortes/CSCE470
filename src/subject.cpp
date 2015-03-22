#include "subject.h"
#include "observer.h"
//#include <iostream>

Observable::Observable()
{
}

void Observable::addObserver(Observer * observer) {
    observers.push_back(observer);
}

void Observable::notifyObservers() {
    for(unsigned int i = 0; i<observers.size(); i++) {
        //std::cout << "Observer "<<i<<std::endl;
        Observer* ob = observers[i];
        ob->update(this);
    }
}
