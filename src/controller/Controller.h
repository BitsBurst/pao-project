#ifndef SMARTSENSORS_CONTROLLER_H
#define SMARTSENSORS_CONTROLLER_H

#include <QObject>
#include "../view/MainView.h"

class MainView;

class Controller : public QObject {
    Q_OBJECT
private:
    MainView * view_;

public:
    explicit Controller(QObject *parent = nullptr);
};

#endif //SMARTSENSORS_CONTROLLER_H
