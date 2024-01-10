#include "StorageObject.h"
StorageObject::StorageObject(void (*modelChanged)()): modelChanged_(modelChanged), categories_(), sensors_()
{
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
QList<Category>* StorageObject::getCategories()
{
	checkCategories();
	return &categories_;
}
QList<Sensor>* StorageObject::getSensors()
{
	checkSensors();
	return &sensors_;
}
void StorageObject::checkCategories()
{
	if (categories_.size() == 0)
	{
		throw std::invalid_argument("Categories list is empty");
	}
}
void StorageObject::checkSensors()
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
			Category category = Category::fromJson(i.toObject());
			category.setModelChangedPointer(&storage->modelChanged_);
			storage->categories_.append(category);
		}
	}
	if (const QJsonValue& sensors = obj["sensors"]; sensors.isArray()) {
		for (auto i : sensors.toArray()) {
			Sensor sensor = Sensor::fromJson(i.toObject());
			sensor.setModelChangedPointer(&storage->modelChanged_);
			storage->sensors_.append(sensor);
			storage->sensors_.last().startDataGeneration();
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
		categories.append(i.toJson());
	}
	for (auto& i : sensors_) {
		sensors.append(i.toJson());
	}
	json["categories"] = categories;
	json["sensors"] = sensors;
	return json;
}
void StorageObject::setModelChangedPointer(void (*modelChanged)())
{
	modelChanged_ = modelChanged;
}
StorageObject::~StorageObject()
= default;
