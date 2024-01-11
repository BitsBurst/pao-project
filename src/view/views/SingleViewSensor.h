#ifndef SMARTSENSORS_SINGLEVIEWSENSOR_H
#define SMARTSENSORS_SINGLEVIEWSENSOR_H

#include <QChart>
#include <QChartView>
#include "AbstractSingleView.h"
#include "../../../include/CustomPlot/qcustomplot.h"

class SingleViewSensor : public AbstractSingleView {
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
    void addRandomGraph();
    void addRealtimeGraph();
    void removeSelectedGraph();
    void removeAllGraphs();
    void moveLegend();
    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

public:
    explicit SingleViewSensor(QWidget *parent = nullptr);
    void show();

    void timerEvent(QTimerEvent *);
    void addRealtimeSample(double v);
};

#endif //SMARTSENSORS_SINGLEVIEWSENSOR_H
