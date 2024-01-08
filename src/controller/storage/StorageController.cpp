#include "StorageController.h"
#include "../LocatorController.h"
const QString StorageController::directory_name_ = "data";
StorageController::StorageController()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	AbstractItem::setModelChangedPointerStatic(&modelChanged);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
bool StorageController::Init()
{
	LoadStorage();
	return true;
}
void StorageController::LoadStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	try {
		storage_ = StorageUtility::Load<StorageObject>(QString("%1/data.dat").arg(StorageController::directory_name_));
	}catch (std::runtime_error& e) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1").arg(e.what()));
		emit ErrorLoadingStorage();
		reinitializeStorage();
	}
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
void StorageController::StoreStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	StorageUtility::Store<StorageObject>(*storage_, QString("%1/data.dat").arg(StorageController::directory_name_));
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
void StorageController::reinitializeStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	storage_ = new StorageObject();
	StoreStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
void StorageController::modelChanged()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Storing Storage");
	LocatorController::StorageControllerInstance()->StoreStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, "Storing Storage done");
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
StorageObject* StorageController::GetStorage()
{
	if (storage_ == nullptr)
	{
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, "Storage not initialized");
		throw std::runtime_error("Storage not initialized");
	}
	return storage_;
}
