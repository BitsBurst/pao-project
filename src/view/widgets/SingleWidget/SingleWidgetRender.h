#ifndef SMARTSENSORS_SINGLEWIDGETRENDER_H
#define SMARTSENSORS_SINGLEWIDGETRENDER_H

#include "../../../model/visitor/IVisitor.h"
#include "SingleSensorWidget.h"
#include "SingleCategoryWidget.h"
#include "../../views/SingleView/SingleView.h"
/**
 * @brief The SingleWidgetRender class
 */
class SingleWidgetRender : public IVisitor {
private:
    SingleSensorWidget * sensor_widget_;
    SingleCategoryWidget * category_widget_;
    InformationWidget * information_widget_;
    SingleView* view_;

public:
    explicit SingleWidgetRender(SingleView* view, SingleSensorWidget * sensor_widget, SingleCategoryWidget * category_widget, InformationWidget* information_widget);
    void visit(Sensor& sensor) override;
    void visit(Category& category) override;
};

#endif //SMARTSENSORS_SINGLEWIDGETRENDER_H
