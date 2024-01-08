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
	connect(LocatorController::StorageControllerInstance(), &StorageController::ErrorLoadingStorage, this, &BusinessController::loadStorageError);
}

void BusinessController::loadStorageError()
{
	qDebug() << "loadStorageError";
}