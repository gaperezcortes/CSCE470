#include "model.h"

Model::Model()
{
locked=true;
}

void Model::lock(){
    locked=true;
    notifyObserver();
}

void Model::unlock(){
    locked=false;
    notifyObserver();
}
