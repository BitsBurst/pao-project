#include "MyApp.h"

fa::QtAwesome* MyApp::awesome = new fa::QtAwesome();

MyApp::~MyApp()
{
	LocatorController::Destroy();
	Logger::Destroy();
}
MyApp::MyApp(int i, char** p_string): QApplication(i, p_string) {
	try {
        awesome->initFontAwesome();

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

fa::QtAwesome* MyApp::getAwesome()
{
    return awesome;
}
