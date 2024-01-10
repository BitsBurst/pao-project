#ifndef SMARTSENSORS_WINDOWCONTROLLER_H
#define SMARTSENSORS_WINDOWCONTROLLER_H

#include "../core/AbstractController.h"
#include "../../view/MainView.h"

class WindowController: public AbstractController {
Q_OBJECT
public:
	WindowController();
	bool Init();
	void Destroy();
private:
	MainView* main_window_;
};

#endif //SMARTSENSORS_WINDOWCONTROLLER_H
