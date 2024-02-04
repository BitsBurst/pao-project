#include "AbstractWidget.h"
/**
 * @brief AbstractWidget::AbstractWidget
 * @param layout
 * @param parent
 */
AbstractWidget::AbstractWidget(QLayout* layout, QWidget* parent)
    :AbstractGraphicalElement(layout, parent) {}
AbstractWidget::~AbstractWidget() {

}