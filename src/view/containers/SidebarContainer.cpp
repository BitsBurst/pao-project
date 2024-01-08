#include "SidebarContainer.h"
#include "../../utility/Logger.h"

SidebarContainer::SidebarContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent) {

    setMaximumWidth(250);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_->addWidget(current_view_);
}

