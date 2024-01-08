#include "AbstractContainer.h"
#include "../../utility/Logger.h"

AbstractContainer::AbstractContainer(AbstractView* current_view, QWidget* parent)
    : QWidget(parent), current_view_(current_view), layout_(new QVBoxLayout(this)) {

    layout_->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    setLayout(layout_);

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding );
}

AbstractView* AbstractContainer::getCurrentView() const
{
    return current_view_;
}

void AbstractContainer::setCurrentView(AbstractView* current_view)
{
    hide();

    current_view_ = current_view;

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