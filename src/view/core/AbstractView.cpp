#include "AbstractView.h"

AbstractView::AbstractView(QLayout * layout, QWidget *parent)
    : QWidget(parent), layout_(layout) {
    if (layout_ ==nullptr)
        layout_ = new QVBoxLayout();

    layout_->setParent(this);
    setLayout(layout_);
}

void AbstractView::toggle() {
    setVisible(!isVisible());
}

void AbstractView::setCustomLayout(QLayout* layout)
{
    if (layout != nullptr) {
        delete layout_;
        layout_ = layout;
        layout_->setParent(this);
    }

    setLayout(layout_);
}
