#ifndef SMARTSENSORS_SINGLEWIDGETRENDER_H
#define SMARTSENSORS_SINGLEWIDGETRENDER_H

#include "../../../model/visitor/IConstVisitor.h"
#include "SingleSensorWidget.h"
#include "SingleCategoryWidget.h"
#include "../../views/SingleView/SingleView.h"

class SingleWidgetRender : public IConstVisitor {
private:
    SingleSensorWidget * sensor_widget_;
    SingleCategoryWidget * category_widget_;
    SingleView* view_;

public:
    explicit SingleWidgetRender(SingleView* view, SingleSensorWidget * sensor_widget, SingleCategoryWidget * category_widget);
    void visit(const Sensor& sensor) override;
    void visit(const Category& category) override;
};

#endif //SMARTSENSORS_SINGLEWIDGETRENDER_H
