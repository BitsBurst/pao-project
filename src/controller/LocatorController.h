#ifndef SMARTSENSORS_LOCATORCONTROLLER_H
#define SMARTSENSORS_LOCATORCONTROLLER_H

#include "storage/StorageController.h"
#include "window/WindowController.h"
#include "business/BusinessController.h"

class WindowController;

class LocatorController {
private:
	static StorageController* storage_controller_;
	static WindowController* window_controller_;
	static BusinessController* business_controller_;
public:
	static StorageController* StorageControllerInstance();
	static WindowController* WindowControllerInstance();
	static BusinessController* BusinessControllerInstance();
	static bool Init();

};

#endif //SMARTSENSORS_LOCATORCONTROLLER_H
