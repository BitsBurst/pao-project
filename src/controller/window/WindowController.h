#ifndef SMARTSENSORS_WINDOWCONTROLLER_H
#define SMARTSENSORS_WINDOWCONTROLLER_H

#include "../core/AbstractController.h"
#include "../../mainwindow.h"
class WindowController: public AbstractController {
public:
	WindowController();
	bool Init();
private:
	MainWindow* main_window_;
};

#endif //SMARTSENSORS_WINDOWCONTROLLER_H
