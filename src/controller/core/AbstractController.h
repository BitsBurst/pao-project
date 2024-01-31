#ifndef SMARTSENSORS_ABSTRACTCONTROLLER_H
#define SMARTSENSORS_ABSTRACTCONTROLLER_H

#include <QObject>
/**
 * @brief The AbstractController class
 * @details This class is the base class for all controllers.
 * It provides the basic functionality for all controllers.
 */
class AbstractController : public QObject{
	Q_OBJECT
public:
	~AbstractController();
	virtual bool Init() = 0;
	virtual void Destroy() = 0;
};

#endif //SMARTSENSORS_ABSTRACTCONTROLLER_H
