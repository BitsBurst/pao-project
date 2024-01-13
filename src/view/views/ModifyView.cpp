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
    label1_ = new QLabel("Modify View" + item_->getName());
    label2_ = new QLabel("Modify View" + item_->getId());

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
}

void ModifyView::show() {
    label1_->show();
    label2_->show();
}

void ModifyView::setItem(AbstractItem* item)
{
    item_ = item;
    update();
}

void ModifyView::update()
{
    QWidget::update();

    label1_->setText("Modify View" + item_->getName());
    label2_->setText("Modify View");
}
