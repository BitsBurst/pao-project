#include "SidebarLowControlWidget.h"

SidebarLowControlWidget::SidebarLowControlWidget(QWidget* parent)
    : AbstractWidget(new QVBoxLayout, parent) {

    // Initialization
    title_label_ = new QLabel("Low Settings");

    // Layout Widgets
    layout_->addWidget(title_label_);
}