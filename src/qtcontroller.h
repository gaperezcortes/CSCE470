#ifndef QTCONTROLLER_H
#define QTCONTROLLER_H

#include <QObject>
#include "mainwindowimpl.h"
#include "model.h"

//! QTController is responsible of handling events from the GUI

class QTController : public QObject
{
    Q_OBJECT
public:
    explicit QTController(QObject *parent = 0);
    void init_listeners();
    Model *model;
    MainWindowImpl *view;

private slots:
    //! Sends lock message to the model
    void lock();
    //! Sends unlock message to the model
    void unlock();
signals:

public slots:

};

#endif // QTCONTROLLER_H
