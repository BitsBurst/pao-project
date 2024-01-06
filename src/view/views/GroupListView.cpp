#include "GroupListView.h"

GroupListView::GroupListView(QLayout * layout, QWidget* parent)
    : AbstractView(layout, parent) {
    QLabel * label = new QLabel("Sidebar Label");
    label->show();

    layout_->addWidget(label);
}