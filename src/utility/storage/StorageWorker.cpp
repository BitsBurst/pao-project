#include "StorageWorker.h"
#include "StorageUtility.h"
#include "../../controller/storage/StorageController.h"
#include "../../controller/LocatorController.h"
void StorageWorker::SaveStorage()
{
	if(closing)
		return;
	lastUpdate = QDateTime::currentDateTime();
	changed = true;
}
StorageWorker::StorageWorker(StorageObject** pp, QString filename, QObject *parent) :QThread(parent), storagePointer(pp), changed(false), lastUpdate(QDateTime::currentDateTime()), filename_(filename), writingMutex(), storageInitialized(false), closing(false) {
	start();
}
StorageWorker::~StorageWorker()
{
	wait();
}
void StorageWorker::run() {
	Load();
	if(*storagePointer == nullptr){
		*storagePointer = new StorageObject();
		Store();
	}
	onStorageReadyEvent.notifyAsync();
	storageInitialized = true;
	while(true) {
		while (!changed);
		writingMutex.lock();
		changed = false;
		QDateTime currentDateTime = lastUpdate;
		int diff = 0;
		int wait = 0;
		while (diff = lastUpdate.msecsTo(currentDateTime) < 250) {
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
void StorageWorker::isWatingSomethingToStore()
{
	closing = true;
	while (changed);
	writingMutex.lock();
	writingMutex.unlock();
}
void StorageWorker::isStorageInitialized()
{
	while (!storageInitialized);
}
void StorageWorker::Store()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	try {
		StorageObject storage = **storagePointer;
		StorageUtility::StoreJSON(storage.toJson(), filename_);
		qDebug() << "Storage stored";
	} catch (std::exception& e) {
		qDebug() << "Couldn't store storage";
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1").arg(e.what()));
	}
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
void StorageWorker::Load()
{
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_IN_);
	try {
		QJsonObject obj = StorageUtility::LoadJSON(filename_);
		*storagePointer = StorageObject::fromJson(obj);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::_ERROR_, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1").arg(e.what()));
	}
	Logger::Log(LogLevel::_INFO_, __FILE__, __LINE__, __FUNCTION__, LogMethod::_OUT_);
}
