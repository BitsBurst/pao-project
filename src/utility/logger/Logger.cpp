#include "Logger.h"
LogLevel Logger::log_level_ = LogLevel::_WARNING_; //log level
QFile* Logger::log_file_ = nullptr; //log file pointer
QString Logger::log_filename_ = "log.txt"; //log file name
std::map<LogLevel,std::string> Logger::ll_map = {{ LogLevel::_INFO_, "_INFO_"}, { LogLevel::_WARNING_, "_WARNING_"}, { LogLevel::_ERROR_, "_ERROR_"}}; //log level map
std::map<LogMethod,std::string> Logger::lm_map = {{ LogMethod::_IN_, "_IN_"}, { LogMethod::_OUT_, "_OUT_"}}; //log method map
const bool Logger::qdeubg_ = false; //IMPORTANT: this should be done by the preprocessor, not a runtime check
LoggerWorker* Logger::worker_ = new LoggerWorker(); //logger worker
/*
 * @brief Logger::GetLogLevel
 * This method is used to get the current log level
 * @return the current log level
 */
LogLevel Logger::GetLogLevel()
{
	return Logger::log_level_;
}
/*
 * @brief Logger::SetLogLevel
 * This method is used to set the current log level
 * @param log_level the new log level
 */
void Logger::SetLogLevel(LogLevel log_level)
{
	Logger::log_level_ = log_level;
}
/*
 * @brief Logger::CheckMaxLogSize
 * This method is used to check if the log file is too big
 * If the log file is too big, it is renamed with the current timestamp
 * and a new log file is created
 */
void Logger::CheckMaxLogSize()
{
	if(Logger::log_file_->size() > 10000000)
	{
		QFile* old_file = Logger::log_file_;
		old_file->rename( Logger::log_filename_ + "_" +  QString::number(QDateTime::currentSecsSinceEpoch()) + ".old");
		Logger::log_file_ = new QFile(Logger::log_filename_);
		Logger::log_file_->open(QIODevice::WriteOnly | QIODevice::Append);
		old_file->close();
	}
}
/*
 * @brief Logger::Log
 * This method is used to log a message
 * @param log_level the log level of the message
 * @param file the file where the message is logged
 * @param line the line where the message is logged
 * @param methodname the method where the message is logged
 * @param message the message to log
 */
void Logger::Log(LogLevel log_level, QString file, int line, QString methodname, QString message)
{
	LoggerObject log(QDateTime::currentDateTime(), log_level, file, line, methodname, message);
	Logger::worker_->WriteLog(log);
}
/*
 * @brief Logger::Log
 * This method is used to log a method call
 * @param log_level the log level of the message
 * @param file the file where the message is logged
 * @param line the line where the message is logged
 * @param methodname the method where the message is logged
 * @param lm the method call type
 */
void Logger::Log(LogLevel log_level, QString file, int line, QString methodname, LogMethod lm)
{
	LoggerObject log(QDateTime::currentDateTime(), log_level, file, line, methodname, lm);
	Logger::worker_->WriteLog(log);
}
/*
 * @brief Logger::Init
 * This method is used to initialize the logger
 * @param log_file_path the path of the log file
 */
void Logger::Init(QString log_file_path)
{
	Logger::log_filename_ = log_file_path;
	Logger::log_file_ = new QFile(log_file_path);
	Logger::log_file_->open(QIODevice::WriteOnly | QIODevice::Append);
}
/*
 * @brief Logger::Destroy
 * This method is used to destroy the logger
 */
void Logger::Destroy()
{
	Logger::worker_->isWatingSomethingToStore();
}

/*
 * @brief LoggerObject::LoggerObject
 * This constructor is used to create a log message
 * @param dt the date and time of the log message
 * @param log_level the log level of the log message
 * @param file the file where the log message is logged
 * @param line the line where the log message is logged
 * @param methodname the method where the log message is logged
 * @param message the message to log
 */
LoggerObject::LoggerObject(QDateTime dt, LogLevel log_level, QString file, int line, QString methodname, QString message) : time_(dt), log_level_(log_level), file_(file), line_(line), methodname_(methodname), message_(message), is_message_(true)
{
}
/*
 * @brief LoggerObject::LoggerObject
 * This constructor is used to create a log method call
 * @param dt the date and time of the log message
 * @param log_level the log level of the log message
 * @param file the file where the log message is logged
 * @param line the line where the log message is logged
 * @param methodname the method where the log message is logged
 * @param lm the method call type
 */
LoggerObject::LoggerObject(QDateTime dt, LogLevel log_level, QString file, int line, QString methodname, LogMethod lm) : time_(dt), log_level_(log_level), file_(file), line_(line), methodname_(methodname), lm_(lm), is_message_(false)
{
}
/*
 * @brief LoggerObject::~LoggerObject
 * This destructor is used to destroy the log message
 */
LoggerObject::~LoggerObject()
{
}
/*
 * @brief LoggerObject::getLogString
 * This method is used to get the log message as a string
 * @return the log message as a string
 */
QString LoggerObject::getLogString()
{
	if(is_message_)
		return QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(time_.toString()).arg(QString::fromStdString(Logger::ll_map[log_level_])).arg(methodname_).arg(line_).arg(file_).arg(message_);
	else
		return QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(time_.toString()).arg(QString::fromStdString(Logger::ll_map[log_level_])).arg(methodname_).arg(line_).arg(file_).arg(QString::fromStdString(Logger::lm_map[lm_]));
}

/*
 * @brief LoggerWorker::WriteLog
 * This method is used to store a log message in the queue
 * @param log the log message to store
 */
void LoggerWorker::WriteLog(LoggerObject log)
{
	worksEdit.acquire();
	works.push_front(log);
	worksEdit.release();
	emptyList.release();
}
/*
 * @brief LoggerWorker::LoggerWorker
 * This constructor is used to create a logger thread
 * @param parent the parent of the thread
 */
LoggerWorker::LoggerWorker(QObject *parent): QThread(parent), emptyList(0), worksEdit(1) {
	start();
}
/*
 * @brief LoggerWorker::~LoggerWorker
 * This destructor is used to destroy the logger thread
 */
LoggerWorker::~LoggerWorker()
{
	wait();
}
/*
 * @brief LoggerWorker::run
 * This method is used to store the log messages in a file
 * The method is executed in a separate thread
 */
void LoggerWorker::run() {
	while(true) {
		emptyList.acquire();
		worksEdit.acquire();
		LoggerObject logString = works.back();
		worksEdit.release();
		try {
			Logger::CheckMaxLogSize();
			if (Logger::log_level_<=logString.log_level_) {
				if (Logger::qdeubg_) //IMPORTANT: this should be done by the preprocessor, not a runtime check
					qDebug() << logString.getLogString();
				Logger::log_file_->write(logString.getLogString().toUtf8());
				Logger::log_file_->flush();
				Logger::log_file_->waitForBytesWritten(10000);
			}

		} catch (std::exception& e) {

		}
		worksEdit.acquire();
		works.pop_back();
		worksEdit.release();
	}
}
/*
 * @brief LoggerWorker::isWatingSomethingToStore
 * This method is used to wait for the logger thread to finish
 */
void LoggerWorker::isWatingSomethingToStore()
{
	while (emptyList.available() > 0);
}