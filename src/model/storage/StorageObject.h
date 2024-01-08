#ifndef SMARTSENSORS_STORAGEOBJECT_H
#define SMARTSENSORS_STORAGEOBJECT_H

#include "../core/Category.h"
#include "../core/Sensor.h"
class StorageObject: public QObject {
	Q_OBJECT
	friend QDataStream &operator<<(QDataStream &, const StorageObject &);
	friend QDataStream &operator>>(QDataStream &, StorageObject &);
private:
	void (*modelChanged_)();

	void modelChangedEvent();
public:
	// to be privatized
	QList<Category> categories_;
	QList<Sensor> sensors_;
	// to be privatized
	StorageObject(void (*)() = nullptr);
	~StorageObject();
	StorageObject(const StorageObject &);
	void addCategory(Category*);
	void addSensor(Sensor*);
	void removeCategory(Category*);
	void removeSensor(Sensor*);
	Category* findCategory(Category);
	Sensor* findSensor(Sensor);
	QList<Sensor> filterSensorsByCategory(Category);
	QList<Sensor> filterSensorsByName(QString name);
QList<Category> filterCategoriesByName(QString name);
signals:
	void modelChangedSignal();
};
QDataStream &operator<<(QDataStream &, const StorageObject&);
QDataStream &operator>>(QDataStream &, StorageObject &);

#endif //SMARTSENSORS_STORAGEOBJECT_H
