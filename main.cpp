#include "src/utility/logger/Logger.h"
#include "src/MyApp.h"

int main(int argc, char *argv[])
{
	Logger::Init();
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-d") == 0)
		{
			Logger::SetLogLevel(LogLevel::INFO);
		}
	}
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Application Start");
	MyApp a(argc, argv);
    return a.exec();
}
