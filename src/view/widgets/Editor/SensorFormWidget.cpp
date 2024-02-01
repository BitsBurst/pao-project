#include <QFormLayout>
#include "SensorFormWidget.h"

SensorFormWidget::SensorFormWidget(QWidget* parent)
    : AbstractFormWidget(parent)
{
    min_range_edit_ = new QDoubleSpinBox();
    max_range_edit_ = new QDoubleSpinBox();

    min_range_edit_->setRange(-100, 0);
    min_range_edit_->setSingleStep(0.5);
    min_range_edit_->setValue(-50);
    min_range_edit_->setDecimals(2);

    max_range_edit_->setRange(0, 100);
    max_range_edit_->setSingleStep(0.5);
    max_range_edit_->setValue(50);
    max_range_edit_->setDecimals(2);

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Min Range"), min_range_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Max Range"), max_range_edit_);
}

void SensorFormWidget::setValues(const Sensor& item)
{
    AbstractFormWidget::setValues(item);

    min_range_edit_->setValue(item.getMinRange());
    max_range_edit_->setValue(item.getMaxRange());
}

void SensorFormWidget::reset()
{
    AbstractFormWidget::reset();

    min_range_edit_->clear();
    max_range_edit_->clear();
}

void SensorFormWidget::updateItem(AbstractItem* item)
{
	AbstractFormWidget::updateItem(item);

	static_cast<Sensor*>(item)->setMinRange(min_range_edit_->value());
	static_cast<Sensor*>(item)->setMaxRange(max_range_edit_->value());
}
