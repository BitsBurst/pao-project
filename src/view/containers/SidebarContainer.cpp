#include "SidebarContainer.h"
#include "../../utility/Logger.h"

SidebarContainer::SidebarContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent) {

    setMaximumWidth(250);
    low_control_widget_ = new SidebarLowControlWidget(this);

    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_->addWidget(current_view_);
    layout_->addWidget(low_control_widget_);
}

