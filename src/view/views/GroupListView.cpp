#include "GroupListView.h"
#include "../../utility/Logger.h"

GroupListView::GroupListView(QWidget* parent)
    : AbstractView(parent) {

    layout_ = new QVBoxLayout(this);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);

    label1_ = new QLabel("Single View");
    label2_ = new QLabel("Single View");

    layout_->addWidget(label1_);
    layout_->addWidget(label2_);

    setLayout(layout_);
}

void GroupListView::show() {
    label1_->show();
    label2_->show();
}
