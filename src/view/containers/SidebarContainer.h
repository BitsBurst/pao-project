#ifndef SMARTSENSORS_SIDEBARCONTAINER_H
#define SMARTSENSORS_SIDEBARCONTAINER_H

#include <QLabel>
#include "../core/AbstractContainer.h"

class SidebarContainer : public AbstractContainer {
    Q_OBJECT
private:
public:
    explicit SidebarContainer(AbstractView * current_view = nullptr,QWidget * parent = nullptr);
};

#endif //SMARTSENSORS_SIDEBARCONTAINER_H
