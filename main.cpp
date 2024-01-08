#include "src/controller/LocatorController.h"
#include "src/utility/Logger.h"
#include "src/tests/testDavide.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	Logger::Init();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Application Start");

    QApplication a(argc, argv);
	LocatorController::Init();
	TestDavide::runTestV2();
    return a.exec();
}
