#ifndef SMARTSENSORS_STORAGEOBJECT_H
#define SMARTSENSORS_STORAGEOBJECT_H

#include "../core/Category.h"
#include "../core/Sensor.h"
class StorageObject: public QObject {
	Q_OBJECT
	friend QDataStream &operator<<(QDataStream &, const StorageObject &);
	friend QDataStream &operator>>(QDataStream &, StorageObject &);
private:

public:
	QList<Category> categories_;
	QList<Sensor> sensors_;
	StorageObject();
	~StorageObject();
	StorageObject(const StorageObject &);
	void addCategory(Category);
	void addSensor(Sensor);
	void removeCategory(Category);
	void removeSensor(Sensor);
	void findCategory(QString);
	void findSensor(QString);
	QList<Sensor> filterSensorsByCategory(Category);
};
QDataStream &operator<<(QDataStream &, const StorageObject&);
QDataStream &operator>>(QDataStream &, StorageObject &);

#endif //SMARTSENSORS_STORAGEOBJECT_H
