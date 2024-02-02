#ifndef PAO_PROJECT_SENSOR_H
#define PAO_PROJECT_SENSOR_H
#include <QMutexLocker>
#include "AbstractItem.h"
#include "Category.h"
#include "../datagen/DataGeneratorWorker.h"
#include "../../utility/limitedqmap/LimitedQMap.h"
/*
 * @brief Sensor class
 * @details This class represents a sensor. It has a category, a min and max range and a data generator worker.
 */
class Sensor: public AbstractItem{

public:
	Sensor(QString, Category);
	Sensor();
	Sensor(const Sensor &);
	~Sensor();
	double getMinRange() const;
	void setMinRange(double min_range);
	double getMaxRange() const;
	void setMaxRange(double max_range);
	Category getCategory() const;
	void setCategory(Category category);
	QJsonObject toJson() const;
	static Sensor * fromJson(QJsonObject const &);
	void startDataGeneration();
	void stopDataGeneration();
	EventHandler<DataGenObj> onDataGenerated;

	LimitedQMap<QDateTime, double> data_;

    void accept(IConstVisitor& visitor) const override;
    void accept(IVisitor& visitor) override;

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
