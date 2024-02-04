#include "SingleViewGroup.h"
#include <utility>
/**
 * @brief SingleViewGroup::SingleViewGroup
 * @param sensor_list
 * @param parent
 */
SingleViewGroup::SingleViewGroup(QVector<Sensor *> sensor_list, QWidget * parent)
    : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), sensor_list_(std::move(sensor_list))
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}
/**
 * @brief SingleViewGroup::SingleViewGroup
 * @param parent
 */
SingleViewGroup::SingleViewGroup(QWidget* parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}
/**
 * @brief SingleViewGroup::setSensors
 * @param sensor_list
 */
void SingleViewGroup::setSensors(QVector<Sensor*> sensor_list)
{
    sensor_list_ = sensor_list;
    update();
}
/**
 * @brief SingleViewGroup::update
 */
void SingleViewGroup::update()
{
    // TODO[Luca]: Move insede ChartHandler
    QWidget::update();
    layout_->removeWidget(chart_);
    chart_->deleteLater();
    chart_ = new ChartHandler(sensor_list_, this);
    layout_->addWidget(chart_);
}
/**
 * @brief SingleViewGroup::~SingleViewGroup
 */
SingleViewGroup::~SingleViewGroup()
{

}
