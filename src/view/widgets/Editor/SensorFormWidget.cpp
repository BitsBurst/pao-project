#include <QFormLayout>
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

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Min Range"), min_range_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Max Range"), max_range_edit_);
}