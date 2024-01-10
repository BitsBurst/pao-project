#include "DataGenObj.h"
DataGenObj::DataGenObj(double data, QDateTime timestamp):data_(data), timestamp_(timestamp)
{
}
QDateTime DataGenObj::getTimestamp()
{
	return timestamp_;
}
double DataGenObj::getData()
{
	return data_;
}
