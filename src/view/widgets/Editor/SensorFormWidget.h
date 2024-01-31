#ifndef SMARTSENSORS_SENSORFORMWIDGET_H
#define SMARTSENSORS_SENSORFORMWIDGET_H

#include <QSpinBox>
#include "AbstractFormWidget.h"
#include "../../../model/core/Sensor.h"

class SensorFormWidget : public AbstractFormWidget {
    Q_OBJECT
private:
    QDoubleSpinBox *max_range_edit_,
                   *min_range_edit_;
public:
    explicit SensorFormWidget(QWidget * parent = nullptr);

    void setValues(const Sensor & item);
    void reset() override;
};

#endif //SMARTSENSORS_SENSORFORMWIDGET_H
