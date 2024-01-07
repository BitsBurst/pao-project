#include "GroupItemWidget.h"

// TODO[Luca]: Rivedere utilizzo ereditarietà per i layout
GroupItemWidget::GroupItemWidget(QString id, QString title, QString description, QString icon_src, QWidget* parent)
    :AbstractWidget(nullptr, parent),  id_(id), icon_src_(icon_src) {

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(16, 16, 16, 0);
    layout->setSpacing(4);

    setCustomLayout(layout);

    // Initialize Elements
    title_label_ = new QLabel(title);
    description_label_ = new QLabel(description);

    // Layout
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

    layout_->addWidget(description_label_);
    layout_->addWidget(title_label_);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}

void GroupItemWidget::show() {
    title_label_->show();
    description_label_->show();
}