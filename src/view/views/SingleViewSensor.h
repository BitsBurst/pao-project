#ifndef SMARTSENSORS_SINGLEVIEWSENSOR_H
#define SMARTSENSORS_SINGLEVIEWSENSOR_H

#include <QChart>
#include <QChartView>
#include "AbstractSingleView.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../widgets/ChartHandler.h"

class SingleViewSensor : public AbstractSingleView {
    Q_OBJECT
private:
    ChartHandler * chart_;

public:
    explicit SingleViewSensor(const AbstractItem& item, QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_SINGLEVIEWSENSOR_H
