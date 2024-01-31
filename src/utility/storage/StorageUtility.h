#ifndef SMARTSENSORS_STORAGEUTILITY_H
#define SMARTSENSORS_STORAGEUTILITY_H
#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QJsonDocument>
#include "../../model/core/Sensor.h"
#include "../logger/Logger.h"
/*
 * @brief StorageUtility
 * This class is used to store and load JSON files
 */
class StorageUtility {
public:
	static bool StoreJSON(QJsonObject, QString);
	static QJsonObject LoadJSON(QString);
};

#endif //SMARTSENSORS_STORAGEUTILITY_H
