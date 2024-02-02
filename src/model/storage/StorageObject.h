#ifndef SMARTSENSORS_STORAGEOBJECT_H
#define SMARTSENSORS_STORAGEOBJECT_H

#include "../core/Category.h"
#include "../core/Sensor.h"
#include <QVector>
#include <QJsonArray>
/*
 * StorageObject
 * This class is used to store all the sensors and categories.
 */
class StorageObject {
private:
	void modelChangedEvent();
	QVector<Category*> categories_;
	QVector<Sensor*> sensors_;
	bool checkCategories() const;
	bool checkSensors() const;
public:
	StorageObject();
	virtual ~StorageObject();
	StorageObject(const StorageObject &);
	const QVector<Category*>* getCategories() const;
	const QVector<Sensor*>* getSensors() const;

	const QVector<AbstractItem*>& getCategories(int) const;
	const QVector<AbstractItem*>& getSensors(int) const;
	Category* getCategory(int index) const;
	void addCategory(Category*);
	void addSensor(Sensor*);
	void removeCategory(Category*);
	void removeSensor(Sensor*);
	const Category* findCategory(Category) const;
	const Sensor* findSensor(Sensor) const;
    QVector<AbstractItem*> filterSensorsByName(const QString& name) const;
    QVector<AbstractItem*> filterCategoriesByName(QString name);
	QJsonObject toJson() const;
	static StorageObject *fromJson(QJsonObject const &);
	EventHandlerVoid onModelChangedEvent;
};

#endif //SMARTSENSORS_STORAGEOBJECT_H
