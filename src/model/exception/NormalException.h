#ifndef SMARTSENSORS_NORMALEXCEPTION_H
#define SMARTSENSORS_NORMALEXCEPTION_H

#include "BaseException.h"
/**
 * @brief NormalException is thrown when a normal error occurs.
 */
class NormalException: public BaseException {
public:
	NormalException(QString);
	virtual ~NormalException();
};

#endif //SMARTSENSORS_NORMALEXCEPTION_H
