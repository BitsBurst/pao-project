#ifndef SMARTSENSORS_LOCATORCONTROLLER_H
#define SMARTSENSORS_LOCATORCONTROLLER_H

#include "storage/StorageController.h"
#include "window/WindowController.h"
#include "business/BusinessController.h"
#include "error/ErrorController.h"

class LocatorController {
private:
	static StorageController* storage_controller_;
	static WindowController* window_controller_;
	static BusinessController* business_controller_;
	static ErrorController* error_controller_;
public:
	static StorageController* StorageControllerInstance();
	static WindowController* WindowControllerInstance();
	static BusinessController* BusinessControllerInstance();
	static ErrorController* ErrorControllerInstance();
	static bool Init();
	static void Destroy();

};

#endif //SMARTSENSORS_LOCATORCONTROLLER_H
