#include "MainContentContainer.h"

MainContentContainer::MainContentContainer(QStackedWidget * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    // Layout Widgets
    layout_->addWidget(current_view_);
}