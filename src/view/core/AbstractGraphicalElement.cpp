#include "AbstractGraphicalElement.h"
/**
 * @brief AbstractGraphicalElement::AbstractGraphicalElement
 * @param layout
 * @param parent
 */
AbstractGraphicalElement::AbstractGraphicalElement(QLayout* layout, QWidget* parent)
    : QWidget(parent), layout_(layout)
{
    setLayout(layout_);
}
/**
 * @brief AbstractGraphicalElement::setCustomLayout
 * @param layout
 */
void AbstractGraphicalElement::setCustomLayout(QLayout* layout)
{
    if (layout == nullptr)
        return;

    layout_ = layout;

    setLayout(layout_);
}
/**
 * @brief AbstractGraphicalElement::getLayout
 * @return the layout
 */
QLayout* AbstractGraphicalElement::getLayout() const
{
    return layout_;
}
