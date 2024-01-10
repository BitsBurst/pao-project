#ifndef PAO_PROJECT_SENSOR_H
#define PAO_PROJECT_SENSOR_H
#include <QDateTime>
#include "AbstractItem.h"
#include "Category.h"
#include "../datagen/DataGeneratorWorker.h"
class Sensor: public AbstractItem {
public:
	Sensor(QString, Category,  void (**)() = nullptr);
	Sensor(void (**)() = nullptr);
	~Sensor();
	double getMinRange();
	void setMinRange(double min_range);
	double getMaxRange();
	void setMaxRange(double max_range);
	Category getCategory();
	void setCategory(Category category);
	QJsonObject toJson() const;
	static Sensor fromJson(QJsonObject const &);
	void startDataGeneration();
	void stopDataGeneration();
private:
	double min_range_;
	double max_range_;
	Category category_;
	qint64 seed_;
	QMap<QDateTime, double> data_;
	DataGeneratorWorker* data_generator_worker_;
	void dataGenerated(double, QDateTime);
};
#endif //PAO_PROJECT_SENSOR_H
