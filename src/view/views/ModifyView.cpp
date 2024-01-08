#include "ModifyView.h"

ModifyView::ModifyView(QLayout* layout, QWidget* parent)
        :AbstractView(new QVBoxLayout, parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    label1_ = new QLabel("Modify View");
    label2_ = new QLabel("Modify View");

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
}

void ModifyView::show() {
    label1_->show();
    label2_->show();
}