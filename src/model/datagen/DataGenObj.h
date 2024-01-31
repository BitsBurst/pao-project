#ifndef PAO_PROJECT_DATAGEN_H
#define PAO_PROJECT_DATAGEN_H
#include <QString>
#include <QDateTime>
/**
 * @brief The DataGenObj class
 * This class is used to store the data generated
 */
class DataGenObj {
public:
	DataGenObj(double, QDateTime);
	double getData() const;
	QDateTime getTimestamp() const;
private:
	double data_;
	QDateTime timestamp_;
};

#endif
