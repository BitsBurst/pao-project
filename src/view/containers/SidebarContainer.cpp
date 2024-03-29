#include "SidebarContainer.h"
#include "../../utility/logger/Logger.h"
/**
 * @brief SidebarContainer::SidebarContainer
 * @param current_view
 * @param parent
 */
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
    search_bar_ = new SearchBar(this);

    // Layout Settings
    setMaximumWidth(300);

    // Layout Widgets
    layout_->addWidget(search_bar_);
    layout_->addWidget(current_view_);
    layout_->addWidget(low_control_widget_);

    connect(low_control_widget_, &SidebarLowControlWidget::createSensor, this, &SidebarContainer::createSensor);
    connect(low_control_widget_, &SidebarLowControlWidget::createCategory, this, &SidebarContainer::createCategory);
}
/**
 * @brief SidebarContainer::getSearch
 * @details This method is used to get the search bar
 * @return the search bar
 */
SearchBar* SidebarContainer::getSearch() const
{
    return search_bar_;
}

