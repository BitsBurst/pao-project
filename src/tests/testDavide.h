#ifndef SMARTSENSORS_TESTDAVIDE_H
#define SMARTSENSORS_TESTDAVIDE_H
#include <QFile>
#include "../model/core/Category.h"
#include "../model/core/Sensor.h"
class TestDavide {
public:
	static void runTest();
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
#endif //SMARTSENSORS_TESTDAVIDE_H
