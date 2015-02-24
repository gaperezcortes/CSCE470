#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "observer.h"

//! This Qt4 front-end GUI responsible for all of the user's input

class MainWindowImpl : public QMainWindow, public Ui::MainWindow, public Observer
{
Q_OBJECT
public:
    //! The constructor
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
    //! GUI will update based on any changes to the model
    void update(class Observable*); //! The subject pointer is passed as a parameter to get the changes
private slots:
    //! A function to be called by a QObject to quit the program
    void quit();
};
#endif




