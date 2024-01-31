#include "SettingsView.h"

SettingsView::SettingsView(QWidget* parent)
        : AbstractView(CustomElements::getCustomLayoutPrototype(SINGLE_SPACING), parent)
{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    */

    // Initialization
    label1_ = new QLabel("Settings View");
    label2_ = new QLabel("Settings View");

    // Layout Widgets
    layout_->addWidget(label1_);
    layout_->addWidget(label2_);
}