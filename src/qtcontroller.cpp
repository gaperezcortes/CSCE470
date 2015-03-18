#include "qtcontroller.h"
#include "model.h"
#include "mainwindowimpl.h"

QTController::QTController(QObject *parent) :
    QObject(parent)
{
}

void QTController::init_listeners() {
    view->connect(view->btn_lock, SIGNAL(released()), this, SLOT(lock()));
    view->connect(view->btn_unlock, SIGNAL(released()), this, SLOT(unlock()));
}
void QTController::lock() {
    view->label->setText("Locked");
}
void QTController::unlock() {
    view->label->setText("Unlocked");
}
