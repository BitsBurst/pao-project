#ifndef SMARTSENSORS_ERRORCONTROLLER_H
#define SMARTSENSORS_ERRORCONTROLLER_H

#include "../core/AbstractController.h"
#include "../../model/exception/NormalException.h"
#include "../../model/exception/FatalException.h"
class ErrorController: public AbstractController {
	Q_OBJECT
public:
	ErrorController();
	~ErrorController();
	bool Init();
	void Destroy();
	void manageException(NormalException);
	void manageException(FatalException);

};

#endif //SMARTSENSORS_ERRORCONTROLLER_H
