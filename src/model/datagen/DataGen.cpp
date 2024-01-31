#include "DataGenObj.h"
DataGenObj::DataGenObj(double data, QDateTime timestamp):data_(data), timestamp_(timestamp)
{
}
QDateTime DataGenObj::getTimestamp() const
{
	return timestamp_;
}
double DataGenObj::getData() const
{
	return data_;
}
