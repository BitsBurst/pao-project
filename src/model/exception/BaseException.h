#ifndef SMARTSENSORS_BASEEXCEPTION_H
#define SMARTSENSORS_BASEEXCEPTION_H

#include <exception>
#include <QString>
/**
 * @brief BaseException is the base class for all the exceptions in the project.
 */
class BaseException: public std::exception {
public:
	BaseException();
	BaseException(QString);
	virtual ~BaseException();
	virtual QString getMessage() const;
private:
	QString message;
};

#endif //SMARTSENSORS_BASEEXCEPTION_H
