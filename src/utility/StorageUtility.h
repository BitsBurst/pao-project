#ifndef SMARTSENSORS_STORAGEUTILITY_H
#define SMARTSENSORS_STORAGEUTILITY_H
#include <QString>
template <typename T>
class StorageUtility {
public:
	static void Store(T data, QString filename);
	static T Load(QString filename);
};

#endif //SMARTSENSORS_STORAGEUTILITY_H
