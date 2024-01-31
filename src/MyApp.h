#ifndef SMARTSENSORS_MYAPP_H
#define SMARTSENSORS_MYAPP_H


#include <QApplication>
#include "controller/LocatorController.h"
#include "../include/QtAwesome/QtAwesome.h"

class MyApp: public QApplication {
private:
    static fa::QtAwesome* awesome;
public:
	MyApp(int i, char** p_string);
	~MyApp();

    static fa::QtAwesome* getAwesome();
};
#endif //SMARTSENSORS_MYAPP_H
