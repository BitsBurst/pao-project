#include "SettingsView.h"

SettingsView::SettingsView(QLayout* layout, QWidget* parent)
        :AbstractView(layout, parent)
{
    QLabel * label = new QLabel("Settings View");
    label->show();
    QLabel * label2 = new QLabel("Settings View");
    label->show();

    layout_->addWidget(label);
    layout_->addWidget(label2);
}