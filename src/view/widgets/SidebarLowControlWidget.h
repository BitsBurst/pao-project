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
};

#endif //SMARTSENSORS_SIDEBARLOWCONTROLWIDGET_H
