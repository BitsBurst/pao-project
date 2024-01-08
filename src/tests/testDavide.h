#ifndef SMARTSENSORS_TESTDAVIDE_H
#define SMARTSENSORS_TESTDAVIDE_H
#include <QFile>
#include "../model/core/Category.h"
#include "../model/core/Sensor.h"
#include "../utility/StorageUtility.h"
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
	storeObject->addCategory(category);
	storeObject->addCategory(category2);
	StorageUtility::Store<StorageObject>(storeObject, "data/testData.dat");
	//qDebug() << storeObject->categories_.size();
	storeObject->removeCategory(category2);
	//qDebug() << storeObject->categories_.size();
	//qDebug() << storeObject->categories_.front().getId();
}
void ChangedModel()
{
	qDebug() << "Model changed";
}
void TestDavide::runTestV3()
{
	void (*f)() = &ChangedModel;
	Category* category = new Category("1", "Temperature", "Celsius", nullptr, &f);
	category->setUnitMeasure("Temperatura");
	category->setId("Temperatura");
}
void TestDavide::runTestV4()
{
	Category* category = new Category("1", "Temperature", "Celsius", nullptr);
	LocatorController::StorageControllerInstance()->GetStorage()->addCategory(category);
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->categories_.size();
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().getId();
	LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().setId("1"+LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().getId());
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().getId();
}
void TestDavide::runTestV5()
{
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->categories_.size();
	qDebug() << LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().getId();
	LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().setId("1"+LocatorController::StorageControllerInstance()->GetStorage()->categories_.front().getId());
}
void TestDavide::runTestV6()
{

}
#endif //SMARTSENSORS_TESTDAVIDE_H
