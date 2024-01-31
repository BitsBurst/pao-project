#include "src/utility/logger/Logger.h"
#include "src/MyApp.h"
int main(int argc, char *argv[])
{
	Logger::Init();
	for (int i = 0; i < argc; i++)
	{
		// if -d is passed as argument, set log level to debug
		// this is useful to debug the application
		if (strcmp(argv[i], "-d") == 0)
		{
			Logger::SetLogLevel(LogLevel::_INFO_);
		}
	}
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, "Application Start");
	MyApp a(argc, argv);
    return a.exec();
}
