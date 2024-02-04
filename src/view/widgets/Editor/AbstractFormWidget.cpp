#include <QFormLayout>
#include "AbstractFormWidget.h"
/**
 * @brief AbstractFormWidget::AbstractFormWidget
 * This is the constructor of the class. It creates the form layout and the name and description fields.
 * @param parent
 */
AbstractFormWidget::AbstractFormWidget(QWidget* parent)
    : AbstractWidget( new QFormLayout, parent)
{
    name_edit_ = new QLineEdit();
    description_edit_ = new QLineEdit();

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Nome"), name_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Descrizione"), description_edit_);
}
/**
 * @brief AbstractFormWidget::setValues
 * This method sets the values of the item in the form.
 * @param item
 */
void AbstractFormWidget::setValues(const AbstractItem& item)
{
    name_edit_->setText(item.getName());
    description_edit_->setText(item.getDescription());
}
/**
 * @brief AbstractFormWidget::reset
 * This method resets the form.
 */
void AbstractFormWidget::reset()
{
    name_edit_->clear();
    description_edit_->clear();
}
/**
 * @brief AbstractFormWidget::updateItem
 * This method updates the item with the values of the form.
 * @param item
 */
void AbstractFormWidget::updateItem(AbstractItem* item) {
	item->setName(name_edit_->text());
    item->setDescription(description_edit_->text());
}
/**
 * @brief AbstractFormWidget::~AbstractFormWidget
 * This is the destructor of the class.
 */
AbstractFormWidget::~AbstractFormWidget()
{

}
