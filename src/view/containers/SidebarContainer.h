#ifndef SMARTSENSORS_SIDEBARCONTAINER_H
#define SMARTSENSORS_SIDEBARCONTAINER_H

#include <QLabel>
#include "../core/AbstractContainer.h"
#include "../widgets/SidebarLowControlWidget.h"

class SidebarContainer : public AbstractContainer {
    Q_OBJECT
private:
    SidebarLowControlWidget * low_control_widget_;
public:
    explicit SidebarContainer(QStackedWidget * current_view = new QStackedWidget,QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_SIDEBARCONTAINER_H
