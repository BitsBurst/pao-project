#include "ChartHandler.h"
/**
 * @brief ChartHandler::ChartHandler
 * @param sensor_list
 * @param parent
 */
ChartHandler::ChartHandler(QVector<Sensor *> sensor_list, QWidget* parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), sensor_list_(sensor_list)
{
    QLayout * curr_row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
    for (int i = 1; i <= sensor_list_.size() ; ++i) {
        RealtimeChart * temp = new RealtimeChart(this, sensor_list_[i-1]);
        chart_list_.push_back(temp);
        if (i % 2 != 0) {
            // Initialization
			if(i > 1){
				curr_row = CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING);
			}
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
/**
 * @brief ChartHandler::~ChartHandler
 */
ChartHandler::~ChartHandler()
{
	for (auto & chart : chart_list_) {
		delete chart;
	}
}
