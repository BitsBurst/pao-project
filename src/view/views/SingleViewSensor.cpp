#include <QLineSeries>
#include "SingleViewSensor.h"

SingleViewSensor::SingleViewSensor(QWidget * parent)
    : AbstractSingleView(parent)
{
    customPlot = new QCustomPlot(this);

    srand(QDateTime::currentDateTime().toSecsSinceEpoch());

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
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

    QString titleTxt = "Realtime Graph";

    customPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(customPlot, titleTxt, CustomElements::getFontH3());
    customPlot->plotLayout()->addElement(0, 0, title);

    customPlot->xAxis->setLabel("x Axis");
    customPlot->yAxis->setLabel("y Axis");
    customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setSelectedFont(legendFont);
    customPlot->legend->setSelectableParts(QCPLegend::spItems);

    // Graphs
    addRealtimeGraph();

    // mouse events callbacks
    connect(customPlot, &QCustomPlot::mousePress, this, &SingleViewSensor::mousePress);

    // connect callback that shows a message in the status bar when a graph is clicked:
    connect(customPlot, &QCustomPlot::plottableClick, this, &SingleViewSensor::graphClicked);

    setWindowTitle(titleTxt);
}

void SingleViewSensor::show()
{
    AbstractSingleView::show();
    customPlot->show();
}


void SingleViewSensor::mousePress()
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

void SingleViewSensor::mouseWheel()
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

void SingleViewSensor::addRealtimeGraph()
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

void SingleViewSensor::addRealtimeSample(double v)
{
    // shift the values
    for (auto i = animdata->begin(); (i + 1) != (animdata->end()); ++i) {
        i->value = (i + 1)->value;
    }
    // add a new datapoint at the start
    (animdata->end() - 1)->value = v;
}

void SingleViewSensor::timerEvent(QTimerEvent *)
{
    // demonstrates that adding a few samples before plotting speeds things up
    for (int i = 0; i < 5; i++) {
        addRealtimeSample(sin(t * 5) * (rand() % 3));
        t = t + dt;
    }
    customPlot->replot();
}

void SingleViewSensor::addRandomGraph()
{
    int n = 2000; // number of points in graph
    double xScale = (rand() / (double) RAND_MAX + 0.5) * 2;
    double yScale = (rand() / (double) RAND_MAX + 0.5) * 2;
    double xOffset = (rand() / (double) RAND_MAX - 0.5) * 4;
    double yOffset = (rand() / (double) RAND_MAX - 0.5) * 10;
    double r1 = (rand() / (double) RAND_MAX - 0.5) * 2;
    double r2 = (rand() / (double) RAND_MAX - 0.5) * 2;
    double r3 = (rand() / (double) RAND_MAX - 0.5) * 2;
    double r4 = (rand() / (double) RAND_MAX - 0.5) * 2;
    QVector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x[i] = (i / (double) n - 0.5) * 10.0 * xScale + xOffset;
        y[i] = (qSin(x[i] * r1 * 5) * qSin(qCos(x[i] * r2) * r4 * 3) + r3 * qCos(qSin(x[i]) * r4 * 2))
                * yScale
                + yOffset;
    }

    customPlot->addGraph();
    customPlot->graph()->setName(QString("New graph %1").arg(customPlot->graphCount() - 1));
    customPlot->graph()->setData(x, y);
    QPen graphPen;
    graphPen.setColor(QColor(rand() % 245 + 10, rand() % 245 + 10, rand() % 245 + 10));
    graphPen.setWidthF(2);
    customPlot->graph()->setPen(graphPen);
    customPlot->replot();
}

void SingleViewSensor::removeSelectedGraph()
{
    if (customPlot->selectedGraphs().size() > 0) {
        customPlot->removeGraph(customPlot->selectedGraphs().first());
        customPlot->replot();
    }
}

void SingleViewSensor::removeAllGraphs()
{
    customPlot->clearGraphs();
    customPlot->replot();
}

void SingleViewSensor::moveLegend()
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

void SingleViewSensor::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
    // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
    // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
    double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
    QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.")
            .arg(plottable->name())
            .arg(dataIndex)
            .arg(dataValue);
}
