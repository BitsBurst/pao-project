#ifndef SMARTSENSORS_SINGLEVIEWGROUP_H
#define SMARTSENSORS_SINGLEVIEWGROUP_H

#include <QChart>
#include <QChartView>
#include "../../../../include/CustomPlot/qcustomplot.h"
#include "../ChartHandler.h"

// Model Include
#include "../../../model/core/Sensor.h"

class SingleViewGroup : public AbstractWidget {
    Q_OBJECT
private:
    QVector<Sensor *> sensor_list_;
    ChartHandler * chart_;

public:
    explicit SingleViewGroup(QVector<Sensor *> sensor_list, QWidget *parent = nullptr);
    explicit SingleViewGroup(AbstractItem* item, QWidget *parent = nullptr);
    void update();

    void setSensors(QVector<Sensor *> sensor_list);
};

#endif //SMARTSENSORS_SINGLEVIEWGROUP_H
