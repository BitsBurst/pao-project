#include "GroupItemWidget.h"

GroupItemWidget::GroupItemWidget(QString id, QString title, QString description, QString icon_src, QWidget* parent)
    : AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent),  id_(std::move(id)), icon_src_(std::move(icon_src))
{
    // Initialization
    title_label_ = new QLabel(title);
    description_label_ = new QLabel(description);

    // Layout Settings
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    title_label_->setFont(CustomElements::getFontH4());
    description_label_->setFont(CustomElements::getFontDetails());

    // Layout Widgets
    layout_->addWidget(description_label_);
    layout_->addWidget(title_label_);
}

void GroupItemWidget::show() {
    title_label_->show();
    description_label_->show();
}