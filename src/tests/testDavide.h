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
	Category* category = new Category("Temperature", "Celsius", nullptr);
	Category* category2 = new Category("Temperature", "Celsius", nullptr);
	StorageObject* storeObject = new StorageObject();
	storeObject->addCategory(category);
	storeObject->addCategory(category2);
	//qDebug() << storeObject->getCategories()->size();
	storeObject->removeCategory(category2);
	//qDebug() << storeObject->getCategories()->size();
	//qDebug() << storeObject->getCategories()->front().getId();
}
void ChangedModel()
{
	qDebug() << "Model changed";
}
void TestDavide::runTestV3()
{
	void (*f)() = &ChangedModel;
	Category* category = new Category("Temperature", "Celsius", nullptr, &f);
	category->setUnitMeasure("Temperatura");
	category->setId("Temperatura");
}
void TestDavide::runTestV4()
{
	Category* category = new Category("Temperature", "Celsius", nullptr);
	LocatorController::StorageControllerInstance()->GetStorage()->addCategory(category);
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->size();
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().getId();
	LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().setId("1"+LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().getId());
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().getId();

}
void TestDavide::runTestV5()
{
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->size();
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().getId();
	LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().setId("1"+LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().getId());
}
void TestDavide::runTestV6()
{
	qDebug() << "runTestV6";
	//qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->size();
	Category* category = new Category("Temperature", "Celsius", nullptr);
	for(int i = 0; i<100000; i++)
	{
		//Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, QString("i: %1").arg(i));
		LocatorController::StorageControllerInstance()->GetStorage()->addCategory(category);
		//LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front().setId("1");
	}
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->size();
	//LocatorController::StorageControllerInstance()->GetStorage()->getCategories()->front();
}
#endif //SMARTSENSORS_TESTDAVIDE_H
