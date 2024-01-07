#ifndef SMARTSENSORS_SIDEBARLOWCONTROLWIDGET_H
#define SMARTSENSORS_SIDEBARLOWCONTROLWIDGET_H

#include <QLabel>
#include "../core/AbstractWidget.h"

class SidebarLowControlWidget : public AbstractWidget {
    Q_OBJECT
private:
    QLabel *title_label_;

public:
    explicit SidebarLowControlWidget(QWidget *parent = nullptr);
    void show();
};

#endif //SMARTSENSORS_SIDEBARLOWCONTROLWIDGET_H
