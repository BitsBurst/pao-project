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
    explicit SingleViewSensor(AbstractItem* item, QWidget *parent = nullptr);
};

#endif //SMARTSENSORS_SINGLEVIEWSENSOR_H
