#include "Controller.h"

Controller::Controller(QObject * parent)
    : QObject(parent), view_(new MainView(this)) {
    view_->show();
}