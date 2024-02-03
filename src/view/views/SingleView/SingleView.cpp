#include "SingleView.h"
#include "../../../controller/LocatorController.h"
#include "../../widgets/SingleWidget/SingleWidgetRender.h"

SingleView::SingleView(AbstractItem* item, bool check_add_btn, QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item)
{
    // Initialization
    information_widget_ = new InformationWidget(item_, check_add_btn);

    QWidget* stack_widget = new QWidget(this);
    single_stack_ = new QStackedLayout(this);

    sensor_widget_ = new SingleSensorWidget(item_, stack_widget);
    category_widget_ = new SingleCategoryWidget(new Category(), stack_widget);
    group_widget_ = new SingleViewGroup(item_, stack_widget);

    // Single Stack Settings
    stack_widget->setLayout(single_stack_);

    single_stack_->addWidget(sensor_widget_);
    single_stack_->addWidget(category_widget_);
    // single_stack_->addWidget(group_view_);

    if (item_ != nullptr) {
        SingleWidgetRender widget_render(this, sensor_widget_, category_widget_, information_widget_);
        item_->accept(widget_render);
    }

    // Layout Settings
    layout_->addWidget(information_widget_);
    layout_->addWidget(stack_widget);

    // Events
    handleEvents();

    if (item_ == nullptr) {
        setActiveView(0);
    }
}

void SingleView::handleEvents()
{
    connect(information_widget_, &InformationWidget::changeToModify, this, &SingleView::onChangeToModifyView);
	connect(information_widget_, &InformationWidget::deleteItem, this, &SingleView::onDeleteItem);
}

void SingleView::setActiveView(int index)
{
    single_stack_->setCurrentIndex(index);
}

void SingleView::setItem(AbstractItem* item) {
	unsubscribeEvents();

    item_ = item;

    if (item_ != nullptr) {
        SingleWidgetRender widget_render(this, sensor_widget_, category_widget_, information_widget_);
        item_->accept(widget_render);
    }

    handleEvents();
}

AbstractItem* SingleView::getItem() const
{
    return item_;
}


void SingleView::onChangeToModifyView()
{
	emit changeToModifyView(item_);
}

void SingleView::onDeleteItem()
{
	emit deleteItem(item_);
}

void SingleView::unsubscribeEvents() {
	disconnect(information_widget_, &InformationWidget::changeToModify, this, &SingleView::onChangeToModifyView);
	disconnect(information_widget_, &InformationWidget::deleteItem, this, &SingleView::onDeleteItem);
}
