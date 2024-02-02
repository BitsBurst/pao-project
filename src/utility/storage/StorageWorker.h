#ifndef SMARTSENSORS_STORAGEWORKER_H
#define SMARTSENSORS_STORAGEWORKER_H

#include <QThread>
#include <deque>
#include <QSemaphore>
#include <QMutex>
#include <QFile>
#include "../../model/storage/StorageObject.h"
/*
 * @brief StorageWorker
 * This class is used to store the storage in a file
 */
class StorageWorker: public QThread {
Q_OBJECT
public:
	StorageWorker(StorageObject**, QString, QObject * = nullptr);
	~StorageWorker();
	void isWatingSomethingToStore();
	void SaveStorage();
	void isStorageInitialized();
	bool isStorageReady();
	EventHandlerVoid onStorageReadyEvent;
private:
	StorageObject** storagePointer;
	QMutex writingMutex;
	QString filename_;
	bool changed;
	bool closing;
	bool destroy;
	void Store();
	void Load();
protected:
	void run() override;
	QDateTime lastUpdate;
	bool storageInitialized;
};

#endif //SMARTSENSORS_STORAGEWORKER_H
