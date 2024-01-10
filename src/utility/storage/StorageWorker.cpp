#include "StorageWorker.h"
#include "StorageUtility.h"
#include "../../controller/storage/StorageController.h"
#include "../../controller/LocatorController.h"
void StorageWorker::SaveStorage()
{
	lastUpdate = QDateTime::currentDateTime();
	changed = true;
}
StorageWorker::StorageWorker(StorageObject** pp, QString filename, QObject *parent) :QThread(parent), storagePointer(pp), changed(false), lastUpdate(QDateTime::currentDateTime()), filename_(filename), writingMutex() {
	start();
}
StorageWorker::~StorageWorker()
{
	wait();
}
void StorageWorker::run() {
	Load();
	if(*storagePointer == nullptr){
		*storagePointer = new StorageObject(&StorageController::modelChanged);
		Store();
	}
	emit onStorageReady();
	while(true) {
		while (!changed);
		writingMutex.lock();
		changed = false;
		QDateTime currentDateTime = QDateTime::currentDateTime();
		int diff = 0;
		int wait = 0;
		while (diff = lastUpdate.msecsTo(currentDateTime) < 1000) {
			wait += diff;
			if (wait > 5000) {
				break;
			}
			qDebug() << "Waiting for " << wait << "ms";
			currentDateTime = QDateTime::currentDateTime();
		}
		Store();
		writingMutex.unlock();
	}
}
void StorageWorker::isWatingSomethingToStore()
{
	while (changed);
	writingMutex.lock();
	writingMutex.unlock();
}
void StorageWorker::isStorageInitialized()
{
	while(*storagePointer == nullptr);
}
void StorageWorker::Store()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	try {
		StorageUtility::StoreJSON((*storagePointer)->toJson(), filename_);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1").arg(e.what()));
	}
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
void StorageWorker::Load()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	try {
		QJsonObject obj = StorageUtility::LoadJSON(filename_);
		*storagePointer = StorageObject::fromJson(obj);
		(**storagePointer).setModelChangedPointer(&StorageController::modelChanged);
	} catch (std::exception& e) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1").arg(e.what()));
	}
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
