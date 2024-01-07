#ifndef SMARTSENSORS_STORAGECONTROLLER_H
#define SMARTSENSORS_STORAGECONTROLLER_H

#include <QList>
#include "../core/AbstractController.h"
#include "../../model/core/Category.h"
#include "../../model/core/Sensor.h"
#include "../../utility/StorageUtility.h"
#include "../../model/storage/StorageObject.h"

class StorageController: public AbstractController {
	Q_OBJECT
public:
	StorageController();
	bool Init();
private:
	static const QString directory_name_;
	StorageObject* storage_;
	void LoadStorage();
	void StoreStorage();
	void reinitializeStorage();
signals:
	void ErrorLoadingStorage();
};

#endif //SMARTSENSORS_STORAGECONTROLLER_H
