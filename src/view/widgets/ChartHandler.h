#ifndef SMARTSENSORS_CHARTHANDLER_H
#define SMARTSENSORS_CHARTHANDLER_H

#include <QVector>
#include "../core/AbstractWidget.h"
#include "RealtimeChart.h"

// Model
#include "../../model/core/Sensor.h"

class ChartHandler : public AbstractWidget {
Q_OBJECT
private:
    QVector<RealtimeChart*> chart_list_;
    // TODO[Luca] : Forse si può rimuovere la lista di sensori, non viene utilizzata fuori dal costruttore.
    QVector<Sensor *> sensor_list_;

public:
    explicit ChartHandler(int number_charts = 1, QWidget * parent = nullptr);
    explicit ChartHandler(QVector<Sensor *> vector_list, QWidget * parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_CHARTHANDLER_H
