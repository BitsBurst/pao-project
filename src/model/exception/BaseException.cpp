#include "BaseException.h"
BaseException::BaseException(): std::exception() {
}
BaseException::BaseException(QString str): std::exception(), message(str) {

}
QString BaseException::getMessage() const
{
	return message;
}
BaseException::~BaseException()
= default;
