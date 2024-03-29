#include "StorageObject.h"
#include "../../utility/logger/Logger.h"

/*
 * @brief StorageObject
 * Constructor
 */
StorageObject::StorageObject(): categories_(), sensors_()
{
}
/*
 * @brief addCategory
 * @param category
 * Adds a category to the storage
 */
void StorageObject::addCategory(Category* category)
{
	categories_.append(category);
	category->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, this));
	modelChangedEvent();
}
/*
 * @brief addSensor
 * @param sensor
 * Adds a sensor to the storage
 */
void StorageObject::addSensor(Sensor* sensor)
{
	sensors_.append(sensor);
	sensor->modelChangedEvent.subscribe(std::bind(&StorageObject::modelChangedEvent, this));
	modelChangedEvent();
}
/*
 * @brief removeCategory
 * @param category
 * Removes a category from the storage
 */
void StorageObject::removeCategory(Category* category)
{
	QMutableListIterator<Category*> i(categories_);
	while (i.hasNext()) {
		if (i.next()->getId() == category->getId()){
			delete i.value();
			i.remove();
		}
	}
	modelChangedEvent();
}
/*
 * @brief removeSensor
 * @param sensor
 * Removes a sensor from the storage
 */
void StorageObject::removeSensor(Sensor* sensor)
{
	QMutableListIterator<Sensor*> i(sensors_);
	while (i.hasNext()) {
		if (i.next()->getId()==sensor->getId()) {
			delete i.value();
			i.remove();
		}
		modelChangedEvent();
	}
}
/*
 * @brief findSensor
 * @param sensor
 * @return
 * Returns a sensor from the storage
 */
const Sensor* StorageObject::findSensor(Sensor sensor) const
{
	for (auto& i : sensors_) {
		if (i->getId() == sensor.getId())
			return i;
	}
	return nullptr;
}
/*
 * @brief findCategory
 * @param category
 * @return
 * Returns a category from the storage
 */
const Category* StorageObject::findCategory(Category category) const
{
	for (auto& i : categories_) {
		if (i->getId() == category.getId())
			return i;
	}
	return nullptr;
}
/*
 * @brief StorageObject
 * @param obj
 * Copy constructor
 */
StorageObject::StorageObject(const StorageObject& obj): categories_(), sensors_()
{
	for (auto& i : obj.categories_) {
		Category* category = new Category(*i);
		categories_.append(category);
	}
	for (auto& i : obj.sensors_) {
		Sensor* sensor = new Sensor(*i);
		sensors_.append(sensor);
	}
}
/*
 * @brief modelChangedEvent
 * Notifies the model changed event
 */
void StorageObject::modelChangedEvent()
{
	onModelChangedEvent.notifyAsync();
}
/*
 * @brief filterSensorsByName
 * @param name
 * @return
 * Returns a list of sensors filtered by name
 */
QVector<AbstractItem*> StorageObject::filterSensorsByName(const QString& name) const
{
    Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, name);
    QVector<AbstractItem*> list;
    for (auto i : sensors_) {

        if (i->getName().toLower().contains(name.toLower()))
            list.push_back(i);
    }
    return list;
}

/*
 * @brief filterCategoriesByName
 * @param name
 * @return
 * Returns a list of categories filtered by name
 */
QVector<AbstractItem*> StorageObject::filterCategoriesByName(QString name)
{
    QVector<AbstractItem*> list;
    for (auto& i : categories_) {
        if (i->getName().toLower().contains(name.toLower()))
            list.append(i);
    }
    return list;
}
/*
 * @brief getCategories
 * @return
 * Returns the categories list
 */
const QVector<Category*>* StorageObject::getCategories() const
{
	checkCategories();
	return &categories_;
}
/*
 * @brief getSensors
 * @return
 * Returns the sensors list
 */
const QVector<Sensor*>* StorageObject::getSensors() const
{
	checkSensors();
	return &sensors_;
}
/*
 * @brief getSensors
 * @return
 * Returns the sensors list as a QVector<AbstractItem*>
 */
const QVector<AbstractItem*> StorageObject::getSensors(int) const
{
	QVector<AbstractItem*> list;
	for (auto& i : sensors_) {
		list.append(i);
	}
	return list;
}

/*
 * @brief getCategories
 * @return
 * Returns the categories list as a QVector<AbstractItem*>
 */
const QVector<AbstractItem*> StorageObject::getCategories(int) const
{
	QVector<AbstractItem*> list;
	for (auto& i : categories_) {
		list.append(i);
	}
	return list;
}
/*
 * @brief checkCategories
 * Checks if the categories list is empty
 * @return true if the categories list is empty, false otherwise
 */
bool StorageObject::checkCategories() const
{
	return categories_.size() != 0;
}
/*
 * @brief checkSensors
 * Checks if the sensors list is empty
 * @return true if the sensors list is empty, false otherwise
 */
bool StorageObject::checkSensors() const
{
	return sensors_.size() != 0;
}
/*
 * @brief fromJson
 * @param obj
 * @return
 * Returns a StorageObject from a QJsonObject
 */
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
		}
	}
	return storage;
}
/*
 * @brief toJson
 * @return
 * Returns a QJsonObject from a StorageObject
 */
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
Category* StorageObject::getCategory(int index) const
{
	if (categories_.isEmpty()) {
		return nullptr;
	}
	return categories_.value(index);
}

/*
 * @brief ~StorageObject
 * Destructor
 */
StorageObject::~StorageObject()
{
	for (auto& i : categories_) {
		delete i;
	}
	for (auto& i : sensors_) {
		delete i;
	}
}