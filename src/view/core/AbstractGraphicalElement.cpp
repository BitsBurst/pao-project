#include "AbstractGraphicalElement.h"

AbstractGraphicalElement::AbstractGraphicalElement(QLayout* layout, QWidget* parent)
    : QWidget(parent), layout_(layout)
{
    setLayout(layout_);
}

void AbstractGraphicalElement::setCustomLayout(QLayout* layout)
{
    if (layout == nullptr)
        return;

    if (layout != layout_) {
        delete layout_;
        layout_ = layout;
    }

    setLayout(layout_);
}

QLayout* AbstractGraphicalElement::getLayout() const
{
    return layout_;
}
