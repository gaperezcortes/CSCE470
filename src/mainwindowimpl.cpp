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
    label->setText("Label");
    connect(n9, SIGNAL(released()), this, SLOT(quit()));
}

void MainWindowImpl::quit(){
    //n9->setText("ok");
    connect(n8, SIGNAL(released()), this, SLOT(quit()));
    std::cout << "PRINT" << std::endl;
}

void MainWindowImpl::update(class Observable* observable){

    Model *model = static_cast<Model*>(observable);
    if(model->locked){
        label->setText("Locked");
    }else{
        label->setText("Unlocked");
    }
}
//
