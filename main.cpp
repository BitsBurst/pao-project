#include "src/utility/logger/Logger.h"
#include "src/MyApp.h"

int main(int argc, char *argv[])
{
	Logger::Init();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Application Start");
	MyApp a(argc, argv);
    return a.exec();
}
