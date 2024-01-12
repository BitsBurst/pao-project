#include <QLineSeries>
#include "SingleViewSensor.h"

SingleViewSensor::SingleViewSensor(QWidget * parent)
    : AbstractSingleView(parent)
{
    // Initialization
    chart_ = new RealtimeChart(this);

    layout_->addWidget(chart_);
}

void SingleViewSensor::show()
{
    AbstractSingleView::show();
    chart_->show();
}