#ifndef SMARTSENSORS_SINGLESENSORWIDGET_H
#define SMARTSENSORS_SINGLESENSORWIDGET_H

#include <QChart>
#include <QChartView>
#include "../../../../include/CustomPlot/qcustomplot.h"
#include "../ChartHandler.h"
/**
 * @brief The SingleSensorWidget class
 */
class SingleSensorWidget : public AbstractWidget {
    Q_OBJECT
private:
    ChartHandler * chart_;

public:
    explicit SingleSensorWidget(AbstractItem* item, QWidget *parent = nullptr);
	~SingleSensorWidget();

	void setItem(Sensor* item);
};

#endif //SMARTSENSORS_SINGLESENSORWIDGET_H
