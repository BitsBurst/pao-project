#ifndef SMARTSENSORS_REALTIMECHART_H
#define SMARTSENSORS_REALTIMECHART_H

#include "../core/AbstractWidget.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../utility/CustomElements.h"
#include "../../model/datagen/DataGenObj.h"
#include "../../model/core/Sensor.h"

class RealtimeChart : public AbstractWidget {
Q_OBJECT
private:
    QCustomPlot *custom_plot_;

    QSharedPointer<QCPDataContainer<QCPGraphData> > data_;
    const int max_samples_ = 300;
    const double delta_time_ = 0.1;
    double t = 0;
	Sensor* sensor_;

    void mousePress();
    void mouseWheel();
    void addRealtimeGraph();

public:
    RealtimeChart(QWidget * parent = nullptr, Sensor* sensor = nullptr);
	~RealtimeChart() override;
    void onDataGeneratedEvent(DataGenObj obj);
    void addRealtimeSample(double v);
	void dataGenerated(DataGenObj);
signals:
	void dataGeneratedSignal(DataGenObj);
};

#endif //SMARTSENSORS_REALTIMECHART_H
