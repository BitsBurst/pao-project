#ifndef SMARTSENSORS_LOGGER_H
#define SMARTSENSORS_LOGGER_H

#include <QString>
#include <QFile>
#include <QDateTime>
enum class LogLevel {
	INFO,
	WARNING,
	L_ERROR
};
enum class LogMethod {
	M_IN,
	M_OUT,
};
class Logger {
private:
	static LogLevel log_level_;
	static QFile* log_file_;
	static QString log_filename_;
	static void CheckMaxLogSize();
	static std::map<LogLevel,std::string> ll_map;
	static std::map<LogMethod,std::string> lm_map;
public:
	static void Init(QString log_file_path = "log.txt");
	static LogLevel GetLogLevel();
	static void SetLogLevel(LogLevel log_level);
	static void Log(LogLevel, QString, int, QString, QString);
	static void Log(LogLevel, QString, int, QString, LogMethod);
};

#endif //SMARTSENSORS_LOGGER_H
