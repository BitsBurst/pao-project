#ifndef SMARTSENSORS_FATALEXCEPTION_H
#define SMARTSENSORS_FATALEXCEPTION_H

#include "BaseException.h"
/**
 * @brief FatalException is thrown when a fatal error occurs.
 */
class FatalException: public BaseException {
public:
	FatalException(QString);
	virtual ~FatalException();

};

#endif //SMARTSENSORS_FATALEXCEPTION_H
