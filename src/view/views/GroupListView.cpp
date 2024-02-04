#include "GroupListView.h"
#include "../../utility/logger/Logger.h"
/**
 * @brief GroupListView::GroupListView is the constructor of the class.
 * @param items is a vector of AbstractItem pointers.
 * @param parent is the parent widget of the view.
 */
GroupListView::GroupListView(const QVector<AbstractItem*>& items, QWidget* parent)
    : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), scroll_area_(new QScrollArea), current_selected_(nullptr)
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
    scroll_area_layout->setContentsMargins(0,0,0,0);
    scroll_area_list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

    scroll_area_layout->addStretch();

    scroll_area_list->setLayout(scroll_area_layout);

    // Scroll Area
    scroll_area_->setWidget(scroll_area_list);
    scroll_area_->setWidgetResizable(true);

    layout_->addWidget(scroll_area_);

    // Events
    handleEvents();
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::handleEvents()
{
    for (auto element : item_lists_) {
		unsubscribeToGroupItemsEvents(element);
		subscribeToGroupItemsEvents(element);
    }
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::setItems(const QVector<AbstractItem*>& items)
{
    scroll_area_layout->deleteLater();
    scroll_area_list->deleteLater();
    resetCurrentItem();

	for (auto item : item_lists_) {
		delete item;
	}

	item_lists_.clear();

    scroll_area_list = new QWidget(scroll_area_);
    scroll_area_layout = new QVBoxLayout(scroll_area_list);
    scroll_area_layout->setContentsMargins(0,0,0,0);
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
    scroll_area_layout->addStretch();
    scroll_area_list->setLayout(scroll_area_layout);

    // Scroll Area
    scroll_area_->setWidget(scroll_area_list);

    handleEvents();
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::deleteListItem(GroupItemWidget* item)
{
    if (item == nullptr) return;
	if(current_selected_ == item)
		current_selected_ = nullptr;
	scroll_area_layout->removeWidget(item);
	item_lists_.erase(std::remove(item_lists_.begin(), item_lists_.end(), item), item_lists_.end());
	delete item;
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
GroupItemWidget * GroupListView::getGroupItem(AbstractItem * item)
{
    for (auto graphical_item : item_lists_) {
        if (graphical_item->getItem() == item)
            return graphical_item;
    }

    return nullptr;
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
QVector<AbstractItem*>& GroupListView::getItems()
{
    return items_;
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
GroupListView::~GroupListView()
{
	resetCurrentItem();
	for (auto element : item_lists_) {
		unsubscribeToGroupItemsEvents(element);
	}
	for (auto item : item_lists_) {
        delete item;
    }
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::handleShowSingleItem(GroupItemWidget* graphical_item, AbstractItem* item) {
    emit showSingleItem(item);

    if (current_selected_ != nullptr) {
        current_selected_->setActive(false);
    }

    current_selected_ = graphical_item;
	current_selected_->setActive(true);
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::resetCurrentItem()
{
    current_selected_ = nullptr;
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::subscribeToGroupItemsEvents(GroupItemWidget * element)
{
	connect(element, &GroupItemWidget::changeToModifyView, this, &GroupListView::changeToModifyView);
	connect(element, &GroupItemWidget::deleteItem, this, &GroupListView::deleteItem);
	connect(element, &GroupItemWidget::showSingleItem, this, &GroupListView::handleShowSingleItem);
}
/**
 * @brief GroupListView::changeToModifyView is a slot that is used to change the view to the modify view.
 * @param item is a pointer to an AbstractItem.
 */
void GroupListView::unsubscribeToGroupItemsEvents(GroupItemWidget * element)
{
	disconnect(element, &GroupItemWidget::changeToModifyView, this, &GroupListView::changeToModifyView);
	disconnect(element, &GroupItemWidget::deleteItem, this, &GroupListView::deleteItem);
	disconnect(element, &GroupItemWidget::showSingleItem, this, &GroupListView::handleShowSingleItem);
}
