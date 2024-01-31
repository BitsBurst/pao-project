#include "DataGeneratorWorker.h"
DataGeneratorWorker::DataGeneratorWorker(int maxrange, int minrange, int seed, unsigned long time, DistributionType distribution_type, QObject* parent)
		:QThread(parent), counter(0), maxrange(maxrange), minrange(minrange), speed(time), seed(seed), distributionType(distribution_type)
{

}
void DataGeneratorWorker::run()
{
	CombinedDataGenerator data_generator;
	data_generator.setDistributionType(distributionType);
	while (true)
	{
		counter++;
		DataGenObj obj(data_generator.generateData(), QDateTime::currentDateTime());
		newDataEvent.notify(obj);
		QThread::msleep(speed);
	}
}
void DataGeneratorWorker::start(QThread::Priority priority)
{
	QThread::start(priority);
}

DataGeneratorWorker::~DataGeneratorWorker()
= default;
