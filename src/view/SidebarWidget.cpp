#include <QLabel>
#include "SidebarWidget.h"

SidebarWidget::SidebarWidget(QWidget* parent)
    : AbstractContainer(nullptr, parent) {
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
}

void SidebarWidget::show() {
    QLabel * label = new QLabel("Sidebar");
    label->show();

    layout_->addWidget(label);
}

