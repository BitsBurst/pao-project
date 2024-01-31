#include "RealtimeChart.h"


RealtimeChart::RealtimeChart(QWidget * parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(H_NO_BORDER) ,parent)
{
    // Initialization
    custom_plot_ = new QCustomPlot(this);
    srand(QDateTime::currentDateTime().toSecsSinceEpoch());

    // SizePolicy
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(custom_plot_->sizePolicy().hasHeightForWidth());
    custom_plot_->setSizePolicy(sizePolicy);

    layout_->addWidget(custom_plot_);

    // Custom chart settings
    custom_plot_->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes
            | QCP::iSelectLegend | QCP::iSelectPlottables);
    custom_plot_->xAxis->setRange(0, 6);
    custom_plot_->yAxis->setRange(-5, 5);

    custom_plot_->xAxis->setLabel("x Axis");
    custom_plot_->yAxis->setLabel("y Axis");

    /*
    custom_plot_->legend->setVisible();

    custom_plot_->legend->setFont(CustomElements::getFontParagraph());
    custom_plot_->legend->setSelectedFont(CustomElements::getFontParagraph());
    custom_plot_->legend->setSelectableParts(QCPLegend::spItems);
    */

    // Graphs
    addRealtimeGraph();

    // Mouse events callbacks
    connect(custom_plot_, &QCustomPlot::mousePress, this, &RealtimeChart::mousePress);
}

void RealtimeChart::mousePress()
{
    if (custom_plot_->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        custom_plot_->axisRect()->setRangeDrag(custom_plot_->xAxis->orientation());
    else if (custom_plot_->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        custom_plot_->axisRect()->setRangeDrag(custom_plot_->yAxis->orientation());
    else
        custom_plot_->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
}

void RealtimeChart::mouseWheel()
{
    if (custom_plot_->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        custom_plot_->axisRect()->setRangeZoom(custom_plot_->xAxis->orientation());
    else if (custom_plot_->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        custom_plot_->axisRect()->setRangeZoom(custom_plot_->yAxis->orientation());
    else
        custom_plot_->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
}

void RealtimeChart::addRealtimeGraph()
{
    custom_plot_->addGraph();
    custom_plot_->graph()->setName(QString("Realtime"));

    data_.reset(new QCPDataContainer<QCPGraphData>);

    // Initial data ( 0 )
    for (int i = 0; i < max_samples_; i++) {
        QCPGraphData data(i * delta_time_, 0);
        data_->add(data);
    }
    custom_plot_->graph()->setData(data_);

    // Pen Settings
    QPen graphPen;
    graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
    graphPen.setWidthF(2);
    custom_plot_->graph()->setPen(graphPen);

    custom_plot_->replot();
    startTimer(50);
}

void RealtimeChart::addRealtimeSample(double v)
{
    // shift the values
    for (auto i = data_->begin(); (i + 1) != (data_->end()); ++i) {
        i->value = (i + 1)->value;
    }
    // add a new datapoint at the start
    (data_->end() - 1)->value = v;
}

void RealtimeChart::timerEvent(QTimerEvent *)
{
    for (int i = 0; i < 5; i++) {
        addRealtimeSample(sin(t * 5) * (rand() % 3));
        t = t + delta_time_;
    }
    custom_plot_->replot();
}