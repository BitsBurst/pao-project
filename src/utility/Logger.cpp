#include "Logger.h"
LogLevel Logger::log_level_ = LogLevel::INFO;
QFile* Logger::log_file_ = nullptr;
QString Logger::log_filename_ = "log.txt";
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
	if(Logger::log_file_->size() > 1000000)
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
	Logger::CheckMaxLogSize();
	if (Logger::log_level_ <= log_level)
	{
		Logger::log_file_->write(QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(message).toUtf8());
		Logger::log_file_->flush();
		Logger::log_file_->waitForBytesWritten(10000);
	}
}
void Logger::Log(LogLevel log_level, QString file, int line, QString methodname, LogMethod lm)
{
	Logger::CheckMaxLogSize();
	if (Logger::log_level_ <= log_level)
	{
		Logger::log_file_->write(QString("%1 | %2 | %3 | %4 | %5 | %6\n").arg(QDateTime::currentDateTime().toString()).arg(QString::fromStdString(ll_map[log_level])).arg(methodname).arg(line).arg(file).arg(QString::fromStdString(lm_map[lm])).toUtf8());
		Logger::log_file_->flush();
		Logger::log_file_->waitForBytesWritten(10000);
	}
}
void Logger::Init(QString log_file_path)
{
	Logger::log_filename_ = log_file_path;
	Logger::log_file_ = new QFile(log_file_path);
	Logger::log_file_->open(QIODevice::WriteOnly | QIODevice::Append);
}
