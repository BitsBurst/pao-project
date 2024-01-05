#ifndef SMARTSENSORS_SIDEBARWIDGET_H
#define SMARTSENSORS_SIDEBARWIDGET_H

#include "AbstractContainer.h"

class SidebarWidget : public AbstractContainer {
    Q_OBJECT
private:
public:
    explicit SidebarWidget(QWidget * parent = nullptr);

    void show();
};

#endif //SMARTSENSORS_SIDEBARWIDGET_H
