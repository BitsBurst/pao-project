#include <QFile>
#include "StorageUtility.h"
#include "Logger.h"
template <typename T>
void StorageUtility<T>::Store(T data, QString filename)
{
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly)) {
		QDataStream out(&file);
		out << data;
	}
	else {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't open save file."));
	}
}
template <typename T>
T StorageUtility<T>::Load(QString filename)
{
	QFile loadFile(filename);
	if (!loadFile.open(QIODevice::ReadOnly))
	{
		Logger::Log(LogLevel::ERROR,__FILE__,__LINE__,__FUNCTION__,QString("Couldn't open save file."));
		return;
	}
	QDataStream in(&loadFile);
	T loadDoc;
	in >> loadDoc;
	return loadDoc;
}