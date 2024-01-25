#ifndef SMARTSENSORS_SENSORFORMWIDGET_H
#define SMARTSENSORS_SENSORFORMWIDGET_H

#include <QSpinBox>
#include "AbstractFormWidget.h"

class SensorFormWidget : public AbstractFormWidget {
    Q_OBJECT
private:
    QLabel *max_range_, * min_range_;
    QSpinBox *max_range_edit_, * min_range_edit_;
public:
    explicit SensorFormWidget(QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_SENSORFORMWIDGET_H
