#include "RealtimeChart.h"


RealtimeChart::RealtimeChart(QWidget * parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(H_NO_BORDER) ,parent)
{
    customPlot = new QCustomPlot(this);

    srand(QDateTime::currentDateTime().toSecsSinceEpoch());

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
    customPlot->setSizePolicy(sizePolicy);

    layout_->addWidget(customPlot);

    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes
            | QCP::iSelectLegend | QCP::iSelectPlottables);
    customPlot->xAxis->setRange(0, 6);
    customPlot->yAxis->setRange(-5, 5);
    customPlot->axisRect()->setupFullAxesBox();

    customPlot->xAxis->setLabel("x Axis");
    customPlot->yAxis->setLabel("y Axis");
    customPlot->legend->setVisible(true);

    customPlot->legend->setFont(CustomElements::getFontParagraph());
    customPlot->legend->setSelectedFont(CustomElements::getFontParagraph());
    customPlot->legend->setSelectableParts(QCPLegend::spItems);

    // Graphs
    addRealtimeGraph();

    // mouse events callbacks
    connect(customPlot, &QCustomPlot::mousePress, this, &RealtimeChart::mousePress);
}

void RealtimeChart::show()
{
    customPlot->show();
}

void RealtimeChart::mousePress()
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeDrag(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
}

void RealtimeChart::mouseWheel()
{
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->xAxis->orientation());
    else if (customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        customPlot->axisRect()->setRangeZoom(customPlot->yAxis->orientation());
    else
        customPlot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
}

void RealtimeChart::addRealtimeGraph()
{
    customPlot->addGraph();
    customPlot->graph()->setName(QString("Realtime"));
    animdata.reset(new QCPDataContainer<QCPGraphData>);
    for (int i = 0; i < nRealtimePoints; i++) {
        QCPGraphData data(i * dt, 0);
        animdata->add(data);
    }
    customPlot->graph()->setData(animdata);
    QPen graphPen;
    graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
    graphPen.setWidthF(2);
    customPlot->graph()->setPen(graphPen);
    customPlot->replot();
    startTimer(500);
}

void RealtimeChart::addRealtimeSample(double v)
{
    // shift the values
    for (auto i = animdata->begin(); (i + 1) != (animdata->end()); ++i) {
        i->value = (i + 1)->value;
    }
    // add a new datapoint at the start
    (animdata->end() - 1)->value = v;
}

void RealtimeChart::timerEvent(QTimerEvent *)
{
    // demonstrates that adding a few samples before plotting speeds things up
    for (int i = 0; i < 5; i++) {
        addRealtimeSample(sin(t * 5) * (rand() % 3));
        t = t + dt;
    }
    customPlot->replot();
}


void RealtimeChart::moveLegend()
{
    if (QAction *contextAction = qobject_cast<QAction *>(
            sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
    {
        bool ok;
        int dataInt = contextAction->data().toInt(&ok);
        if (ok) {
            customPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment) dataInt);
            customPlot->replot();
        }
    }
}
