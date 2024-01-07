#include "SidebarLowControlWidget.h"

SidebarLowControlWidget::SidebarLowControlWidget(QWidget* parent)
    : AbstractWidget(new QVBoxLayout(), parent) {

    // Initialize Field
    title_label_ = new QLabel("Low Settings");

    // Layout Settings
    layout_->addWidget(title_label_);
}

void SidebarLowControlWidget::show() {
    title_label_->show();
}