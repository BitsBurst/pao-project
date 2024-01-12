#include "SidebarContainer.h"
#include "../../utility/Logger.h"

SidebarContainer::SidebarContainer(QStackedWidget * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    low_control_widget_ = new SidebarLowControlWidget(this);

    // Layout Settings
    setMaximumWidth(300);

    // Layout Widgets
    layout_->addWidget(current_view_);
    layout_->addWidget(low_control_widget_);
}

