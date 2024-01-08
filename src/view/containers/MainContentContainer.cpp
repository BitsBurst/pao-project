#include "MainContentContainer.h"

MainContentContainer::MainContentContainer(AbstractView * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_->addWidget(current_view_);
}