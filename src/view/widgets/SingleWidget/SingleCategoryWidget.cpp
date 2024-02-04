#include "SingleCategoryWidget.h"
/**
 * @brief SingleCategoryWidget::SingleCategoryWidget
 * This is the constructor of the class.
 * @param item
 * @param parent
 */
SingleCategoryWidget::SingleCategoryWidget(Category* item, QWidget* parent)
    :AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    unit_measure_ = new QLabel(item->getUnitMeasure());
    distribution_type_ = new QLabel(DistributionUtility::ToString(item->getDistributionType()));

    unit_measure_->setFont(CustomElements::getFontParagraph());
    distribution_type_->setFont(CustomElements::getFontParagraph());

    QLabel * pref_unit = new QLabel("Unità di misura: ");
    QLabel * pref_distribution = new QLabel("Distribuzione: ");

    pref_unit->setFont(CustomElements::getFontParagraph());
    pref_distribution->setFont(CustomElements::getFontParagraph());

    QWidget* row1 = new QWidget(this);
    QHBoxLayout * row1_layout = new QHBoxLayout(row1);

    row1_layout->addWidget(pref_unit);
    row1_layout->addWidget(unit_measure_);
    row1_layout->addStretch();

    QWidget* row2 = new QWidget(this);
    QHBoxLayout * row2_layout = new QHBoxLayout(row2);

    row2_layout->addWidget(pref_distribution);
    row2_layout->addWidget(distribution_type_);
    row2_layout->addStretch();

    layout_->addWidget(row1);
    layout_->addWidget(row2);
    layout_->addItem(CustomElements::getTerminalSpacer(VERTICAL));
}
/**
 * @brief SingleCategoryWidget::~SingleCategoryWidget
 * This is the destructor of the class.
 */
SingleCategoryWidget::~SingleCategoryWidget()
{

}
/**
 * @brief SingleCategoryWidget::setItem
 * This method sets the item of the widget.
 * @param item
 */
void SingleCategoryWidget::setItem(Category* item)
{
    if (item != nullptr) {
        unit_measure_->setText(item->getUnitMeasure());
        distribution_type_->setText(DistributionUtility::ToString(item->getDistributionType()));
    }
}
