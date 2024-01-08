#include "StorageObject.h"
StorageObject::StorageObject(): categories_(), sensors_()
{
	modelChanged = &modelChangedEvent;
}
QDataStream& operator<<(QDataStream& stream, const StorageObject& obj)
{
	stream << obj.categories_ << obj.sensors_;
	return stream;
}
QDataStream& operator>>(QDataStream& stream, StorageObject& obj)
{
	stream >> obj.categories_ >> obj.sensors_;
	return stream;
}
void StorageObject::addCategory(Category category)
{
	category.setModelChangedPointer(&modelChanged);
	categories_.append(category);
}
void StorageObject::addSensor(Sensor sensor)
{
	sensor.setModelChangedPointer(&modelChanged);
	sensors_.append(sensor);
}
void StorageObject::removeCategory(Category category)
{
	QMutableListIterator<Category> i(categories_);
	while (i.hasNext()) {
		if (i.next().getId() == category.getId())
			i.remove();
	}
}
void StorageObject::removeSensor(Sensor sensor)
{
	QMutableListIterator<Sensor> i(sensors_);
	while (i.hasNext()) {
		if (i.next().getId() == sensor.getId())
			i.remove();
	}
}
StorageObject::StorageObject(const StorageObject& obj): categories_(obj.categories_), sensors_(obj.sensors_)
{
}
void StorageObject::modelChangedEvent()
{

}
StorageObject::~StorageObject()
= default;
