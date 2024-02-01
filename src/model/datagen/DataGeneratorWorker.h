#ifndef SMARTSENSORS_DATAGENERATORWORKER_H
#define SMARTSENSORS_DATAGENERATORWORKER_H

#include <QThread>
#include <QDateTime>
#include "DataGenObj.h"
#include "../../utility/datagenerator/RandomDataGenerator.h"
#include "../../utility/event/EventHandler.h"

/**
 * @brief The DataGeneratorWorker class
 * This class is used to generate data in a separate thread
 */
class DataGeneratorWorker: public QThread{
	Q_OBJECT
public:
	DataGeneratorWorker(int maxrange, int minrange, int seed, unsigned long time = 500, DistributionType distribution_type = DistributionType::UNIFORM,
			QObject* parent= nullptr);
	~DataGeneratorWorker();
	void start(Priority = InheritPriority);
	EventHandler<DataGenObj> newDataEvent;
private:
	int counter;
	int maxrange;
	int minrange;
	unsigned long speed;
	int seed;
	DistributionType distributionType;
protected:
	void run() override;
};

#endif //SMARTSENSORS_DATAGENERATORWORKER_H
