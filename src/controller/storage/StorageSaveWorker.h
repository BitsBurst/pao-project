#ifndef SMARTSENSORS_STORAGESAVEWORKER_H
#define SMARTSENSORS_STORAGESAVEWORKER_H

#include <QThread>
#include <deque>
#include <QSemaphore>
#include <QMutex>
#include <QFile>
#include "../../model/storage/StorageObject.h"
class StorageSaveWorker: public QThread {
Q_OBJECT
public:
	StorageSaveWorker(StorageObject**, QString, QObject * = nullptr);
	~StorageSaveWorker();
	void isWatingSomethingToStore();
	void SaveStorage();
	void isStorageInitialized();
private:
	StorageObject** storagePointer;
	QSemaphore initializedMutex;
	QMutex changeMutex;
	QMutex storeMutex;
	QMutex writingMutex;
	QString filename_;
	QFile* file;
	bool changed;
	void Store();
	void Load();
protected:
	void run() override;
	QDateTime lastUpdate;
	void BytesWritten();
	void BytesRead();
	bool writing;
};

#endif //SMARTSENSORS_STORAGESAVEWORKER_H
