#include "GroupItemWidget.h"

#include <utility>

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

    QFont description_font;
    description_font.setFamily("Roboto");
    description_font.setPixelSize(8);
    description_font.setWeight(QFont::ExtraLight);
    description_font.setLetterSpacing(QFont::AbsoluteSpacing, 1);
    description_font.setCapitalization(QFont::AllUppercase);

    title_label_->setFont(title_font);
    description_label_->setFont(description_font);

    // Layout Widgets
    layout_->addWidget(description_label_);
    layout_->addWidget(title_label_);
}

void GroupItemWidget::show() {
    title_label_->show();
    description_label_->show();
}