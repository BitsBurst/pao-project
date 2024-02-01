#include <QPushButton>
#include "GroupItemWidget.h"
#include "GroupItemRender.h"
#include "../../../MyApp.h"

GroupItemWidget::GroupItemWidget(QString id, QString title, QString description, QString icon_src, QWidget* parent)
    : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent),  id_(std::move(id)), icon_src_(std::move(icon_src))
{
    // Initialization
    title_label_ = new QLabel(title);
    detail_label_ = new QLabel(description);

    // Layout Settings
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    title_label_->setFont(CustomElements::getFontH4());
    detail_label_->setFont(CustomElements::getFontDetails());

    // Layout Widgets
    layout_->addWidget(detail_label_);
    layout_->addWidget(title_label_);
}

GroupItemWidget::GroupItemWidget(AbstractItem* item, QWidget* parent)
        : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), title_label_(new QLabel), detail_label_(new QLabel), item_(item)
{
    // Initialization
    modify_btn_ = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_pencil), "");
    delete_btn_ = new QPushButton(CustomElements::getAwsome()->icon(fa::fa_solid, fa::fa_trash), "");

    if (item_ != nullptr) {
        GroupItemRender item_render(this);
        item_->accept(item_render);
    }

    QWidget* row_btn = new QWidget(this);
    QHBoxLayout* btn_layout = new QHBoxLayout(row_btn);
    btn_layout->setContentsMargins(0, 8, 0, 0);
    row_btn->setLayout(btn_layout);

    // Layout Settings
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout_->setSpacing(0);

    title_label_->setFont(CustomElements::getFontH4());
    detail_label_->setFont(CustomElements::getFontDetails());

    // Layout Widgets
    btn_layout->addWidget(modify_btn_);
    btn_layout->addWidget(delete_btn_);

    layout_->addWidget(detail_label_);
    layout_->addWidget(title_label_);
    layout_->addWidget(row_btn);

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
void GroupItemWidget::deleteItem(AbstractItem* p_item)
{
	LocatorController::StorageControllerInstance()->GetStorage()->removeSensor(dynamic_cast<Sensor*>(p_item));
}

