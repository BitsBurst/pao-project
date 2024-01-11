#ifndef PAO_PROJECT_SENSOR_H
#define PAO_PROJECT_SENSOR_H
#include <QMutexLocker>
#include "AbstractItem.h"
#include "Category.h"
#include "../datagen/DataGeneratorWorker.h"
#include "../../utility/limitedqmap/LimitedQMap.h"
class Sensor: public AbstractItem {
public:
	Sensor(QString, Category);
	Sensor();
	~Sensor();
	double getMinRange();
	void setMinRange(double min_range);
	double getMaxRange();
	void setMaxRange(double max_range);
	Category getCategory();
	void setCategory(Category category);
	QJsonObject toJson() const;
	static Sensor * fromJson(QJsonObject const &);
	void startDataGeneration();
	void stopDataGeneration();
	EventHandlerVoid onDataGenerated;

	LimitedQMap<QDateTime, double> data_;

private:
	double min_range_;
	double max_range_;
	Category category_;
	qint64 seed_;
	DataGeneratorWorker* data_generator_worker_;
	double generationTime;
	static double maxDataGenerated;
	static double generationTimeStatic;
	void dataGenerated(DataGenObj);
};
#endif //PAO_PROJECT_SENSOR_H
