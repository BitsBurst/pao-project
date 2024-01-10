#ifndef SMARTSENSORS_STORAGECONTROLLER_H
#define SMARTSENSORS_STORAGECONTROLLER_H

#include <QList>
#include "../core/AbstractController.h"
#include "../../model/core/Category.h"
#include "../../model/core/Sensor.h"
#include "../../utility/storage/StorageUtility.h"
#include "../../model/storage/StorageObject.h"
#include "../../utility/storage/StorageWorker.h"

class StorageController: public AbstractController {
	Q_OBJECT
	friend class StorageWorker;
public:
	StorageController();
	bool Init();
	void Destroy();
	StorageObject* GetStorage();
	QString getDirectory() const;
	void isStorageReady();
private:
	static const QString directory_name_;
	StorageObject* storage_;
	StorageWorker* worker_;
	void StoreStorage();
	static void modelChanged();
	void storageReadyEvent();
signals:
	void StorageReady();
};

#endif //SMARTSENSORS_STORAGECONTROLLER_H
