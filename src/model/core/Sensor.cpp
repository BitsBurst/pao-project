#include "Sensor.h"
Sensor::Sensor(QString id, QString name, Category category):AbstractItem(id, name), min_range_(0), max_range_(0), category_(category)
{

}
Sensor::~Sensor()
{

}
double Sensor::getMinRange()
{
	return min_range_;
}
void Sensor::setMinRange(double min_range)
{
	min_range_ = min_range;
	modelChangedHandler();
}
double Sensor::getMaxRange()
{
	return max_range_;
}
void Sensor::setMaxRange(double max_range)
{
	max_range_ = max_range;
	modelChangedHandler();
}
Category Sensor::getCategory()
{
	return category_;
}
void Sensor::setCategory(Category category)
{
	category_ = category;
	modelChangedHandler();
}
QDataStream& operator<<(QDataStream& stream, const Sensor& sensor)
{
	stream << dynamic_cast<const AbstractItem&>(sensor) << sensor.min_range_ << sensor.max_range_ << sensor.category_;
	return stream;
}
QDataStream& operator>>(QDataStream& stream, Sensor& sensor)
{
	stream >> dynamic_cast<AbstractItem&>(sensor) >> sensor.min_range_ >> sensor.max_range_ >> sensor.category_;
	return stream;
}
Sensor::Sensor(): AbstractItem("", ""), min_range_(0), max_range_(0), category_(Category())
{

}
