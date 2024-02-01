#include "SingleWidgetRender.h"

SingleWidgetRender::SingleWidgetRender(SingleView* view, SingleSensorWidget* sensor_widget, SingleCategoryWidget* category_widget)
    : sensor_widget_(sensor_widget), category_widget_(category_widget), view_(view) {}

void SingleWidgetRender::visit(const Sensor& sensor)
{
    view_->setActiveView(0);
}

void SingleWidgetRender::visit(const Category& category)
{
    view_->setActiveView(1);
}