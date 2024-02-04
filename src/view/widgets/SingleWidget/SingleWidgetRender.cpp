#include "SingleWidgetRender.h"
/**
 * @brief SingleWidgetRender::SingleWidgetRender
 * @param view
 * @param sensor_widget
 * @param category_widget
 * @param information_widget
 */
SingleWidgetRender::SingleWidgetRender(SingleView* view, SingleSensorWidget* sensor_widget, SingleCategoryWidget* category_widget, InformationWidget* information_widget)
    :IVisitor(), sensor_widget_(sensor_widget), category_widget_(category_widget), information_widget_(information_widget), view_(view) {}
/**
 * @brief SingleWidgetRender::visit
 * @param sensor
 */
void SingleWidgetRender::visit(Sensor& sensor)
{
    information_widget_->setItem(&sensor);
	sensor_widget_->setItem(&sensor);
    view_->setActiveView(0);
}
/**
 * @brief SingleWidgetRender::visit
 * @param category
 */
void SingleWidgetRender::visit(Category& category)
{
    information_widget_->setItem(&category);

    category_widget_->setItem(&category);

    view_->setActiveView(1);
}