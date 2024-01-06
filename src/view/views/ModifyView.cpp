#include "ModifyView.h"

ModifyView::ModifyView(QLayout* layout, QWidget* parent)
        :AbstractView(layout, parent)
{
    QLabel * label = new QLabel("Modify View");
    label->show();
    QLabel * label2 = new QLabel("Modify View");
    label->show();

    layout_->addWidget(label);
    layout_->addWidget(label2);
}