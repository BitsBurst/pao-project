#include "AbstractView.h"
/**
 * @brief AbstractView::AbstractView
 * @param layout
 * @param parent
 */
AbstractView::AbstractView(QLayout* layout, QWidget* parent)
    : AbstractGraphicalElement(layout, parent) {

    // General Settings for views
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    layout_->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
}
/**
 * @brief AbstractView::getItem
 * @return the item
 */
AbstractItem* AbstractView::getItem() const
{
    return nullptr;
}
/**
 * @brief AbstractView::~AbstractView
 */
AbstractView::~AbstractView()
{

}
