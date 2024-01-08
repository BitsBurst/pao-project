#ifndef SMARTSENSORS_ABSTRACTCONTROLLER_H
#define SMARTSENSORS_ABSTRACTCONTROLLER_H

#include <QObject>
class AbstractController : public QObject{
	Q_OBJECT
public:
	~AbstractController();
	virtual bool Init() = 0;
};

#endif //SMARTSENSORS_ABSTRACTCONTROLLER_H
