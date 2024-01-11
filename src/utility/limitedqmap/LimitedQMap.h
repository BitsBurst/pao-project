#ifndef SMARTSENSORS_LIMITEDQMAP_H
#define SMARTSENSORS_LIMITEDQMAP_H
#include <QMap>
#include <QDateTime>
#include <iostream>
#include <QMap>
#include <QDateTime>
#include <QMutex>
#include <QMutexLocker>
#include <iostream>

template <typename Key, typename T>
class LimitedQMap : public QMap<Key, T> {
public:
	LimitedQMap(int maxSize) : maxSize(maxSize), mutex() {}

	void insertLimited(const Key &key, const T &value) {
		mutex.lock();
		this->insert(key, value);
		while (this->size() > maxSize) {
			this->erase(this->begin());
		}
		mutex.unlock();
	}

private:
	int maxSize;
	QMutex mutex;
};
#endif //SMARTSENSORS_LIMITEDQMAP_H
