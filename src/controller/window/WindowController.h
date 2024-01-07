#ifndef SMARTSENSORS_WINDOWCONTROLLER_H
#define SMARTSENSORS_WINDOWCONTROLLER_H

#include "../core/AbstractController.h"
#include "../../view/MainView.h"

class WindowController: public AbstractController {
public:
	WindowController();
	bool Init();
private:
	MainView* main_window_;
};

#endif //SMARTSENSORS_WINDOWCONTROLLER_H
