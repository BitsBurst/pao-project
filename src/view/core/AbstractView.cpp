#include "AbstractView.h"

AbstractView::AbstractView(QLayout* layout, QWidget* parent)
    : AbstractGraphicalElement(layout, parent) {

    // General Settings for views
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    layout_->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
}
