#include "BaseException.h"
/**
 * @brief BaseException
 * Constructor for the BaseException class.
 */
BaseException::BaseException(): std::exception() {
}
/**
 * @brief BaseException
 * Constructor for the BaseException class.
 * @param str The message of the exception.
 */
BaseException::BaseException(QString str): std::exception(), message(str) {

}
/**
 * @brief getMessage
 * Returns the message of the exception.
 * @return QString
 */
QString BaseException::getMessage() const
{
	return message;
}
/**
 * @brief ~BaseException
 * Destructor for the BaseException class.
 */
BaseException::~BaseException()
= default;
