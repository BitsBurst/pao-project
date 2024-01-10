#include "StorageSaveWorker.h"
#include "../../utility/storage/StorageUtility.h"
#include "StorageController.h"
#include "../LocatorController.h"
void StorageSaveWorker::SaveStorage()
{
	lastUpdate = QDateTime::currentDateTime();
	changeMutex.lock();
	changed = true;
	changeMutex.unlock();
}
StorageSaveWorker::StorageSaveWorker(StorageObject** pp, QString filename, QObject *parent) :QThread(parent), storagePointer(pp), changeMutex(), initializedMutex(0), changed(false), lastUpdate(QDateTime::currentDateTime()), filename_(filename), storeMutex(), writingMutex() {
	start();
}
StorageSaveWorker::~StorageSaveWorker()
{
	wait();
}
void StorageSaveWorker::run() {
	try {
		Load();
	}
	catch (std::exception& e) {
		try {
			*storagePointer = new StorageObject(&StorageController::modelChanged);
			Store();
		}catch (std::exception& e) {
			Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1").arg(e.what()));
		}
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage: %1").arg(e.what()));
	}
	qDebug() << "bytes";
	while(true) {
		writingMutex.lock();
		lastUpdate = QDateTime::currentDateTime();
		while (!changed || lastUpdate.msecsTo(QDateTime::currentDateTime()) < 1000) {
			QThread::msleep(1000);
		}
		writing = true;
		changeMutex.lock();
		changed = false;
		changeMutex.unlock();
		try {
			Store();
		}catch (std::exception& e) {
			Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't store storage: %1").arg(e.what()));
		}
		qDebug() << "bytes2";
		writing = false;
		writingMutex.unlock();
	}
}
void StorageSaveWorker::isWatingSomethingToStore()
{
	if(writing)
	while (!writingMutex.try_lock());
}
void StorageSaveWorker::isStorageInitialized()
{
	while(*storagePointer == nullptr);
}
void StorageSaveWorker::Store()
{
	qDebug() << "Storing";
	StorageUtility::StoreJSON((*storagePointer)->toJson(), filename_);
}
void StorageSaveWorker::Load()
{
	qDebug() << "Loading";
	QJsonObject obj = StorageUtility::LoadJSON(filename_);
	*storagePointer = StorageObject::fromJson(obj);
	(**storagePointer).setModelChangedPointer(&StorageController::modelChanged);
}
void StorageSaveWorker::BytesWritten()
{
}
void StorageSaveWorker::BytesRead()
{

}
