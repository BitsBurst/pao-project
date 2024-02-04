#include "StorageWorker.h"
#include "StorageUtility.h"
#include "../../controller/storage/StorageController.h"
#include "../../controller/LocatorController.h"
/**
 * @brief StorageWorker::SaveStorage
 * @details This method is called when the storage is changed and it's time to save it.
 * @note This method is called by the StorageController.
 */
void StorageWorker::SaveStorage()
{
	if(closing)
		return;
	lastUpdate = QDateTime::currentDateTime();
	changed = true;
}
/**
 * @brief StorageWorker::StorageWorker
 * @details This is the constructor of the StorageWorker. It initializes the storagePointer and the filename.
 * @param pp pointer to the storage
 * @param filename filename of the storage
 * @param parent parent of the StorageWorker
 */
StorageWorker::StorageWorker(StorageObject** pp, QString filename, QObject *parent) :QThread(parent), storagePointer(pp), changed(false), destroy(false), lastUpdate(QDateTime::currentDateTime()), filename_(filename), writingMutex(), storageInitialized(false), closing(false) {
}
/**
 * @brief StorageWorker::~StorageWorker
 * @details This is the destructor of the StorageWorker. It waits for the storage to be saved and then it destroys the StorageWorker.
 */
StorageWorker::~StorageWorker()
{
	destroy = true;
	wait();
}
/**
 * @brief StorageWorker::run
 * @details This method is the main method of the StorageWorker. It waits for the storage to be changed and then it saves it.
 */
void StorageWorker::run() {
	Load();
	if(*storagePointer == nullptr){
		*storagePointer = new StorageObject();
		Store();
	}
	onStorageReadyEvent.notifyAsync();
	storageInitialized = true;
	while(!destroy) {
		while (!changed && !destroy){
			msleep(10);
		}
		writingMutex.lock();
		changed = false;
		QDateTime currentDateTime = lastUpdate;
		int diff = 0;
		int wait = 0;
		while ((diff = lastUpdate.msecsTo(currentDateTime)) < 250) {
			wait += diff;
			if (wait > 5000) {
				break;
			}
			currentDateTime = QDateTime::currentDateTime();
		}
		Store();
		writingMutex.unlock();
	}
}
/**
 * @brief StorageWorker::isWatingSomethingToStore
 * @details This method is called when the application is closing. It waits for the storage to be saved.
 */
void StorageWorker::isWatingSomethingToStore()
{
	closing = true;
	while (changed);
	writingMutex.lock();
	writingMutex.unlock();
}
/**
 * @brief StorageWorker::isStorageInitialized
 * @details This method is called when the application is starting. It waits for the storage to be loaded.
 */
void StorageWorker::isStorageInitialized()
{
	while (!storageInitialized);
}
/*
 * @brief StorageWorker::iSstorageReady
 * @return true if the storage is ready, false otherwise
 */
bool StorageWorker::isStorageReady()
{
	return storageInitialized;
}
/**
 * @brief StorageWorker::Store
 * @details This method saves the storage.
 */
void StorageWorker::Store()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	try {
		StorageObject storage = **storagePointer;
		StorageUtility::StoreJSON(storage.toJson(), filename_);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1 %2").arg(filename_).arg(e.what()));
	}
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
/**
 * @brief StorageWorker::Load
 * @details This method loads the storage.
 */
void StorageWorker::Load()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	try {
		QJsonObject obj = StorageUtility::LoadJSON(filename_);
		*storagePointer = StorageObject::fromJson(obj);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1 %2").arg(filename_).arg(e.what()));
	}
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
