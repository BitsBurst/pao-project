#ifndef SMARTSENSORS_SENSORFORMWIDGET_H
#define SMARTSENSORS_SENSORFORMWIDGET_H

#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include "AbstractFormWidget.h"
#include "../../../model/core/Sensor.h"
/**
 * @brief The SensorFormWidget class
 * This class is the form widget for the Sensor.
 */
class SensorFormWidget : public AbstractFormWidget {
    Q_OBJECT
private:
    QDoubleSpinBox *max_range_edit_,
                   *min_range_edit_;
    QComboBox * categories_;

    void updateCategories();

public:
    explicit SensorFormWidget(QWidget * parent = nullptr);

    void setValues(const Sensor & item);
    void reset() override;

	void updateItem(AbstractItem* item);
};

#endif //SMARTSENSORS_SENSORFORMWIDGET_H
