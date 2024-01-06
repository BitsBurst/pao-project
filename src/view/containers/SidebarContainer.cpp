#include "SidebarContainer.h"

SidebarContainer::SidebarContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent) {

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
}

