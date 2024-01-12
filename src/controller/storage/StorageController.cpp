#include "StorageController.h"
#include "../LocatorController.h"
const QString StorageController::directory_name_ = "data";
StorageController::StorageController()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_IN);
	AbstractItem::setModelChangedPointerStatic(&modelChanged);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_OUT);
}
bool StorageController::Init()
{
	LoadStorage();
	return true;
}
void StorageController::LoadStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_IN);
	try {
		storage_ = StorageUtility::Load<StorageObject>(QString("%1/data.dat").arg(StorageController::directory_name_), new StorageObject(&modelChanged));
	}catch (std::runtime_error& e) {
		Logger::Log(LogLevel::L_ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1").arg(e.what()));
		emit ErrorLoadingStorage();
		reinitializeStorage();
	}
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_OUT);
}
void StorageController::StoreStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_IN);
	StorageUtility::Store<StorageObject>(storage_, QString("%1/data.dat").arg(StorageController::directory_name_));
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_OUT);
}
void StorageController::reinitializeStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_IN);
	storage_ = new StorageObject(&modelChanged);
	StoreStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_OUT);
}
void StorageController::modelChanged()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_IN);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Storing Storage");
	qDebug() << "Storing Storage";
	LocatorController::StorageControllerInstance()->StoreStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Storing Storage done");
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::M_OUT);
}
StorageObject* StorageController::GetStorage()
{
	if (storage_ == nullptr)
	{
		Logger::Log(LogLevel::L_ERROR, __FILE__, __LINE__, __FUNCTION__, "Storage not initialized");
		throw std::runtime_error("Storage not initialized");
	}
	return storage_;
}
