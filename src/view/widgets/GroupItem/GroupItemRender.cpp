#include "GroupItemRender.h"
#include "../../../model/core/Sensor.h"
#include "../../../model/core/Category.h"

GroupItemRender::GroupItemRender(GroupItemWidget* item_widget)
    : item_widget_(item_widget){}

void GroupItemRender::visit(const Sensor& sensor)
{
    item_widget_->setTitle(sensor.getName());
    item_widget_->setDetail(sensor.getCategory().getName());
}

void GroupItemRender::visit(const Category& category)
{
    item_widget_->setTitle(category.getName());
    item_widget_->setDetail(category.getUnitMeasure());
}
