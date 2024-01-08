#ifndef SMARTSENSORS_BASEEXCEPTION_H
#define SMARTSENSORS_BASEEXCEPTION_H

#include <exception>
#include <QString>
class BaseException: public std::exception {
public:
	BaseException();
	BaseException(QString);
	virtual ~BaseException();
	virtual QString getMessage() const = 0;

};

#endif //SMARTSENSORS_BASEEXCEPTION_H
