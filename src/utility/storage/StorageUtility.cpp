#include "StorageUtility.h"
bool StorageUtility::StoreJSON(QJsonObject obj, QString filename)
{
	QFileInfo fi(filename);
	QDir dir(fi.absoluteDir().absoluteFilePath("."));
	if (!dir.exists()){
		Logger::Log(LogLevel::_INFO_,__FILE__,__LINE__,__FUNCTION__,QString("Creating directory %1").arg(dir.absolutePath()));
		dir.mkpath(".");
	}
	QFile file(fi.absoluteFilePath());
	if (file.open(QIODevice::WriteOnly)) {
		QJsonDocument doc(obj);
		file.write(doc.toJson());
		file.flush();
		file.close();
		return true;
	}
	else {
		Logger::Log(LogLevel::_ERROR_,__FILE__,__LINE__,__FUNCTION__,QString("Couldn't open save file."));
		return false;
	}
}
QJsonObject StorageUtility::LoadJSON(QString filename)
{
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly)) {
		Logger::Log(LogLevel::_ERROR_,__FILE__,__LINE__,__FUNCTION__,QString("Couldn't open saved file."));
		throw std::runtime_error("Couldn't open saved file.");
	}
	QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
	return doc.object();
}