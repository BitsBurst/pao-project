#include <QLineSeries>
#include "SingleSensorWidget.h"
/**
 * @brief SingleSensorWidget::SingleSensorWidget
 * @param item
 * @param parent
 */
SingleSensorWidget::SingleSensorWidget(AbstractItem* item, QWidget * parent)
    :AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    // Initialization
	QVector<Sensor *> sensor_list;
	sensor_list.push_back(dynamic_cast<Sensor*>(item));
    chart_ = new ChartHandler(sensor_list, this);

    layout_->addWidget(chart_);
}
/**
 * @brief SingleSensorWidget::setItem
 * @param item
 */
void SingleSensorWidget::setItem(Sensor* item)
{
	layout_->removeWidget(chart_);
	delete chart_;

	QVector<Sensor *> sensor_list;
	sensor_list.push_back(dynamic_cast<Sensor*>(item));
	chart_ = new ChartHandler(sensor_list, this);

	layout_->addWidget(chart_);
}
/**
 * @brief SingleSensorWidget::update
 */
SingleSensorWidget::~SingleSensorWidget()
{

}
