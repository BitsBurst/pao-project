#include <QFormLayout>
#include "CategoryFormWidget.h"
/**
 * @brief CategoryFormWidget::CategoryFormWidget
 * This is the constructor of the class. It creates the form layout and the unit measure and data generator fields.
 * @param parent
 */
CategoryFormWidget::CategoryFormWidget(QWidget* parent)
    : AbstractFormWidget(parent)
{
    unit_measure_ = new QComboBox();
    data_gen_ = new QComboBox();

    units_.push_back("C°");
    units_.push_back("F°");
    units_.push_back("Pa");
    units_.push_back("kW");
	units_.push_back("%");
	units_.push_back("km/h");
	units_.push_back("lx");


    for (auto dist : DistributionUtility::type_) {
        data_gens_.push_back(dist);
    }

    unit_measure_->addItems(units_);
    data_gen_->addItems(data_gens_);

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Unità di misura:"), unit_measure_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Generatore dati:"), data_gen_);
}
/**
 * @brief CategoryFormWidget::setValues
 * This method sets the values of the item in the form.
 * @param item
 */
void CategoryFormWidget::setValues(const Category& item)
{
    AbstractFormWidget::setValues(item);

    unit_measure_->setCurrentText(item.getUnitMeasure());
    data_gen_->setCurrentText(DistributionUtility::ToString(item.getDistributionType()));
}
/**
 * @brief CategoryFormWidget::reset
 * This method resets the form.
 */
void CategoryFormWidget::reset()
{
    AbstractFormWidget::reset();

    unit_measure_->setCurrentIndex(0);
    data_gen_->setCurrentIndex(0);
}
/**
 * @brief CategoryFormWidget::updateItem
 * This method updates the item with the values of the form.
 * @param item
 */
void CategoryFormWidget::updateItem(AbstractItem* item)
{
	AbstractFormWidget::updateItem(item);

	static_cast<Category*>(item)->setUnitMeasure(unit_measure_->currentText());
	static_cast<Category*>(item)->setDistributionType(static_cast<DistributionType>(data_gen_->currentIndex()));
}
