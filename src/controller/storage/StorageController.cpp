#include "StorageController.h"
#include "../LocatorController.h"
const QString StorageController::directory_name_ = "data";
StorageController::StorageController():storage_(nullptr), worker_(new StorageWorker(&storage_, QString("%1/data.json").arg(directory_name_)))
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	connect(worker_, &StorageWorker::onStorageReady, this, &StorageController::storageReadyEvent);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
bool StorageController::Init()
{
	return true;
}
void StorageController::StoreStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	worker_->SaveStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
void StorageController::modelChanged()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	LocatorController::StorageControllerInstance()->StoreStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
StorageObject* StorageController::GetStorage()
{
	worker_->isStorageInitialized();
	return storage_;
}
void StorageController::Destroy()
{
	worker_->isWatingSomethingToStore();
}
QString StorageController::getDirectory() const
{
	return directory_name_;
}
void StorageController::isStorageReady()
{
	worker_->isStorageInitialized();
}
void StorageController::storageReadyEvent()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
