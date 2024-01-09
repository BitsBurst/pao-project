#include "GroupItemWidget.h"

GroupItemWidget::GroupItemWidget(QString id, QString title, QString description, QString icon_src, QWidget* parent)
    : AbstractWidget(new QVBoxLayout, parent),  id_(std::move(id)), icon_src_(std::move(icon_src))
{
    // Initialization
    title_label_ = new QLabel(title);
    description_label_ = new QLabel(description);

    // Layout Settings
    layout_->setContentsMargins(16, 16, 16, 0);
    layout_->setSpacing(4);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Fonts
    QFont title_font;
    title_font.setFamily("Roboto");
    title_font.setPixelSize(18);
    title_font.setWeight(QFont::Medium);

    title_label_->setFont(*CustomElements::getFontH4());
    description_label_->setFont(*CustomElements::getFontDetails());

    // Layout Widgets
    layout_->addWidget(description_label_);
    layout_->addWidget(title_label_);
}

void GroupItemWidget::show() {
    title_label_->show();
    description_label_->show();
}