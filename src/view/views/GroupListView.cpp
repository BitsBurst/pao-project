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
    scroll_area_list = new QWidget(scroll_area_);
    scroll_area_layout = new QVBoxLayout(scroll_area_list);
    scroll_area_layout->setSpacing(16);

    if (items.empty()) {
        scroll_area_layout->addWidget(new QLabel("Nessun Elemento"));
    } else {

        for (auto item : items) {
            item_lists_.push_back(new GroupItemWidget(item, scroll_area_list));
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
        connect(element, &GroupItemWidget::changeToModifyView, this, &GroupListView::changeToModifyView);
        connect(element, &GroupItemWidget::deleteItem, this, &GroupListView::deleteItem);
        connect(element, &GroupItemWidget::showSingleItem, this, &GroupListView::showSingleItem);
    }
}

void GroupListView::setItems(const QVector<AbstractItem*>& items)
{
    scroll_area_layout->deleteLater();
    scroll_area_list->deleteLater();

	for (auto item : item_lists_) {
		delete item;
	}

	item_lists_.clear();


    scroll_area_list = new QWidget(scroll_area_);
    scroll_area_layout = new QVBoxLayout(scroll_area_list);
    scroll_area_layout->setSpacing(16);

    if (items.empty()) {
        scroll_area_layout->addWidget(new QLabel("Nessun Elemento"));
    } else {

        for (auto item : items) {
            item_lists_.push_back(new GroupItemWidget(item, scroll_area_list));
        }

        for (auto item : item_lists_) {
            scroll_area_layout->addWidget(item);
        }
    }

    scroll_area_list->setLayout(scroll_area_layout);

    // Scroll Area
    scroll_area_->setWidget(scroll_area_list);

    handleEvents();
}

void GroupListView::deleteListItem(GroupItemWidget* item)
{
    if (item == nullptr) return;

	scroll_area_layout->removeWidget(item);
	item_lists_.erase(std::remove(item_lists_.begin(), item_lists_.end(), item), item_lists_.end());
	delete item;

    scroll_area_layout->addStretch();
}

GroupItemWidget * GroupListView::getGroupItem(AbstractItem * item)
{
    for (auto graphical_item : item_lists_) {
        if (graphical_item->getItem() == item)
            return graphical_item;
    }

    return nullptr;
}

QVector<AbstractItem*>& GroupListView::getItems()
{
    return items_;
}

GroupListView::~GroupListView()
{
    for (auto item : item_lists_) {
        delete item;
    }
}
