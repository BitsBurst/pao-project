#ifndef SMARTSENSORS_ABSTRACTCONTROLLER_H
#define SMARTSENSORS_ABSTRACTCONTROLLER_H

class AbstractController {
public:
	~AbstractController();
	virtual bool Init() = 0;
};

#endif //SMARTSENSORS_ABSTRACTCONTROLLER_H
