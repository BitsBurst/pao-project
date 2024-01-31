#include "DataGenObj.h"
/**
 * @brief DataGenObj::DataGenObj
 * @param data data generated
 * @param timestamp timestamp of the data
 */
DataGenObj::DataGenObj(double data, QDateTime timestamp):data_(data), timestamp_(timestamp)
{
}
/**
 * @brief DataGenObj::getTimestamp
 * @return timestamp of the data
 */
QDateTime DataGenObj::getTimestamp() const
{
	return timestamp_;
}
/**
 * @brief DataGenObj::getData
 * @return data generated
 */
double DataGenObj::getData() const
{
	return data_;
}
