#include "AbstractFormWidget.h"
#include "../utility/CustomElements.h"

AbstractFormWidget::AbstractFormWidget(QWidget* parent)
    : AbstractWidget( CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    name_ = new QLabel("Name");
    name_->setFont(CustomElements::getFontParagraph());
    description_ = new QLabel("Description");
    description_->setFont(CustomElements::getFontParagraph());

    name_edit_ = new QLineEdit();
    description_edit_ = new QLineEdit();

    ok_btn_ = new QPushButton("Ok");
    ok_btn_->setFont(CustomElements::getFontParagraph());

    cancel_btn_ = new QPushButton("Cancella");
    cancel_btn_->setFont(CustomElements::getFontParagraph());

    layout_->addWidget(createRow(name_, name_edit_));
    layout_->addWidget(createRow(description_, description_edit_));
}

void AbstractFormWidget::show()
{
    int items = layout_->count();
    for (int i = 0; i < items; ++i) {
        layout_->itemAt(i)->widget()->show();
    }
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
