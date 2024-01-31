#ifndef SMARTSENSORS_LOGGER_H
#define SMARTSENSORS_LOGGER_H

#include <QString>
#include <QFile>
#include <QDateTime>
#include <deque>
#include <QSemaphore>
#include <QThread>
enum class LogLevel {
	_INFO_,
	_WARNING_,
	_ERROR_
};
enum class LogMethod {
	_IN_,
	_OUT_,
};
/*
 * @brief LoggerObject
 * This class is used to store the log messages in a file
 */
class LoggerObject {
	friend class LoggerWorker;
private:
	LogLevel log_level_;
	QString file_;
	int line_;
	QString methodname_;
	QString message_;
	LogMethod lm_;
	bool is_message_;
	QDateTime time_;
public:
	LoggerObject(QDateTime, LogLevel, QString, int, QString, QString);
	LoggerObject(QDateTime, LogLevel, QString, int, QString, LogMethod);
	~LoggerObject();
	QString getLogString();
};
/*
 * @brief LoggerWorker
 * This class is used to store the log messages in a file
 */
class LoggerWorker: public QThread {
Q_OBJECT
public:
	LoggerWorker(QObject * = nullptr);
	~LoggerWorker();
	void isWatingSomethingToStore();
	void WriteLog(LoggerObject);
private:
	std::deque<LoggerObject> works;
	QSemaphore emptyList;
	QSemaphore worksEdit;
protected:
	void run() override;
};
/*
 * @brief Logger
 * This class is used to store the log messages in a file
 */
class Logger {
	friend class LoggerObject;
	friend class LoggerWorker;
private:
	static LogLevel log_level_;
	static QFile* log_file_;
	static QString log_filename_;
	static LoggerWorker* worker_;
	static void CheckMaxLogSize();
	static std::map<LogLevel,std::string> ll_map;
	static std::map<LogMethod,std::string> lm_map;
public:
	static void Init(QString log_file_path = "log.txt");
	static LogLevel GetLogLevel();
	static void SetLogLevel(LogLevel log_level);
	static void Log(LogLevel, QString, int, QString, QString);
	static void Log(LogLevel, QString, int, QString, LogMethod);
	static void Destroy();
};

#endif //SMARTSENSORS_LOGGER_H
