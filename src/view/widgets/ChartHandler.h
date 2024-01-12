#ifndef SMARTSENSORS_CHARTHANDLER_H
#define SMARTSENSORS_CHARTHANDLER_H

#include <QVector>
#include "../core/AbstractWidget.h"
#include "RealtimeChart.h"

class ChartHandler : public AbstractWidget {
Q_OBJECT
private:
    QVector<RealtimeChart*> chart_list_;
public:
    ChartHandler(int number_charts = 1, QWidget * parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_CHARTHANDLER_H
