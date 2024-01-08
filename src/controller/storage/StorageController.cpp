#include "StorageController.h"
const QString StorageController::directory_name_ = "data";
StorageController::StorageController()
{
	AbstractItem::setModelChangedPointerStatic(&modelChanged);
}
bool StorageController::Init()
{
	LoadStorage();
	return true;
}
void StorageController::LoadStorage()
{
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::IN);
	storage_ = StorageUtility::Load<StorageObject>(QString("%1/data.dat").arg(StorageController::directory_name_));
	if (storage_ == nullptr) {
		Logger::Log(LogLevel::ERROR, __FILE__, __LINE__, __FUNCTION__, QString("Couldn't load storage."));
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
	qDebug() << "model changed";
	Logger::Log(LogLevel::INFO, __FILE__, __LINE__, __FUNCTION__, LogMethod::OUT);
}
StorageObject* StorageController::GetStorage()
{
	return storage_;
}
