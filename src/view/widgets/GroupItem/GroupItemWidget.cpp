#include <QPushButton>
#include "GroupItemWidget.h"
#include "GroupItemRender.h"
#include "../../../utility/icons/Icons.h"

void GroupItemWidget::refresh(){
	GroupItemRender item_render(this);
	item_->accept(item_render);
}
GroupItemWidget::GroupItemWidget(AbstractItem* item, QWidget* parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), title_label_(new QLabel), detail_label_(new QLabel), item_(item)
{
    // Initialization
    modify_btn_ = new QPushButton(Icons::getIcon(Icons::IconType::EDIT), "");
    delete_btn_ = new QPushButton(Icons::getIcon(Icons::IconType::DELETE_I), "");

    QWidget * container = new QWidget(this);
    QVBoxLayout* cont_layout = new QVBoxLayout(container);
    container->setLayout(cont_layout);

    if (item_ != nullptr) {
        GroupItemRender item_render(this);
        item_->accept(item_render);
		item_->modelChangedEvent.subscribe(std::bind(&GroupItemWidget::refresh, this));
    }

    QWidget* row_btn = new QWidget(this);
    QHBoxLayout* btn_layout = new QHBoxLayout(row_btn);
    btn_layout->setContentsMargins(0, 8, 0, 0);
    row_btn->setLayout(btn_layout);

    // Layout Settings
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    cont_layout->setSpacing(0);
    cont_layout->setContentsMargins(8,8,8,8);

    title_label_->setFont(CustomElements::getFontH4());
    detail_label_->setFont(CustomElements::getFontDetails());

    // Layout Widgets
    btn_layout->addWidget(modify_btn_);
    btn_layout->addWidget(delete_btn_);

    cont_layout->addWidget(detail_label_);
    cont_layout->addWidget(title_label_);
    cont_layout->addWidget(row_btn);

    layout_->addWidget(container);
    // Events
    handleEvents();
}

void GroupItemWidget::setTitle(const QString& title)
{
    title_label_->setText(title);
}

void GroupItemWidget::setDetail(const QString& detail)
{
    detail_label_->setText(detail);
}

void GroupItemWidget::handleEvents()
{
    connect(modify_btn_, &QPushButton::released, [this] { emit changeToModifyView(item_); });
	connect(delete_btn_, &QPushButton::released, [this] { emit deleteItem(item_); });
}

void GroupItemWidget::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    emit showSingleItem(this, item_);
}
GroupItemWidget::~GroupItemWidget()
{
	if (item_ != nullptr) {
		item_->modelChangedEvent.unsubscribe(std::bind(&GroupItemWidget::refresh, this));
	}
}
AbstractItem* GroupItemWidget::getItem()
{
	return item_;
}
void GroupItemWidget::setActive(bool active)
{
	if (active) {
		detail_label_->setStyleSheet("color: red;");
		title_label_->setStyleSheet("color: red;");
	}
	else {
		detail_label_->setStyleSheet("");
		title_label_->setStyleSheet("");
	}
}

