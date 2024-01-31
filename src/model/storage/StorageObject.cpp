#include "StorageObject.h"
StorageObject::StorageObject(): categories_(), sensors_()
{
}
void StorageObject::addCategory(Category* category)
{
	categories_.append(category);
	category->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, this));
	modelChangedEvent();
}
void StorageObject::addSensor(Sensor* sensor)
{
	sensors_.append(sensor);
	sensor->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, this));
	//sensor->startDataGeneration();
	modelChangedEvent();
}
void StorageObject::removeCategory(Category* category)
{
	QMutableListIterator<Category*> i(categories_);
	while (i.hasNext()) {
		if (i.next()->getId() == category->getId())
			i.remove();
	}
	modelChangedEvent();
}
void StorageObject::removeSensor(Sensor* sensor)
{
	QMutableListIterator<Sensor*> i(sensors_);
	while (i.hasNext()) {
		if (i.next()->getId() == sensor->getId())
			i.remove();
	}
	modelChangedEvent();
}
const Sensor* StorageObject::findSensor(Sensor sensor) const
{
	for (auto& i : sensors_) {
		if (i->getId() == sensor.getId())
			return i;
	}
	return nullptr;
}
const Category* StorageObject::findCategory(Category category) const
{
	for (auto& i : categories_) {
		if (i->getId() == category.getId())
			return i;
	}
	return nullptr;
}
StorageObject::StorageObject(const StorageObject& obj): categories_(obj.categories_), sensors_(obj.sensors_)
{
}
void StorageObject::modelChangedEvent()
{
	onModelChangedEvent.notifyAsync();
}
const QList<Sensor*> StorageObject::filterSensorsByCategory(Category category) const
{
	QList<Sensor*> list;
	for (auto& i : sensors_) {
		if (i->getCategory().getId() == category.getId())
			list.append(i);
	}
	return list;
}
const QList<Sensor*> StorageObject::filterSensorsByName(QString name) const
{
	QList<Sensor*> list;
	for (auto& i : sensors_) {
		if (i->getName().contains(name))
			list.append(i);
	}
	return list;
}
const QList<Category*> StorageObject::filterCategoriesByName(QString name) const
{
	QList<Category*> list;
	for (auto& i : categories_) {
		if (i->getName().contains(name))
			list.append(i);
	}
	return list;
}
const QVector<Category*>* StorageObject::getCategories() const
{
	checkCategories();
	return &categories_;
}
const QVector<Sensor*>* StorageObject::getSensors() const
{
	checkSensors();
	return &sensors_;
}
void StorageObject::checkCategories() const
{
	if (categories_.size() == 0)
	{
		throw std::invalid_argument("Categories list is empty");
	}
}
void StorageObject::checkSensors() const
{
	if (sensors_.size() == 0)
	{
		throw std::invalid_argument("Sensors list is empty");
	}
}
StorageObject *StorageObject::fromJson(const QJsonObject& obj)
{
	StorageObject * storage = new StorageObject();
	if (const QJsonValue& categories = obj["categories"]; categories.isArray()) {
		for (auto i : categories.toArray()) {
			Category* category = Category::fromJson(i.toObject());
			category->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, storage));
			storage->categories_.push_front(category);
		}
	}
	if (const QJsonValue& sensors = obj["sensors"]; sensors.isArray()) {
		for (auto i : sensors.toArray()) {
			Sensor* sensor = Sensor::fromJson(i.toObject());
			sensor->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, storage));
			storage->sensors_.push_front(sensor);
			//sensor->startDataGeneration();
		}
	}
	return storage;
}
QJsonObject StorageObject::toJson() const
{
	QJsonObject json;
	QJsonArray categories;
	QJsonArray sensors;
	for (auto& i : categories_) {
		categories.append(i->toJson());
	}
	for (auto& i : sensors_) {
		sensors.append(i->toJson());
	}
	json["categories"] = categories;
	json["sensors"] = sensors;
	return json;
}
StorageObject::~StorageObject()
= default;
