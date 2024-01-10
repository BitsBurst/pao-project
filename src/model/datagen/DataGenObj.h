#ifndef PAO_PROJECT_DATAGEN_H
#define PAO_PROJECT_DATAGEN_H
#include <QString>
#include <QDateTime>
class DataGenObj {
public:
	DataGenObj(double, QDateTime);
	double getData();
	QDateTime getTimestamp();
private:
	double data_;
	QDateTime timestamp_;
};

#endif
