#include "AbstractView.h"

AbstractView::AbstractView(QWidget *parent)
    : QWidget(parent), layout_(nullptr) {}

    AbstractView::AbstractView(QLayout* layout, QWidget* parent) {}

void AbstractView::toggle() {
    setVisible(!isVisible());
}

void AbstractView::show() {
    setVisible(true);
}

void AbstractView::setCustomLayout(QLayout* layout)
{
    if (layout != nullptr) {
        delete layout_;
        layout_ = layout;
    }

    setLayout(layout_);
}
