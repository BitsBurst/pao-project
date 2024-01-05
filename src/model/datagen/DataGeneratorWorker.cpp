#include "DataGeneratorWorker.h"

DataGeneratorWorker::DataGeneratorWorker(QObject* parent, AbstractDataGen* dataGenerator)
		:QThread(parent), dataGenerator(dataGenerator), counter(0)
{

}
void DataGeneratorWorker::run()
{
	while (true)
	{
		counter++;
		emit dataGenerated(dataGenerator->generateData(), QDateTime::currentDateTime());
	}
}
void DataGeneratorWorker::start(QThread::Priority priority)
{
	if (dataGenerator == nullptr)
	{
		throw std::runtime_error("DataGeneratorWorker::start: dataGenerator is nullptr");
	}
	QThread::start(priority);
}
DataGeneratorWorker::~DataGeneratorWorker()
= default;
