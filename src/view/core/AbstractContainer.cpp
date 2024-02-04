#include "AbstractContainer.h"
#include "../../utility/logger/Logger.h"
/**
 * @brief AbstractContainer::AbstractContainer
 * @param current_view
 * @param parent
 */
AbstractContainer::AbstractContainer(QStackedWidget* current_view, QWidget* parent)
    : AbstractGraphicalElement(CustomElements::getCustomLayoutPrototype(V_CONTAINER), parent), current_view_(current_view) {

    // General settings for containers
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
/**
 * @brief AbstractContainer::getCurrentView
 * @return the current view
 */
int AbstractContainer::getCurrentView() const
{
    return current_view_->currentIndex();
}
/**
 * @brief AbstractContainer::setCurrentView
 * @param id
 */
void AbstractContainer::setCurrentView(int id)
{
    current_view_->setCurrentIndex(id);
}