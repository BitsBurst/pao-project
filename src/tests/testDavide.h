#ifndef SMARTSENSORS_TESTDAVIDE_H
#define SMARTSENSORS_TESTDAVIDE_H
#include <QFile>
#include <QUuid>
#include <QJsonDocument>
#include "../model/core/Category.h"
#include "../model/core/Sensor.h"
#include "../utility/storage/StorageUtility.h"
#include "../model/storage/StorageObject.h"
#include "../controller/LocatorController.h"
/*
 * TestDavide
 * This class is used to test the application features.
 */
class TestDavide {
public:
	static void runTest();
	static void runTestV2();
	static void runTestV3();
	static void runTestV4();
	static void runTestV5();
	static void runTestV6();
};
void TestDavide::runTest()
{

}
void TestDavide::runTestV2()
{
}
void TestDavide::runTestV3()
{
}
void TestDavide::runTestV4()
{
}
void TestDavide::runTestV5()
{
}
void addSensors()
{
	Category* category = new Category("Category " + QString::number(1), "Unit measure " + QString::number(1));
	Sensor* sensor = new Sensor("Sensor " + QString::number(1), *category);
	for (int i = 0; i < 100000; i++) {
	LocatorController::StorageControllerInstance()->GetStorage()->addSensor(sensor);
	}
}
void TestDavide::runTestV6()
{
	//addSensors();
	qDebug() << "Storage size: " << LocatorController::StorageControllerInstance()->GetStorage()->getSensors()->size();
}
#endif //SMARTSENSORS_TESTDAVIDE_H
