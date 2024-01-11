#include "MyApp.h"
MyApp::~MyApp()
{
	LocatorController::Destroy();
	Logger::Destroy();
}
MyApp::MyApp(int i, char** p_string): QApplication(i, p_string) {
	try {
		LocatorController::Init();
	}
	catch (NormalException& e) {
		LocatorController::ErrorControllerInstance()->manageException(e);
	}
	catch (FatalException& e) {
		LocatorController::ErrorControllerInstance()->manageException(e);
	}
	catch (std::runtime_error& e) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Runtime error: %1").arg(e.what()));
	}
	catch (std::exception& e) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Exception: %1").arg(e.what()));
	}
	catch (...) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, "Unexpected error");
	}
}