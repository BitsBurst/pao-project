#include "DataGeneratorWorker.h"
/**
 * @brief DataGeneratorWorker::DataGeneratorWorker
 * Constructor
 * @param maxrange max range of the data
 * @param minrange min range of the data
 * @param seed seed of the data
 * @param time time between each data generation
 * @param distribution_type distribution type of the data
 * @param parent parent of the thread
 */
DataGeneratorWorker::DataGeneratorWorker(int maxrange, int minrange, int seed, unsigned long time, DistributionType distribution_type, QObject* parent)
		:QThread(parent), counter(0), maxrange(maxrange), minrange(minrange), speed(time), seed(seed), distributionType(distribution_type)
{

}
/**
 * @brief DataGeneratorWorker::run
 * This method is used to generate data in a separate thread
 */
void DataGeneratorWorker::run()
{
	CombinedDataGenerator data_generator;
	data_generator.setDistributionType(distributionType);
	data_generator.setMinMaxValue(minrange, maxrange);
	while (true)
	{
		counter++;
		DataGenObj obj(data_generator.generateData(), QDateTime::currentDateTime());
		newDataEvent.notify(obj);
		QThread::msleep(speed);
	}
}
/**
 * @brief DataGeneratorWorker::start
 * @param priority priority of the thread
 */
void DataGeneratorWorker::start(QThread::Priority priority)
{
	QThread::start(priority);
}
/**
 * @brief DataGeneratorWorker::~DataGeneratorWorker
 * Destructor
 */
DataGeneratorWorker::~DataGeneratorWorker()
= default;
