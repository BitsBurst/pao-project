#include "CreateView.h"

CreateView::CreateView(QLayout* layout, QWidget* parent)
        :AbstractView(layout, parent)
{
    QLabel * label = new QLabel("Create View");
    label->show();
    QLabel * label2 = new QLabel("Create View");
    label->show();

    layout_->addWidget(label);
    layout_->addWidget(label2);
}