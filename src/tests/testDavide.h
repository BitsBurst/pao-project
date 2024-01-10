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
class TestDavide {
public:
	static void runTest();
	static void runTestV2();
	static void runTestV3();
	static void runTestV4();
	static void runTestV5();
	static  void runTestV6();
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
void DataGenerated()
{
	qDebug() << "Data generated";
}
void TestDavide::runTestV6()
{
	Category c1("c1", "c1");
	Sensor* s1 = new Sensor("s1", c1);
	s1->setMinRange(0);
	s1->setMaxRange(100);
	//LocatorController::StorageControllerInstance()->GetStorage()->addSensor(s1);
}
#endif //SMARTSENSORS_TESTDAVIDE_H
