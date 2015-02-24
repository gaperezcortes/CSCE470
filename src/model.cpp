#include "model.h"

Model::Model()
{
}

void Model::lock(){
    locked=true;
    notifyObserver();
}

void Model::unlock(){
    locked=false;
    notifyObserver();
}
