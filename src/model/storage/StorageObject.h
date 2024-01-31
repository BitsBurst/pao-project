#ifndef SMARTSENSORS_STORAGEOBJECT_H
#define SMARTSENSORS_STORAGEOBJECT_H

#include "../core/Category.h"
#include "../core/Sensor.h"
#include <QVector>
#include <QJsonArray>
class StorageObject: public QObject {
	Q_OBJECT
private:
	void modelChangedEvent();
	QVector<Category*> categories_;
	QVector<Sensor*> sensors_;
public:
	StorageObject();
	~StorageObject();
	StorageObject(const StorageObject &);
	const QList<Category*>* getCategories() const;
	const QList<Sensor*>* getSensors() const;
	void checkCategories() const;
	void checkSensors() const;
	void addCategory(Category*);
	void addSensor(Sensor*);
	void removeCategory(Category*);
	void removeSensor(Sensor*);
	const Category* findCategory(Category) const;
	const Sensor* findSensor(Sensor) const;
	const QList<Sensor*> filterSensorsByCategory(Category) const;
	const QList<Sensor*> filterSensorsByName(QString name) const;
	const QList<Category*> filterCategoriesByName(QString name) const;
	QJsonObject toJson() const;
	static StorageObject *fromJson(QJsonObject const &);
	EventHandlerVoid onModelChangedEvent;

signals:
	void modelChangedSignal();
};

#endif //SMARTSENSORS_STORAGEOBJECT_H
