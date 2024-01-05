#ifndef SMARTSENSORS_LOCATORCONTROLLER_H
#define SMARTSENSORS_LOCATORCONTROLLER_H

#include "storage/StorageController.h"
#include "window/WindowController.h"
#include "business/BusinessController.h"

class LocatorController {
private:
	static StorageController* storage_controller_;
	static StorageController* StorageControllerInstance();
	static WindowController* window_controller_;
	static WindowController* WindowControllerInstance();
	static BusinessController* business_controller_;
	static BusinessController* BusinessControllerInstance();
public:
	static bool Init();

};

#endif //SMARTSENSORS_LOCATORCONTROLLER_H
