#ifndef SMARTSENSORS_REALTIMECHART_H
#define SMARTSENSORS_REALTIMECHART_H

#include "../core/AbstractWidget.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../utility/CustomElements.h"

class RealtimeChart : public AbstractWidget {
Q_OBJECT
private:
    QCustomPlot *custom_plot_;

    QSharedPointer<QCPDataContainer<QCPGraphData> > data_;
    const int max_samples_ = 300;
    const double delta_time_ = 0.02;
    double t = 0;

    void mousePress();
    void mouseWheel();
    void addRealtimeGraph();

public:
    RealtimeChart(QWidget * parent = nullptr);

    void show();

    void timerEvent(QTimerEvent *);
    void addRealtimeSample(double v);
};

#endif //SMARTSENSORS_REALTIMECHART_H
