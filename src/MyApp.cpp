#include "MyApp.h"
/**
 * @brief MyApp::~MyApp
 * This is the destructor of the application. It destroys the LocatorController and the Logger.
 */
MyApp::~MyApp()
{
	LocatorController::Destroy();
	Logger::Destroy();
}
/**
 * @brief MyApp::MyApp
 * This is the constructor of the application. It initializes the resources and the custom elements.
 * It also initializes the LocatorController.
 * @param i number of arguments
 * @param p_string arguments
 */
MyApp::MyApp(int i, char** p_string): QApplication(i, p_string) {
	try {
		Q_INIT_RESOURCE(resources);
		CustomElements::Init();
		LocatorController::Init();
	}
	catch (NormalException& e) {
		LocatorController::ErrorControllerInstance()->manageException(e);
	}
	catch (FatalException& e) {
		LocatorController::ErrorControllerInstance()->manageException(e);
	}
	catch (std::runtime_error& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Runtime error: %1").arg(e.what()));
	}
	catch (std::exception& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Exception: %1").arg(e.what()));
	}
	catch (...) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, "Unexpected error");
	}
}