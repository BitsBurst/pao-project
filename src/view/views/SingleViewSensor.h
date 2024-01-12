#ifndef SMARTSENSORS_SINGLEVIEWSENSOR_H
#define SMARTSENSORS_SINGLEVIEWSENSOR_H

#include <QChart>
#include <QChartView>
#include "AbstractSingleView.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../widgets/RealtimeChart.h"

class SingleViewSensor : public AbstractSingleView {
    Q_OBJECT
private:
    RealtimeChart * chart_;

public:
    explicit SingleViewSensor(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_SINGLEVIEWSENSOR_H
