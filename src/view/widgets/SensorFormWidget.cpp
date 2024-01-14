#include "SensorFormWidget.h"

SensorFormWidget::SensorFormWidget(QWidget* parent)
    : AbstractFormWidget(parent)
{
    min_range_ = new QLabel("Min Range:");
    max_range_ = new QLabel("Max Range:");

    min_range_edit_ = new QSpinBox();
    max_range_edit_ = new QSpinBox();

    min_range_edit_->setMinimum(-100);
    min_range_edit_->setMaximum(100);
    min_range_edit_->setSingleStep(1);

    min_range_edit_->setMinimum(-100);
    min_range_edit_->setMaximum(100);
    min_range_edit_->setSingleStep(1);

    layout_->addWidget(createRow(min_range_, min_range_edit_));
    layout_->addWidget(createRow(max_range_, max_range_edit_));
    layout_->addWidget(getRowBtn());
}