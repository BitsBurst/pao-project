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

/**
 * @brief The LimitedQMap class
 * This class is used to store a limited number of elements in a QMap
 * @tparam Key the key of the QMap
 * @tparam T the value of the QMap
 */
template <typename Key, typename T>
class LimitedQMap : public QMap<Key, T> {
public:
	/**
	 * @brief LimitedQMap
	 * Constructor
	 * @param maxSize
	 */
	LimitedQMap(int maxSize) : maxSize(maxSize), mutex() {}
	/**
	 * @brief insertLimited
	 * Insert a new element in the map and remove the oldest if the map is full
	 * @param key
	 * @param value
	 */
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
