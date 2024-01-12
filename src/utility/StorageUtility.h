#ifndef SMARTSENSORS_STORAGEUTILITY_H
#define SMARTSENSORS_STORAGEUTILITY_H
#include <QString>
#include <QFileInfo>
#include <QDir>
#include "../model/core/Sensor.h"
#include "Logger.h"
class StorageUtility {
public:
	template <typename T>
	static bool Store(T*, QString);
	template<typename T>
	static T* Load(QString, T* = nullptr);
};
template <typename T>
bool StorageUtility::Store(T* data, QString filename)
{
	QFileInfo fi(filename);
	QDir dir(fi.absoluteDir().absoluteFilePath("."));
	if (!dir.exists()){
		Logger::Log(LogLevel::INFO,__FILE__,__LINE__,__FUNCTION__,QString("Creating directory %1").arg(dir.absolutePath()));
		dir.mkpath(".");
	}
	QFile file(fi.absoluteFilePath());
	if (file.open(QIODevice::WriteOnly)) {
		QDataStream out(&file);
		out << *data;
		file.waitForBytesWritten(10000);
		return true;
	}
	else {
		Logger::Log(LogLevel::L_ERROR,__FILE__,__LINE__,__FUNCTION__,QString("Couldn't open save file."));
		return false;
	}
}
template <typename T>
T* StorageUtility::Load(QString filename, T* obj )
{
	QFileInfo fi(filename);
	QFile loadFile(fi.absoluteFilePath());
	if (!loadFile.open(QIODevice::ReadOnly)) {
		Logger::Log(LogLevel::L_ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't open saved file."));
		throw std::runtime_error("Couldn't open saved file.");
	}
	QDataStream in(&loadFile);
	if(obj ==nullptr){
		obj = new T();
	}
	in >> *obj;
	loadFile.waitForReadyRead(10000);
	return obj;
}
#endif //SMARTSENSORS_STORAGEUTILITY_H
