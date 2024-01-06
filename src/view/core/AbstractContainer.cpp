#include "AbstractContainer.h"

AbstractContainer::AbstractContainer(AbstractView* current_view, QWidget* parent)
    : QWidget(parent), current_view_(current_view), layout_(new QVBoxLayout(this)) {
    setLayout(layout_);

    if (current_view_ !=nullptr)
        current_view_->setParent(this);
}

AbstractView* AbstractContainer::getCurrentView() const
{
    return current_view_;
}

void AbstractContainer::setCurrentView(AbstractView* current_view)
{
    hide();

    current_view_ = current_view;

    if (current_view_ !=nullptr)
        current_view_->setParent(this);

    show();
}

void AbstractContainer::show() {
    if (current_view_ !=nullptr)
        current_view_->toggle();
}
void AbstractContainer::update() {
    if (current_view_ !=nullptr)
        current_view_->toggle();
}
void AbstractContainer::hide() {
    if (current_view_ !=nullptr)
        current_view_->hide();
}