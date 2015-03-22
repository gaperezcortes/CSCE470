#ifndef QTCONTROLLER_H
#define QTCONTROLLER_H

#include <QObject>
#include "mainwindowimpl.h"
#include "model.h"
#include <string>

//! QTController is responsible of handling events from the GUI

class QTController : public QObject
{
    Q_OBJECT
public:
    explicit QTController(QObject *parent = 0);
    void init_listeners();
    Model *model;
    MainWindowImpl *view;
private:
    std::string buffer;
    //! Add number to the pin sequence
    void append_to_buffer(char ch);
    void clear_buffer();
private slots:
    //! Sends lock message to the model
    void arm();
    //! Sends unlock message to the model
    void disarm();
    //! Handles number presses
    void numkey_pressed();
    //! Submit the current PIN
    void submit();

signals:

public slots:

};

#endif // QTCONTROLLER_H
