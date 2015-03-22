#include "mainwindowimpl.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "observer.h"
#include "subject.h"
#include "model.h"
#include <string>

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
    : QMainWindow(parent, f)
{
    setupUi(this);
}


void MainWindowImpl::update(class Observable* observable) {

    Model *model = static_cast<Model*>(observable);
    if(model->isTripped()) {
        label->setText("Alarm Tripped");

    } else if (!(model->isArmed())) {
        label->setText("Disarmed");
        enable_all();
    }else{
        label->setText("Armed");
        disable_all();
    }
}

void MainWindowImpl::enable_all(){
    btn_arm->setEnabled(true);
    btn_test->setEnabled(true);
    btn_walk->setEnabled(true);
    btn_options->setEnabled(true);
}

void MainWindowImpl::disable_all(){
    btn_arm->setEnabled(false);
    btn_test->setEnabled(false);
    btn_walk->setEnabled(false);
    btn_options->setEnabled(false);
}
