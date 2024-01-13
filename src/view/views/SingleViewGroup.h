#ifndef SMARTSENSORS_SINGLEVIEWGROUP_H
#define SMARTSENSORS_SINGLEVIEWGROUP_H

#include <QChart>
#include <QChartView>
#include "AbstractSingleView.h"
#include "../../../include/CustomPlot/qcustomplot.h"
#include "../widgets/ChartHandler.h"

// Model Include
#include "../../model/core/Sensor.h"

class SingleViewGroup : public AbstractSingleView {
    Q_OBJECT
private:
    QVector<Sensor *> sensor_list_;
    ChartHandler * chart_;

public:
    explicit SingleViewGroup(QVector<Sensor *> sensor_list, QWidget *parent = nullptr);
    explicit SingleViewGroup(const AbstractItem& item, QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_SINGLEVIEWGROUP_H
