#include "StorageController.h"
#include "../LocatorController.h"
const QString StorageController::directory_name_ = "data";
StorageController::StorageController():storage_(nullptr), worker_(new StorageWorker(&storage_, QString("%1/data.json").arg(directory_name_)))
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	worker_->onStorageReadyEvent.subscribe(std::bind(&StorageController::storageReadyEvent, this));
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
bool StorageController::Init()
{
	return true;
}
void StorageController::StoreStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	worker_->SaveStorage();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
void StorageController::modelChanged()
{
	StoreStorage();
}
StorageObject* StorageController::GetStorage()
{
	isStorageReady();
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
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	storage_->onModelChangedEvent.subscribe(std::bind(&StorageController::modelChanged, this));
	emit StorageReady();
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
