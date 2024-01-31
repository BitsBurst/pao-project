#include "Logger.h"
/*Logger*/
LogLevel Logger::log_level_ = LogLevel::WARNING;
QFile* Logger::log_file_ = nullptr;
QString Logger::log_filename_ = "log.txt";
std::map<LogLevel,std::string> Logger::ll_map = {{LogLevel::INFO,"INFO"},{LogLevel::WARNING,"WARNING"},{LogLevel::ERROR,"ERROR"}};
std::map<LogMethod,std::string> Logger::lm_map = {{LogMethod::IN,"IN"},{LogMethod::OUT,"OUT"}};
const bool Logger::qdeubg_ = false; //IMPORTANT: this should be done by the preprocessor, not a runtime check
LoggerWorker* Logger::worker_ = new LoggerWorker();
LogLevel Logger::GetLogLevel()
{
	return Logger::log_level_;
}
void Logger::SetLogLevel(LogLevel log_level)
{
	Logger::log_level_ = log_level;
}
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

void Logger::Log(LogLevel log_level, QString file, int line, QString methodname, QString message)
{
	/*logger::CheckMaxLogSize();
	if (logger::log_level_ <= log_level)
	{
		if(logger::qdeubg_) //IMPORTANT: this should be done by the preprocessor, not a runtime check
		qDebug() << QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(message);
		logger::log_file_->write(QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(message).toUtf8());
		logger::log_file_->flush();
		logger::log_file_->waitForBytesWritten(10000);
	}*/
	LoggerObject log(QDateTime::currentDateTime(), log_level, file, line, methodname, message);
	Logger::worker_->WriteLog(log);
}
void Logger::Log(LogLevel log_level, QString file, int line, QString methodname, LogMethod lm)
{
	/*logger::CheckMaxLogSize();
	if (logger::log_level_ <= log_level)
	{
		if(logger::qdeubg_) //IMPORTANT: this should be done by the preprocessor, not a runtime check
		qDebug() << QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(QString::fromStdString(lm_map[lm]));
		logger::log_file_->write(QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(QString::fromStdString(lm_map[lm])).toUtf8());
		logger::log_file_->flush();
		logger::log_file_->waitForBytesWritten(10000);
	}*/
	LoggerObject log(QDateTime::currentDateTime(), log_level, file, line, methodname, lm);
	Logger::worker_->WriteLog(log);
}
void Logger::Init(QString log_file_path)
{
	Logger::log_filename_ = log_file_path;
	Logger::log_file_ = new QFile(log_file_path);
	Logger::log_file_->open(QIODevice::WriteOnly | QIODevice::Append);
}
void Logger::Destroy()
{
	Logger::worker_->isWatingSomethingToStore();
}

/*LoggerObject*/
LoggerObject::LoggerObject(QDateTime dt, LogLevel log_level, QString file, int line, QString methodname, QString message) : time_(dt), log_level_(log_level), file_(file), line_(line), methodname_(methodname), message_(message), is_message_(true)
{
}
LoggerObject::LoggerObject(QDateTime dt, LogLevel log_level, QString file, int line, QString methodname, LogMethod lm) : time_(dt), log_level_(log_level), file_(file), line_(line), methodname_(methodname), lm_(lm), is_message_(false)
{
}
LoggerObject::~LoggerObject()
{
}
QString LoggerObject::getLogString()
{
	if(is_message_)
		return QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(time_.toString()).arg(QString::fromStdString(Logger::ll_map[log_level_])).arg(methodname_).arg(line_).arg(file_).arg(message_);
	else
		return QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(time_.toString()).arg(QString::fromStdString(Logger::ll_map[log_level_])).arg(methodname_).arg(line_).arg(file_).arg(QString::fromStdString(Logger::lm_map[lm_]));
}

/*LoggerWorker*/
void LoggerWorker::WriteLog(LoggerObject log)
{
	worksEdit.acquire();
	works.push_front(log);
	worksEdit.release();
	emptyList.release();
}
LoggerWorker::LoggerWorker(QObject *parent): QThread(parent), emptyList(0), worksEdit(1) {
	start();
}
LoggerWorker::~LoggerWorker()
{
	wait();
}
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
void LoggerWorker::isWatingSomethingToStore()
{
	while (emptyList.available() > 0);
}