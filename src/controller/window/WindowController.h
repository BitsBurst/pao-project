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
	void setDisabled(bool);
private:
	MainView* main_window_;

    QStackedWidget * content_stack_;
    QStackedWidget * sidebar_stack_;
};

#endif //SMARTSENSORS_WINDOWCONTROLLER_H
