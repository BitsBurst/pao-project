#include <QFormLayout>
#include "AbstractFormWidget.h"
#include "../utility/CustomElements.h"

AbstractFormWidget::AbstractFormWidget(QWidget* parent)
    : AbstractWidget( new QFormLayout, parent)
{
    name_edit_ = new QLineEdit();
    description_edit_ = new QLineEdit();

    ok_btn_ = new QPushButton("Ok");
    cancel_btn_ = new QPushButton("Cancella");

    static_cast<QFormLayout*>(layout_)->addRow(tr("&Nome"), name_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(tr("&Descrizione"), description_edit_);
    static_cast<QFormLayout*>(layout_)->addRow(getRowBtn());
}

QWidget* AbstractFormWidget::createRow(QWidget* label, QWidget* editable_field)
{
    QWidget * row = new QWidget(this);
    row->setLayout(CustomElements::getCustomLayoutPrototype(H_SINGLE_SPACING));

    label->setParent(row);
    editable_field->setParent(row);

    row->layout()->addWidget(label);
    row->layout()->addWidget(editable_field);

    return row;
}

QWidget* AbstractFormWidget::getRowBtn()
{
    QWidget * row = createRow(ok_btn_, cancel_btn_);
    row->layout()->addItem(CustomElements::getTerminalSpacer(HORIZONTAL));
    return row;
}
