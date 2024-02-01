#include "SingleViewGroup.h"
#include <utility>

SingleViewGroup::SingleViewGroup(QVector<Sensor *> sensor_list, QWidget * parent)
    : AbstractSingleView(new AbstractItem("Gruppo"), true, parent), sensor_list_(std::move(sensor_list))
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}

SingleViewGroup::SingleViewGroup(AbstractItem* item, QWidget * parent)
        : AbstractSingleView(item, true, parent)
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}

void SingleViewGroup::setSensors(QVector<Sensor*> sensor_list)
{
    sensor_list_ = sensor_list;
    update();
}

void SingleViewGroup::update()
{
    // TODO[Luca]: Move insede ChartHandler
    QWidget::update();
    layout_->removeWidget(chart_);
    chart_->deleteLater();
    chart_ = new ChartHandler(sensor_list_, this);
    layout_->addWidget(chart_);
}
