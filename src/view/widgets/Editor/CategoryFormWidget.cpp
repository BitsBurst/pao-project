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

    data_gens_.push_back("Lineare");
    data_gens_.push_back("Casuale");
    data_gens_.push_back("Distribuzione");

    unit_measure_->addItems(units_);
    data_gen_->addItems(data_gens_);

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Unità di misura:"), unit_measure_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Generatore dati:"), data_gen_);
}

void CategoryFormWidget::setValues(const Category& item)
{
    AbstractFormWidget::setValues(item);

    if (units_.contains(item.getUnitMeasure()))
        unit_measure_->setCurrentText(item.getUnitMeasure());
}
