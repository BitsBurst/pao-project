#include <QLineSeries>
#include "SingleViewSensor.h"

SingleViewSensor::SingleViewSensor(QWidget * parent)
    : AbstractSingleView(parent)
{
    // Initialization
    chart_ = new ChartHandler(3, this);

    layout_->addWidget(chart_);
}

void SingleViewSensor::show()
{
    AbstractSingleView::show();
    chart_->show();
}