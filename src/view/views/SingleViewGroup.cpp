#include "SingleViewGroup.h"
#include "../../utility/Logger.h"

#include <utility>

SingleViewGroup::SingleViewGroup(QVector<Sensor *> sensor_list, QWidget * parent)
    : AbstractSingleView(AbstractItem("0", "Gruppo"), true, parent), sensor_list_(std::move(sensor_list))
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}

SingleViewGroup::SingleViewGroup(const AbstractItem& item, QWidget * parent)
        : AbstractSingleView(item, true, parent)
{
    // Initialization
    chart_ = new ChartHandler(sensor_list_, this);

    layout_->addWidget(chart_);
}

void SingleViewGroup::show()
{
    AbstractSingleView::show();
    chart_->show();
}