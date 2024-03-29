#ifndef SMARTSENSORS_CHARTHANDLER_H
#define SMARTSENSORS_CHARTHANDLER_H

#include <QVector>
#include "../core/AbstractWidget.h"
#include "RealtimeChart.h"

// Model
#include "../../model/core/Sensor.h"
/**
 * @brief The ChartHandler class
 */
class ChartHandler : public AbstractWidget {
Q_OBJECT
private:
    QVector<RealtimeChart*> chart_list_;
    QVector<Sensor *> sensor_list_;

public:
    explicit ChartHandler(QVector<Sensor *> vector_list, QWidget * parent = nullptr);
	~ChartHandler() override;
};

#endif //SMARTSENSORS_CHARTHANDLER_H
