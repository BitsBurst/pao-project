#ifndef SMARTSENSORS_REALTIMECHART_H
#define SMARTSENSORS_REALTIMECHART_H

#include "../core/AbstractWidget.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../utility/CustomElements.h"

class RealtimeChart : public AbstractWidget {
Q_OBJECT
private:
    QCustomPlot *customPlot;

    QSharedPointer<QCPDataContainer<QCPGraphData> > animdata;
    const int nRealtimePoints = 300;
    const double dt = 0.02;
    double t = 0;
    QTimer * timer_;

    void mousePress();
    void mouseWheel();
    void addRealtimeGraph();
    void moveLegend();
    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

public:
    RealtimeChart(QWidget * parent = nullptr);

    void show();

    void timerEvent(QTimerEvent *);
    void addRealtimeSample(double v);
};

#endif //SMARTSENSORS_REALTIMECHART_H
