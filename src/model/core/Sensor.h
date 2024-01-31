#ifndef PAO_PROJECT_SENSOR_H
#define PAO_PROJECT_SENSOR_H
#include <QDateTime>
#include "AbstractItem.h"
#include "Category.h"
#include "../datagen/DataGeneratorWorker.h"
class Sensor: public AbstractItem {
	friend QDataStream &operator<<(QDataStream &, const Sensor &);
	friend QDataStream &operator>>(QDataStream &, Sensor &);
public:
	Sensor(QString, QString, Category,  void (**)() = nullptr);
	Sensor(void (**)() = nullptr);
	~Sensor();
	double getMinRange() const;
	void setMinRange(double min_range);
	double getMaxRange() const;
	void setMaxRange(double max_range);
	Category getCategory() const;
	void setCategory(Category category);
private:
	double min_range_;
	double max_range_;
	Category category_;
	QMap<QDateTime, double> data_;
};
QDataStream &operator<<(QDataStream &, const Sensor&);
QDataStream &operator>>(QDataStream &, Sensor &);
#endif //PAO_PROJECT_SENSOR_H
