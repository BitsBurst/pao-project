#ifndef SMARTSENSORS_BUSINESSCONTROLLER_H
#define SMARTSENSORS_BUSINESSCONTROLLER_H

#include "../core/AbstractController.h"
#include "../storage/StorageController.h"

class BusinessController: public AbstractController {
Q_OBJECT
public:
	BusinessController();
	bool Init();
private:
	void subscribeToEvents();
	void loadStorageError();
};

#endif //SMARTSENSORS_BUSINESSCONTROLLER_H
