#include "GroupListView.h"

GroupListView::GroupListView(QLayout * layout, QWidget* parent)
    : AbstractView(layout, parent) {

    item_ = new GroupItemWidget("1", "Titolo Esempio", "Temperatura", "", this);
    item_->show();

    auto item_2 = new GroupItemWidget("1", "Titolo Esempio 2", "Movimento", "", this);
    item_2->show();

    layout_->addWidget(item_);
    layout_->addWidget(item_2);
    layout_->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
}