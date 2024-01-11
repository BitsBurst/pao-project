#include "AbstractSingleView.h"

AbstractSingleView::AbstractSingleView(QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    title_ = new QLabel("Sensore");
    title_->setFont(CustomElements::getFontH2());
    description_ = new QLabel("Una descrizione per il sensore, la categoria o il gruppo");
    description_->setFont(CustomElements::getFontParagraph());

    QWidget * info_widget_ = new QWidget(this);

    group_buttons_ = new QWidget(this);
    modify_btn_ = new QPushButton("Modifica", group_buttons_);
    delete_btn_ = new QPushButton("Elimina", group_buttons_);

    button_list_.push_back(modify_btn_);
    button_list_.push_back(delete_btn_);

    info_widget_->setLayout(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING));

    group_buttons_->setLayout(CustomElements::getHorizontalLayout(0));
    group_buttons_->layout()->setSpacing(8);

    for (auto item : button_list_) {
        group_buttons_->layout()->addWidget(item);
    }

    group_buttons_->layout()->addItem(CustomElements::getTerminalSpacer(HORIZONTAL));

    // Layout Widgets
    info_widget_->layout()->addWidget(title_);
    info_widget_->layout()->addWidget(description_);
    info_widget_->layout()->addWidget(group_buttons_);

    layout()->addWidget(info_widget_);
}

void AbstractSingleView::show() {
    title_->show();
    description_->show();
    group_buttons_->show();
}
