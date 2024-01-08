#include "CreateView.h"

CreateView::CreateView(QLayout* layout, QWidget* parent)
        :AbstractView(parent)
{
    layout_ = new QVBoxLayout(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );

    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    label1_ = new QLabel("Create View");
    label2_ = new QLabel("Create View");

    layout_->addWidget(label1_);
    layout_->addWidget(label2_);

    setLayout(layout_);
}

void CreateView::show() {
    label1_->show();
    label2_->show();
}