#include "AbstractSingleView.h"

AbstractSingleView::AbstractSingleView(AbstractItem* item, bool check_add_btn, QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    information_widget_ = new InformationWidget(item_, check_add_btn);

    layout()->addWidget(information_widget_);

    // Events
    handleEvents();
}

void AbstractSingleView::show() {
    information_widget_->show();
}

void AbstractSingleView::handleEvents()
{
    connect(information_widget_, &InformationWidget::changeToModify, this, &AbstractSingleView::emitChangeToModifyView);
}

// Slots
void AbstractSingleView::emitChangeToModifyView()
{
    emit changeToModifyView(item_);
}
