#include "AbstractContainer.h"

AbstractContainer::AbstractContainer(AbstractView* current_view, QWidget* parent)
    : QWidget(parent), current_view_(current_view), layout_(new QVBoxLayout(this)) {
    setLayout(layout_);
}

AbstractView* AbstractContainer::getCurrentView() const
{
    return current_view_;
}

void AbstractContainer::setCurrentView(AbstractView* current_view)
{
    current_view_ = current_view;
}
