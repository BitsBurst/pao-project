#include <QFile>
#include "StorageUtility.h"
#include "Logger.h"
template <typename T>
bool StorageUtility::Store(T data, QString filename)
{
	QFile file(filename);
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
	QFile loadFile(filename);
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