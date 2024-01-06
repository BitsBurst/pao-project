#ifndef SMARTSENSORS_STORAGECONTROLLER_H
#define SMARTSENSORS_STORAGECONTROLLER_H

#include <QList>
#include "../core/AbstractController.h"
#include "../../model/core/Category.h"
#include "../../model/core/Sensor.h"
#include "../../utility/StorageUtility.h"

class StorageController: public AbstractController {
public:
	StorageController();
	bool Init();
private:
	QList<Category> categories_;
	QList<Sensor> sensors_;
};

#endif //SMARTSENSORS_STORAGECONTROLLER_H
