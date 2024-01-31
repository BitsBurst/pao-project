#include "ChartHandler.h"

ChartHandler::ChartHandler(int number_charts, QWidget* parent)
    : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    QLayout * curr_row;
    for (int i = 1; i <= number_charts; ++i) {
        RealtimeChart * temp = new RealtimeChart(this);
        chart_list_.push_back(temp);

        if (i % 2 != 0) {
            // Initialization
            curr_row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
            QWidget * row = new QWidget(this);

            // Layout settings
            row->setLayout(curr_row);
            curr_row->setParent(row);

            // Layout widget
            curr_row->addWidget(temp);
            layout_->addWidget(row);
        } else {
            curr_row->addWidget(temp);
        }
    }
}

ChartHandler::ChartHandler(QVector<Sensor *> sensor_list, QWidget* parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), sensor_list_(sensor_list)
{
    QLayout * curr_row;
    for (int i = 1; i <= sensor_list_.size() ; ++i) {
        RealtimeChart * temp = new RealtimeChart(this);
        chart_list_.push_back(temp);

        if (i % 2 != 0) {
            // Initialization
            curr_row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
            QWidget * row = new QWidget(this);

            // Layout settings
            row->setLayout(curr_row);
            curr_row->setParent(row);

            // Layout widget
            curr_row->addWidget(temp);
            layout_->addWidget(row);
        } else {
            curr_row->addWidget(temp);
        }
    }
}