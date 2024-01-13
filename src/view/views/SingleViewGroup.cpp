#include "SingleViewGroup.h"
#include "../../utility/Logger.h"

#include <utility>

SingleViewGroup::SingleViewGroup(QVector<Sensor *> sensor_list, QWidget * parent)
    : AbstractSingleView(parent), sensor_list_(std::move(sensor_list))
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