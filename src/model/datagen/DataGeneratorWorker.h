#ifndef SMARTSENSORS_DATAGENERATORWORKER_H
#define SMARTSENSORS_DATAGENERATORWORKER_H

#include <QThread>
#include <QDateTime>
#include "AbstractDataGen.h"

class DataGeneratorWorker: public QThread{
	Q_OBJECT
public:
	DataGeneratorWorker(QObject * = nullptr, AbstractDataGen * = nullptr);
	~DataGeneratorWorker();
	void start(Priority = InheritPriority);
private:
	int counter;
	AbstractDataGen *dataGenerator;
protected:
	void run() override;
signals:
	void dataGenerated(double, QDateTime);
};

#endif //SMARTSENSORS_DATAGENERATORWORKER_H
