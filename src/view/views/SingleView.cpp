#include "SingleView.h"

SingleView::SingleView(QWidget* parent)
        : AbstractView(new QVBoxLayout, parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    label1_ = new QLabel("Single View");
    label2_ = new QLabel("Single View");

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
}

void SingleView::show() {
    label1_->show();
    label2_->show();
}
