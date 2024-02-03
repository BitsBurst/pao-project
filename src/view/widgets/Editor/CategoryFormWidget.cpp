#include <QFormLayout>
#include "CategoryFormWidget.h"

CategoryFormWidget::CategoryFormWidget(QWidget* parent)
    : AbstractFormWidget(parent)
{
    unit_measure_ = new QComboBox();
    data_gen_ = new QComboBox();

    units_.push_back("C°");
    units_.push_back("F°");
    units_.push_back("Pa");
    units_.push_back("kW");

    for (auto dist : DistributionUtility::type_) {
        data_gens_.push_back(dist);
    }

    unit_measure_->addItems(units_);
    data_gen_->addItems(data_gens_);

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Unità di misura:"), unit_measure_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Generatore dati:"), data_gen_);
}

void CategoryFormWidget::setValues(const Category& item)
{
    AbstractFormWidget::setValues(item);

    unit_measure_->setCurrentText(item.getUnitMeasure());
    data_gen_->setCurrentText(DistributionUtility::ToString(item.getDistributionType()));
}

void CategoryFormWidget::reset()
{
    AbstractFormWidget::reset();

    unit_measure_->setCurrentIndex(0);
    data_gen_->setCurrentIndex(0);
}

void CategoryFormWidget::updateItem(AbstractItem* item)
{
	AbstractFormWidget::updateItem(item);

	static_cast<Category*>(item)->setUnitMeasure(unit_measure_->currentText());
	static_cast<Category*>(item)->setDistributionType(static_cast<DistributionType>(data_gen_->currentIndex()));
}
