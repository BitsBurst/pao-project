#include "StorageController.h"
#include "../LocatorController.h"
const QString StorageController::directory_name_ = "data"; // folder name where the data will be stored
/**
 * @brief StorageController::StorageController
 * Constructor
 */
StorageController::StorageController():storage_(nullptr), worker_(new StorageWorker(&storage_, QString("%1/data.json").arg(directory_name_)))
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	worker_->onStorageReadyEvent.subscribe(std::bind(&StorageController::storageReadyEvent, this));
	worker_->start();
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
/**
 * @brief StorageController::Init
 * @return true if the storage is ready, false otherwise
 */
bool StorageController::Init()
{
	return true;
}
/**
 * @brief StorageController::StoreStorage
 * Store the storage
 */
void StorageController::StoreStorage()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	worker_->SaveStorage();
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
/**
 * @brief StorageController::modelChanged
 * When the model is changed, the storage is stored
 */
void StorageController::modelChanged()
{
	StoreStorage();
}
/**
 * @brief StorageController::GetStorage
 * @return the storage
 */
StorageObject* StorageController::GetStorage()
{
	isStorageReady();
	return storage_;
}
/**
 * @brief StorageController::Destroy
 * Destroy the storage
 */
void StorageController::Destroy()
{
	worker_->isWatingSomethingToStore();
}
/**
 * @brief StorageController::getDirectory
 * @return the directory where the data is stored
 */
QString StorageController::getDirectory() const
{
	return directory_name_;
}
/**
 * @brief StorageController::isStorageReady
 * Check if the storage is ready
 */
void StorageController::isStorageReady()
{
	worker_->isStorageInitialized();
}
/**
 * @brief StorageController::isStorageReady
 * @return true if the storage is ready, false otherwise
 */
bool StorageController::isStorageReadyCheck()
{
	return worker_->isStorageReady();
}
/**
 * @brief StorageController::storageReadyEvent
 * When the storage is ready, emit the signal
 */
void StorageController::storageReadyEvent()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	storage_->onModelChangedEvent.subscribe(std::bind(&StorageController::modelChanged, this));
	emit StorageReady();
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
/**
 * @brief StorageController::changeStorageFile
 * Change the storage file
 * @param filename
 */
void StorageController::changeStorageFile(QString filename)
{
	try {
		worker_->onStorageReadyEvent.unsubscribe(std::bind(&StorageController::storageReadyEvent, this));
		storage_->onModelChangedEvent.unsubscribe(std::bind(&StorageController::modelChanged, this));
		delete worker_;
		worker_ = nullptr;
		beforeDestroy.notify();
		delete storage_;
		storage_ = nullptr;
		worker_ = new StorageWorker(&storage_, QString(filename));
		worker_->onStorageReadyEvent.subscribe(std::bind(&StorageController::storageReadyEvent, this));
		worker_->start();
	}catch (...) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, "Couldn't change storage file");
	}
}

void StorageController::saveStorageByName(QString filename)
{
	try {
		StorageObject storage = *storage_;
		StorageUtility::StoreJSON(storage.toJson(), filename);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1").arg(e.what()));
	}
}