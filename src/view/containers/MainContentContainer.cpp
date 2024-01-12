#include "MainContentContainer.h"

MainContentContainer::MainContentContainer(QStackedWidget * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Layout Widgets
    layout_->addWidget(current_view_);
}