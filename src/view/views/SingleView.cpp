#include "SingleView.h"

SingleView::SingleView(QLayout* layout, QWidget* parent)
        :AbstractView(layout, parent)
{
    QLabel * label = new QLabel("Single View");
    label->show();
    QLabel * label2 = new QLabel("Single View");
    label->show();

    layout_->addWidget(label);
    layout_->addWidget(label2);
}
