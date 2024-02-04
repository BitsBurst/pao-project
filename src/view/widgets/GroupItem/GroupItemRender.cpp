#include "GroupItemRender.h"
#include "../../../model/core/Sensor.h"
/**
 * @brief GroupItemRender::GroupItemRender
 * This is the constructor of the class.
 * @param item_widget
 */
GroupItemRender::GroupItemRender(GroupItemWidget* item_widget)
    : item_widget_(item_widget){}
/**
 * @brief GroupItemRender::visit
 * This method visits the sensor and sets the title and detail in the item widget.
 * @param sensor
 */
void GroupItemRender::visit(const Sensor& sensor)
{
    item_widget_->setTitle(sensor.getName());
    item_widget_->setDetail(sensor.getCategory().getName());
}
/**
 * @brief GroupItemRender::visit
 * This method visits the category and sets the title and detail in the item widget.
 * @param category
 */
void GroupItemRender::visit(const Category& category)
{
    item_widget_->setTitle(category.getName());
    item_widget_->setDetail(category.getUnitMeasure());
}
