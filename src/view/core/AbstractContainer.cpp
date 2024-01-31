#include "AbstractContainer.h"
#include "../../utility/logger/Logger.h"

AbstractContainer::AbstractContainer(QStackedWidget* current_view, QWidget* parent)
    : AbstractGraphicalElement(CustomElements::getCustomLayoutPrototype(V_CONTAINER), parent), current_view_(current_view) {

    // General settings for containers
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

int AbstractContainer::getCurrentView() const
{
    return current_view_->currentIndex();
}

void AbstractContainer::setCurrentView(int id)
{
    current_view_->setCurrentIndex(id);
}