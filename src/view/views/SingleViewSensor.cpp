#include <QLineSeries>
#include "SingleViewSensor.h"

SingleViewSensor::SingleViewSensor(AbstractItem* item, QWidget * parent)
    : AbstractSingleView(item,false, parent)
{
    // Initialization
    chart_ = new ChartHandler(1, this);

    layout_->addWidget(chart_);
}