#include <QApplication>
#include "mainwindowimpl.h"
#include "ui_mainwindow.h"

#include "pthread.h"
#include <unistd.h>

#include <iostream>

#include "observer.h"
#include "subject.h"
#include "model.h"
#include "qtcontroller.h"

void *go(void * m){
    Model *model = (Model*)m;
    usleep(1500*1000);
    model->unlock();
    usleep(1500*1000);
    model->lock();
    std::cout << "Proof of threading" << std::endl;
    pthread_exit(NULL);
}

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

    //! Multithreading test
    pthread_t t;
    pthread_create(&t, NULL,go, (void *)&model);

    //! Show the application GUI
    win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    controller.init_listeners();

    return app.exec();
    pthread_join(t,NULL);
}
