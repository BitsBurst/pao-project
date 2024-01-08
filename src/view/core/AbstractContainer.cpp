#include "AbstractContainer.h"
#include "../../utility/Logger.h"

AbstractContainer::AbstractContainer(AbstractView* current_view, QWidget* parent)
    : AbstractGraphicalElement(new QVBoxLayout, parent), current_view_(current_view) {

    // General settings for containers
    layout_->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

AbstractView* AbstractContainer::getCurrentView() const
{
    return current_view_;
}

void AbstractContainer::setCurrentView(AbstractView* current_view)
{

    // TODO[Luca]: Review this function logic!
    hide();

    if (current_view_ !=nullptr) {
        layout_->removeWidget(current_view_);
        current_view_ = current_view;
        current_view_->setParent(this);
        layout_->addWidget(current_view_);
    }

    show();
}

void AbstractContainer::show() {
    if (current_view_ !=nullptr)
        current_view_->show();
}
void AbstractContainer::update() {
    if (current_view_ !=nullptr)
        current_view_->toggle();
}
void AbstractContainer::hide() {
    if (current_view_ !=nullptr)
        current_view_->hide();
}