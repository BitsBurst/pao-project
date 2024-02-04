#include "MainContentContainer.h"
/**
 * @brief MainContentContainer::MainContentContainer
 * @param current_view
 * @param parent
 */
MainContentContainer::MainContentContainer(QStackedWidget * current_view, QWidget* parent)
    : AbstractContainer(current_view, parent)
{
    // Layout Widgets
    layout_->addWidget(current_view_);
}