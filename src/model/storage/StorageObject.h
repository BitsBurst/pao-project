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
class StorageObject: public QObject {
	Q_OBJECT
private:
	void modelChangedEvent();
	QVector<Category*> categories_;
	QVector<Sensor*> sensors_;
public:
	StorageObject();
	virtual ~StorageObject();
	StorageObject(const StorageObject &);
	const QVector<Category*>* getCategories() const;
	const QVector<Sensor*>* getSensors() const;
	const QVector<AbstractItem*>& getCategories(int) const;
	const QVector<AbstractItem*>& getSensors(int) const;
	bool checkCategories() const;
	bool checkSensors() const;
	void addCategory(Category*);
	void addSensor(Sensor*);
	void removeCategory(Category*);
	void removeSensor(Sensor*);
	const Category* findCategory(Category) const;
	const Sensor* findSensor(Sensor) const;
	const QVector<Sensor*> filterSensorsByCategory(Category) const;
	const QVector<Sensor*> filterSensorsByName(QString name) const;
    QVector<AbstractItem*> filterSensorsByName(const QString& name, int) const;
	const QVector<Category*> filterCategoriesByName(QString name) const;
    QVector<AbstractItem*> filterCategoriesByName(QString name, int);
	QJsonObject toJson() const;
	static StorageObject *fromJson(QJsonObject const &);
	EventHandlerVoid onModelChangedEvent;

signals:
	void modelChangedSignal();
};

#endif //SMARTSENSORS_STORAGEOBJECT_H
