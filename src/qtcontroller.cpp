#include "qtcontroller.h"
#include "model.h"
#include "mainwindowimpl.h"
#include <iostream>
#include <QSignalMapper>
#include <string>

QTController::QTController(QObject *parent): QObject(parent)
{
    buffer="";
}

void QTController::init_listeners() {

    view->connect(view->btn_arm, SIGNAL(released()), this, SLOT(arm()));
    //view->connect(view->btn_unlock, SIGNAL(released()), this, SLOT(disarm()));
    view->connect(view->n0, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n1, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n2, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n3, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n4, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n5, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n6, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n7, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n8, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->n9, SIGNAL(released()), this, SLOT(numkey_pressed()));
    view->connect(view->npound, SIGNAL(released()), this, SLOT(submit()));
}

void QTController::arm() {
    model->arm();

}

void QTController::disarm() {
    model->disarm();
}

void QTController::numkey_pressed(){
    QPushButton *button = (QPushButton *)sender();
    append_to_buffer(button->text()[0].toAscii());
}

void QTController::append_to_buffer(char ch){
    if(buffer.length() < 4){
        buffer += ch;
    }
}

void QTController::submit(){
    if(buffer == "1123"){
        if(model->isTripped()){
            model->stop_alarm_and_disable_system();
        }
    }
    buffer = "";
}
