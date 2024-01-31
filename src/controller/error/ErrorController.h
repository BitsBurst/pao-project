#ifndef SMARTSENSORS_ERRORCONTROLLER_H
#define SMARTSENSORS_ERRORCONTROLLER_H

#include "../core/AbstractController.h"
#include "../../model/exception/NormalException.h"
#include "../../model/exception/FatalException.h"
/**
 * @brief The ErrorController class
 * @details This class is used to manage the exceptions thrown by the application.
 * It is a singleton class.
 */
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
