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