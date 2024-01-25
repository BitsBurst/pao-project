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
