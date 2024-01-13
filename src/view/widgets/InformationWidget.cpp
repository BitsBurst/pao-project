#include "InformationWidget.h"
#include "../utility/CustomElements.h"

InformationWidget::InformationWidget(const AbstractItem& item, bool check_add_btn, QWidget* parent)
    :AbstractWidget(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), add_btn_(nullptr)
{
    // Initialization
    title_ = new QLabel(item.getName());
    title_->setFont(CustomElements::getFontH2());
    description_ = new QLabel("Una descrizione per il sensore, la categoria o il gruppo");
    description_->setFont(CustomElements::getFontParagraph());

    group_buttons_ = new QWidget(this);
    modify_btn_ = new QPushButton("Modifica", group_buttons_);
    delete_btn_ = new QPushButton("Elimina", group_buttons_);
    if (check_add_btn)
        add_btn_ = new QPushButton("Aggiungi", group_buttons_);

    // Layout settings
    group_buttons_->setLayout(CustomElements::getHorizontalLayout(0));
    group_buttons_->layout()->setSpacing(8);

    // Layout Widget
    group_buttons_->layout()->addWidget(modify_btn_);
    group_buttons_->layout()->addWidget(delete_btn_);
    if (add_btn_ !=nullptr)
        group_buttons_->layout()->addWidget(add_btn_);
    group_buttons_->layout()->addItem(CustomElements::getTerminalSpacer(HORIZONTAL));

    layout_->addWidget(title_);
    layout_->addWidget(description_);
    layout_->addWidget(group_buttons_);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
}

void InformationWidget::show() {
    title_->show();
    description_->show();
    group_buttons_->show();
}