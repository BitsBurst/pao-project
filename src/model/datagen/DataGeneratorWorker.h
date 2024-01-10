#ifndef SMARTSENSORS_DATAGENERATORWORKER_H
#define SMARTSENSORS_DATAGENERATORWORKER_H

#include <QThread>
#include <QDateTime>
#include "AbstractDataGen.h"
#include "../../utility/datagenerator/RandomDataGenerator.h"

class DataGeneratorWorker: public QThread{
	Q_OBJECT


public:
	DataGeneratorWorker(int maxrange, int minrange, int seed, int time = 500, DistributionType distribution_type = UNIFORM,
			QObject* parent= nullptr);
	~DataGeneratorWorker();
	void start(Priority = InheritPriority);
private:
	int counter;
	int maxrange;
	int minrange;
	int speed;
	int seed;
	DistributionType distributionType;
protected:
	void run() override;
signals:
	void dataGenerated(double, QDateTime);
};

#endif //SMARTSENSORS_DATAGENERATORWORKER_H
