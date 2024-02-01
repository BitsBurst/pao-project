#include "LocatorController.h"
#include "../utility/logger/Logger.h"
StorageController* LocatorController::storage_controller_ = nullptr;
WindowController* LocatorController::window_controller_ = nullptr;
BusinessController* LocatorController::business_controller_ = nullptr;
ErrorController* LocatorController::error_controller_ = nullptr;
/*
 * @brief This function returns the instance of the StorageController.
 * @details If the instance is not created yet, it will be created.
 * @return The instance of the StorageController.
 */
StorageController* LocatorController::StorageControllerInstance()
{
	if (storage_controller_ == nullptr)
	{
		storage_controller_ = new class StorageController();
	}
	return storage_controller_;
}
/*
 * @brief This function returns the instance of the WindowController.
 * @details If the instance is not created yet, it will be created.
 * @return The instance of the WindowController.
 */
WindowController* LocatorController::WindowControllerInstance() {
	if (window_controller_ == nullptr)
	{
		window_controller_ = new class WindowController();
	}
	return window_controller_;
}
/*
 * @brief This function returns the instance of the BusinessController.
 * @details If the instance is not created yet, it will be created.
 * @return The instance of the BusinessController.
 */
BusinessController* LocatorController::BusinessControllerInstance() {
	if (business_controller_ == nullptr)
	{
		business_controller_ = new class BusinessController();
	}
	return business_controller_;
}
/*
 * @brief This function returns the instance of the ErrorController.
 * @details If the instance is not created yet, it will be created.
 * @return The instance of the ErrorController.
 */
ErrorController* LocatorController::ErrorControllerInstance() {
	if (error_controller_ == nullptr)
	{
		error_controller_ = new class ErrorController();
	}
	return error_controller_;
}
/*
 * @brief This function initializes all controllers.
 * @details This function initializes all controllers.
 * @return True if all controllers were initialized successfully, false otherwise.
 */
bool LocatorController::Init()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, "Locator Started");
	bool result = true;
	result &= WindowControllerInstance()->Init();
	result &= BusinessControllerInstance()->Init();
	result &= StorageControllerInstance()->Init();
	result &= ErrorControllerInstance()->Init();
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, "Locator Finished" + QString(result ? "successfully" : "with errors"));
	return result;
}
/*
 * @brief This function destroys all controllers.
 * @details This function destroys all controllers.
 */
void LocatorController::Destroy()
{
	StorageControllerInstance()->Destroy();
	WindowControllerInstance()->Destroy();
	BusinessControllerInstance()->Destroy();
	ErrorControllerInstance()->Destroy();
}
