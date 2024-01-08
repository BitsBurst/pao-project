#include "StorageObject.h"
StorageObject::StorageObject(void (*modelChanged)()): modelChanged_(modelChanged), categories_(), sensors_()
{
}
/*QDataStream &operator<<(QDataStream &out, const QList<AbstractItem> &list)
{
	out << list.size();
	for (auto &i : list) {
		const_cast<AbstractItem &>(i).setModelChangedPointer(&AbstractItem::modelChangedStatic_);
		out << i;
	}
	return out;
}
QDataStream &operator>>(QDataStream &in, QList<AbstractItem> &list)
{
	int size;
	in >> size;
	for (int i = 0; i < size; i++) {
		AbstractItem item;
		item.setModelChangedPointer(&AbstractItem::modelChangedStatic_);
		in >> item;
		list.append(item);
	}
	return in;
}*/
QDataStream& operator<<(QDataStream& stream, const StorageObject& obj)
{
	stream << obj.categories_ << obj.sensors_;
	foreach(auto& i, obj.categories_) {
		const_cast<Category&>(i).setModelChangedPointer(&Category::modelChangedStatic_);
	}
	foreach(auto& i, obj.sensors_) {
		const_cast<Sensor&>(i).setModelChangedPointer(&Sensor::modelChangedStatic_);
	}
	return stream;
}
QDataStream& operator>>(QDataStream& stream, StorageObject& obj)
{
	stream >> obj.categories_ >> obj.sensors_;
	return stream;
}
void StorageObject::addCategory(Category* category)
{
	category->setModelChangedPointer(&modelChanged_);
	categories_.append(*category);
	modelChangedEvent();
}
void StorageObject::addSensor(Sensor* sensor)
{
	sensor->setModelChangedPointer(&modelChanged_);
	sensors_.append(*sensor);
	modelChangedEvent();
}
void StorageObject::removeCategory(Category* category)
{
	QMutableListIterator<Category> i(categories_);
	while (i.hasNext()) {
		if (i.next().getId() == category->getId())
			i.remove();
	}
	modelChangedEvent();
}
void StorageObject::removeSensor(Sensor* sensor)
{
	QMutableListIterator<Sensor> i(sensors_);
	while (i.hasNext()) {
		if (i.next().getId() == sensor->getId())
			i.remove();
	}
	modelChangedEvent();
}
Sensor* StorageObject::findSensor(Sensor sensor)
{
	for (auto& i : sensors_) {
		if (i.getId() == sensor.getId())
			return &i;
	}
	return nullptr;
}
Category* StorageObject::findCategory(Category category)
{
	for (auto& i : categories_) {
		if (i.getId() == category.getId())
			return &i;
	}
	return nullptr;
}
StorageObject::StorageObject(const StorageObject& obj): categories_(obj.categories_), sensors_(obj.sensors_)
{
}
void StorageObject::modelChangedEvent()
{
	if (modelChanged_ != nullptr)
	{
		modelChanged_();
	}
}
QList<Sensor> StorageObject::filterSensorsByCategory(Category category)
{
	QList<Sensor> list;
	for (auto& i : sensors_) {
		if (i.getCategory().getId() == category.getId())
			list.append(i);
	}
	return list;
}
QList<Sensor> StorageObject::filterSensorsByName(QString name)
{
	QList<Sensor> list;
	for (auto& i : sensors_) {
		if (i.getName().contains(name))
			list.append(i);
	}
	return list;
}
QList<Category> StorageObject::filterCategoriesByName(QString name)
{
	QList<Category> list;
	for (auto& i : categories_) {
		if (i.getName().contains(name))
			list.append(i);
	}
	return list;
}
StorageObject::~StorageObject()
= default;
