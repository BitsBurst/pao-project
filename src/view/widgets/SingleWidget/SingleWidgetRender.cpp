#include "SingleWidgetRender.h"

SingleWidgetRender::SingleWidgetRender(SingleView* view, SingleSensorWidget* sensor_widget, SingleCategoryWidget* category_widget)
    : sensor_widget_(sensor_widget), category_widget_(category_widget), view_(view) {}

void SingleWidgetRender::visit(Sensor& sensor)
{
	sensor_widget_->setItem(&sensor);
    view_->setActiveView(0);
}

void SingleWidgetRender::visit(Category& category)
{
    view_->setActiveView(1);
}