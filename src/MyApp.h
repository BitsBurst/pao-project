#ifndef SMARTSENSORS_MYAPP_H
#define SMARTSENSORS_MYAPP_H


#include <QApplication>
#include "controller/LocatorController.h"

class MyApp: public QApplication {
private:

public:
	MyApp(int i, char** p_string);
	~MyApp();
};
#endif //SMARTSENSORS_MYAPP_H
