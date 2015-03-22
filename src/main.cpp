#include <QApplication>
#include "mainwindowimpl.h"
#include "ui_mainwindow.h"

#include "observer.h"
#include "subject.h"
#include "model.h"
#include "qtcontroller.h"

#include "rfmodule.h"
#include "rfmanager.h"

#include "pthread.h"
#include <unistd.h>
#include <iostream>


//! Main method ties together the software using the MVC design pattern
int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    MainWindowImpl win;
    //! The MVC design pattern is practiced here
    Model model = Model();

    QTController controller;
    controller.model = &model;
    controller.view = &win;
    model.Observable::addObserver((Observer*)&win);

    //! Show the application GUI
    win.setWindowFlags(Qt::FramelessWindowHint);
    win.setGeometry(0,0,320,240);
    win.show();

    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    controller.init_listeners();

    RFManager *rfm = new RFManager();
    RFModule rf = RFModule(rfm);
    rfm->set_model(&model);

    model.set_RFModule(&rf);
    model.stop_alarm_and_disable_system();

    std::cout << "Exitting...";

    return app.exec();
}
