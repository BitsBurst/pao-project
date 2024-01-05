#include "LocatorController.h"
#include "../utility/Logger.h"
StorageController* LocatorController::storage_controller_ = nullptr;
WindowController* LocatorController::window_controller_ = nullptr;
BusinessController* LocatorController::business_controller_ = nullptr;

StorageController* LocatorController::StorageControllerInstance()
{
	if (storage_controller_ == nullptr)
	{
		storage_controller_ = new class StorageController();
	}
	return storage_controller_;
}

WindowController* LocatorController::WindowControllerInstance() {
	if (window_controller_ == nullptr)
	{
		window_controller_ = new class WindowController();
	}
	return window_controller_;
}

BusinessController* LocatorController::BusinessControllerInstance() {
	if (business_controller_ == nullptr)
	{
		business_controller_ = new class BusinessController();
	}
	return business_controller_;
}

bool LocatorController::Init()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Locator Started");
	bool result = true;
	result &= BusinessControllerInstance()->Init();
	result &= StorageControllerInstance()->Init();
	result &= WindowControllerInstance()->Init();
	return result;
}
