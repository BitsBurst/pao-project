#ifndef SMARTSENSORS_STORAGECONTROLLER_H
#define SMARTSENSORS_STORAGECONTROLLER_H

#include "core/AbstractController.h"
class StorageController: public AbstractController {
public:
	StorageController();
	bool Init();
};

#endif //SMARTSENSORS_STORAGECONTROLLER_H
