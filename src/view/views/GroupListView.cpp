#include "GroupListView.h"
#include "../../utility/logger/Logger.h"

GroupListView::GroupListView(const QVector<AbstractItem*>& items, QWidget* parent)
    : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), scroll_area_(new QScrollArea)
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
    scroll_area_layout->setSpacing(16);

    if (items.empty()) {
        scroll_area_layout->addWidget(new QLabel("Nessun Elemento"));
    } else {

        for (auto item : items) {
            item_lists_.push_back(new GroupItemWidget(item, scroll_area_));
        }

        for (auto item : item_lists_) {
            scroll_area_layout->addWidget(item);
        }
    }

    scroll_area_list->setLayout(scroll_area_layout);

    // Scroll Area
    scroll_area_->setWidget(scroll_area_list);

    layout_->addWidget(scroll_area_);

    // Events
    handleEvents();
}

void GroupListView::handleEvents()
{
    for (auto element : item_lists_) {
        connect(element, &GroupItemWidget::changeToModifyView, this, &::GroupListView::changeToModifyView);
    }
}
