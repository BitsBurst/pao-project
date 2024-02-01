#include <QLineSeries>
#include "SingleSensorWidget.h"

SingleSensorWidget::SingleSensorWidget(AbstractItem* item, QWidget * parent)
    :AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    // Initialization
    chart_ = new ChartHandler(1, this);

    layout_->addWidget(chart_);
}