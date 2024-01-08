#include "AbstractView.h"

AbstractView::AbstractView(QLayout* layout, QWidget* parent)
    : AbstractGraphicalElement(layout, parent) {

    // General Settings for views
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
}

// TODO[Luca]: Review function logic!
void AbstractView::toggle() {
    setVisible(!isVisible());
}
void AbstractView::show() {
    setVisible(true);
}
