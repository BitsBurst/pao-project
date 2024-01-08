#include "GroupListView.h"
#include "../../utility/Logger.h"

GroupListView::GroupListView(QWidget* parent)
    : AbstractView(new QVBoxLayout, parent), scroll_area_(new QScrollArea)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    QWidget * scroll_area_list = new QWidget(scroll_area_);
    QVBoxLayout * scroll_area_layout = new QVBoxLayout(scroll_area_list);

    // TODO[Luca]: Remove data gen

    for (int i = 0; i < 10; ++i) {
        item_lists_.push_back(new GroupItemWidget("0", QString::fromStdString("Item " + std::to_string(i + 1)), "Temperatura", "", scroll_area_));
    }

    for (auto item : item_lists_) {
        scroll_area_layout->addWidget(item);
    }

    scroll_area_list->setLayout(scroll_area_layout);

    // Scroll Area
    scroll_area_->setWidget(scroll_area_list);

    layout_->addWidget(scroll_area_);
}

void GroupListView::show() {
    for (auto item : item_lists_) {
        item->show();
    }

    scroll_area_->show();
}
