#include <QLabel>
#include "MainContentWidget.h"

MainContentWidget::MainContentWidget(QWidget* parent)
    : AbstractContainer(nullptr, parent)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);
}

void MainContentWidget::show() {
    QLabel * label = new QLabel("Main Content");
    label->show();

    layout_->addWidget(label);
}