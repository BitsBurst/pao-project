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
	static bool Store(T data, QString filename);
	template<typename T>
	static T* Load(QString filename);
};
template <typename T>
bool StorageUtility::Store(T data, QString filename)
{
	QFileInfo fi(filename);
	QDir dir(fi.absoluteDir().absoluteFilePath("."));
	if (!dir.exists())
		dir.mkpath(".");
	QFile file(fi.absoluteFilePath());
	if (file.open(QIODevice::WriteOnly)) {
		QDataStream out(&file);
		out << data;
		return true;
	}
	else {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't open save file."));
		return false;
	}
}
template <typename T>
T* StorageUtility::Load(QString filename)
{
	QFileInfo fi(filename);
	QFile loadFile(fi.absoluteFilePath());
	if (!loadFile.open(QIODevice::ReadOnly))
	{
		Logger::Log(LogLevel::ERROR,__FILE__,__LINE__,__FUNCTION__,QString("Couldn't open save file."));
		return nullptr;
	}
	QDataStream in(&loadFile);
	T* loadDoc = new T();
	in >> *loadDoc;
	return loadDoc;
}
#endif //SMARTSENSORS_STORAGEUTILITY_H
