#include "ModifyView.h"

ModifyView::ModifyView(AbstractItem* item, QLayout* layout, QWidget* parent)
        :AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent), item_(item)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    information_widget_ = new InformationWidget(item_);

    form_ = new SensorFormWidget(this);

    // Layout Widgets
    layout_->addWidget(information_widget_);
    layout_->addWidget(form_);
}

void ModifyView::show() {
    information_widget_->show();
    form_->show();
}

void ModifyView::setItem(AbstractItem* item)
{
    item_ = item;
    update();
}

void ModifyView::update()
{
    QWidget::update();

    information_widget_->deleteLater();
    layout_->replaceWidget(information_widget_, new InformationWidget(item_));
}
