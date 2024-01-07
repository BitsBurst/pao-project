#ifndef SMARTSENSORS_TESTDAVIDE_H
#define SMARTSENSORS_TESTDAVIDE_H
#include <QFile>
#include "../model/core/Category.h"
#include "../model/core/Sensor.h"
#include "../utility/StorageUtility.h"
#include "../model/storage/StorageObject.h"
class TestDavide {
public:
	static void runTest();
	static void runTestV2();
};
void TestDavide::runTest()
{
	QFile file("file.dat");
	file.remove();
	Category* category = new Category("1", "Temperature", "Celsius", nullptr);
	Sensor* sensor = new Sensor("2", "Cucina", *category);
	{
		QFile file("file.dat");
		file.open(QIODevice::WriteOnly);
		QDataStream out(&file);
		out << *sensor;
		qDebug() << "ok";
	}
	{
		QFile file("file.dat");
		file.open(QIODevice::ReadOnly);
		QDataStream in(&file);
		Category category2;
		Sensor sensor2;
		qDebug() << "before";
		in >> sensor2;
		qDebug() << "after";
		qDebug() << sensor2.getId();
		qDebug() << sensor2.getName();
		category2 = sensor2.getCategory();
		qDebug() << category2.getId();
		qDebug() << category2.getName();
		qDebug() << category2.getUnitMeasure();
	}
}
void TestDavide::runTestV2()
{
	Category* category = new Category("1", "Temperature", "Celsius", nullptr);
	Category* category2 = new Category("2", "Temperature", "Celsius", nullptr);
	StorageObject* storeObject = new StorageObject();
	storeObject->addCategory(*category);
	storeObject->addCategory(*category2);
	StorageUtility::Store<StorageObject>(*storeObject, "data/testData.dat");
	qDebug() << storeObject->categories_.size();
	storeObject->removeCategory(*category2);
	qDebug() << storeObject->categories_.size();
	qDebug() << storeObject->categories_.front().getId();
}
#endif //SMARTSENSORS_TESTDAVIDE_H
