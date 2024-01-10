#ifndef SMARTSENSORS_STORAGEOBJECT_H
#define SMARTSENSORS_STORAGEOBJECT_H

#include "../core/Category.h"
#include "../core/Sensor.h"
#include <QVector>
#include <QJsonArray>
class StorageObject: public QObject {
	Q_OBJECT
private:
	void (*modelChanged_)();
	void modelChangedEvent();
	QVector<Category> categories_;
	QVector<Sensor> sensors_;
public:
	StorageObject(void (*)() = nullptr);
	~StorageObject();
	StorageObject(const StorageObject &);
	QList<Category>* getCategories();
	QList<Sensor>* getSensors();
	void checkCategories();
	void checkSensors();
	void addCategory(Category*);
	void addSensor(Sensor*);
	void removeCategory(Category*);
	void removeSensor(Sensor*);
	Category* findCategory(Category);
	Sensor* findSensor(Sensor);
	QList<Sensor> filterSensorsByCategory(Category);
	QList<Sensor> filterSensorsByName(QString name);
	QList<Category> filterCategoriesByName(QString name);
	QJsonObject toJson() const;
	static StorageObject *fromJson(QJsonObject const &);
	void setModelChangedPointer(void (*)());
signals:
	void modelChangedSignal();
};

#endif //SMARTSENSORS_STORAGEOBJECT_H
