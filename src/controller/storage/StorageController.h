#ifndef SMARTSENSORS_STORAGECONTROLLER_H
#define SMARTSENSORS_STORAGECONTROLLER_H

#include <QList>
#include "../core/AbstractController.h"
#include "../../model/core/Category.h"
#include "../../model/core/Sensor.h"
#include "../../utility/storage/StorageUtility.h"
#include "../../model/storage/StorageObject.h"
#include "StorageSaveWorker.h"

class StorageController: public AbstractController {
	Q_OBJECT
	friend class StorageSaveWorker;
public:
	StorageController();
	bool Init();
	void Destroy();
	StorageObject* GetStorage();
	QString getDirectory() const;
private:
	static const QString directory_name_;
	StorageObject* storage_;
	StorageSaveWorker* worker_;
	void StoreStorage();
	void reinitializeStorage();
	static void modelChanged();
signals:
	void ErrorLoadingStorage();
};

#endif //SMARTSENSORS_STORAGECONTROLLER_H
