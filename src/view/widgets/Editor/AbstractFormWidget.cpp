#include <QFormLayout>
#include "AbstractFormWidget.h"
#include "../../utility/CustomElements.h"

AbstractFormWidget::AbstractFormWidget(QWidget* parent)
    : AbstractWidget( new QFormLayout, parent)
{
    name_edit_ = new QLineEdit();
    description_edit_ = new QLineEdit();

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Nome"), name_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Descrizione"), description_edit_);
}

void AbstractFormWidget::setValues(const AbstractItem& item)
{
    name_edit_->setText(item.getName());
    description_edit_->setText(item.getDescription());
}

void AbstractFormWidget::reset()
{
    name_edit_->clear();
    description_edit_->clear();
}

void AbstractFormWidget::updateItem(AbstractItem* item) {
	item->setName(name_edit_->text());
    item->setDescription(description_edit_->text());
}
AbstractFormWidget::~AbstractFormWidget()
{

}
