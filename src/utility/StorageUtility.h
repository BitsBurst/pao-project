#ifndef SMARTSENSORS_STORAGEUTILITY_H
#define SMARTSENSORS_STORAGEUTILITY_H
#include <QString>
#include "../model/core/Sensor.h"
class StorageUtility {
public:
	template <typename T>
	static bool Store(T data, QString filename);
	template<typename T>
	static T* Load(QString filename);
};

#endif //SMARTSENSORS_STORAGEUTILITY_H
