#ifndef SMARTSENSORS_BUSINESSCONTROLLER_H
#define SMARTSENSORS_BUSINESSCONTROLLER_H

#include "../storage/core/AbstractController.h"
class BusinessController: public AbstractController {
public:
	BusinessController();
	bool Init();
};

#endif //SMARTSENSORS_BUSINESSCONTROLLER_H
