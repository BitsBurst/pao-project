#include "SidebarContainer.h"

SidebarContainer::SidebarContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent) {

    // Initialize Field
    setMaximumWidth(250);
    low_control_widget_ = new SidebarLowControlWidget(this);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);

    // Layout Settings
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    low_control_widget_->show();

    layout()->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout()->addWidget(low_control_widget_);
}

