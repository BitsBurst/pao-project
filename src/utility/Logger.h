#ifndef SMARTSENSORS_LOGGER_H
#define SMARTSENSORS_LOGGER_H

#include <QString>
#include <QFile>
#include <QDateTime>
enum class LogLevel {
	INFO,
	WARNING,
	ERROR
};
enum class LogMethod {
	IN,
	OUT,
};
class Logger {
private:
	static LogLevel log_level_;
	static QFile* log_file_;
	static QString log_filename_;
	static void CheckMaxLogSize();
public:
	static void Init(QString log_file_path = "log.txt");
	static LogLevel GetLogLevel();
	static void SetLogLevel(LogLevel log_level);
	static void Log(LogLevel, QString, int, QString, QString);
	static void Log(LogLevel, QString, int, QString, LogMethod);
};
static std::map<LogLevel,std::string> ll_map = {{LogLevel::INFO,"INFO"},{LogLevel::WARNING,"WARNING"},{LogLevel::ERROR,"ERROR"}};
static std::map<LogMethod,std::string> lm_map = {{LogMethod::IN,"IN"},{LogMethod::OUT,"OUT"}};
#endif //SMARTSENSORS_LOGGER_H
