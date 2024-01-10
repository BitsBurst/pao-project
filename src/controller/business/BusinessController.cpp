#include "BusinessController.h"
#include "../LocatorController.h"
BusinessController::BusinessController()
{

}
bool BusinessController::Init()
{
	subscribeToEvents();
	return true;
}
void BusinessController::subscribeToEvents()
{
	connect(LocatorController::StorageControllerInstance(), &StorageController::StorageReady, this, &BusinessController::storageReady);
}

void BusinessController::Destroy()
{

}
void BusinessController::storageReady()
{
	LocatorController::WindowControllerInstance()->setDisabled(false);
}
